<template>
  <q-page class="q-pa-sm">
    <q-card-section>
      <div class="q-pl-sm q-mt-none text-weight-medium text-h5">Devices</div>
    </q-card-section>
    <q-card class="q-pa-sm bg-grey-1">
      <q-card class="q-pa-sm">
        <q-card-section class="q-pa-none" horizontal>
          <div class="bg-blue-10 q-pa-none text-white text-center" style="width: 35% !important">
            <div class="text-subtitle2">*{{ connectedDeviceName || 'No Decive' }}*</div>
            <div>Connected</div>
          </div>
          <q-btn
            color="white"
            class="text-black"
            style="width: 30% !important"
            label="Disconnect"
          />
          <q-btn style="width: 30% !important" label="Scan" />
        </q-card-section>
      </q-card>
      <q-separator />
      <q-btn
        :loading="isScanning"
        label="SCAN"
        color="primary"
        class="q-ml-none"
        :disable="isScanning || isConnected"
        @click="scanForDevices"
      >
        <template v-slot:loading>
          <q-spinner-facebook />
        </template>
      </q-btn>
      <q-btn
        v-if="isConnected"
        label="Disconnect"
        color="negative"
        class="q-ml-md"
        :disable="!isConnected"
        @click="disconnectDevice"
      />

      <div v-if="isScanning" class="text-grey q-mt-md">Scanning for devices...</div>
      <div v-if="isConnected" class="q-mt-md text-positive">
        <strong>Connected to: </strong>{{ connectedDeviceName || 'Unknown Device' }}
      </div>
      <q-list v-if="(devices.length > 0 || isScanning) && !isConnected">
        <q-item
          v-for="(device, index) in devices"
          :key="index"
          clickable
          @click="connectToDevice(device)"
        >
          <q-item-section>
            <div class="text-h6">{{ device.displayName }}</div>
            <q-item>
              <q-item-section class="text-grey"> ID: {{ device.displayId }} </q-item-section>
              <q-item-section side class="text-grey">
                RSSI: {{ device.displayRssi || 'N/A' }}
              </q-item-section>
            </q-item>
          </q-item-section>
        </q-item>
      </q-list>
      <div v-else-if="!isConnected" class="text-grey">
        No devices found. Please scan for devices.
      </div>

      <q-separator />

      <q-card-section>
        <q-input
          v-model="messageToSend"
          label="Message to Send"
          hint="Enter the message you want to send to the device"
          outlined
        />
        <q-btn
          label="Send Message"
          color="primary"
          class="q-mt-md"
          :disable="!isConnected || !messageToSend"
          @click="sendMessage"
        />
      </q-card-section>

      <q-separator />

      <q-card-section>
        <div class="text-h6">Received Data</div>
        <div v-if="receivedData.length === 0" class="text-grey q-mt-md">No data received yet.</div>
        <q-list v-else>
          <q-item v-for="(data, index) in receivedData" :key="index">
            <q-item-section>
              {{ data }}
            </q-item-section>
          </q-item>
        </q-list>
      </q-card-section>
    </q-card>
  </q-page>
</template>

<script>
import { BleClient, numbersToDataView, dataViewToNumbers } from '@capacitor-community/bluetooth-le'
import { defineComponent, ref } from 'vue'

export default defineComponent({
  name: 'BluetoothDebugAssistant',
  setup() {
    const messageToSend = ref('')
    const receivedData = ref([])
    const isConnected = ref(false)
    const connectedDeviceName = ref(null)
    const connectedDeviceId = ref(null)
    const devices = ref([]) // List of scanned devices
    const isScanning = ref(false) // Scanning status
    const SCAN_DURATION = ref(5000) // Duration of the scan in milliseconds
    const CHARACTERISTIC_UUID_Notify = '0000FFF1-0000-1000-8000-00805F9B34FB'
    const CHARACTERISTIC_UUID_Write = '0000FFF2-0000-1000-8000-00805F9B34FB'
    const SERVICE_UUID_Notify = '0000FFF0-0000-1000-8000-00805F9B34FB'
    const SERVICE_UUID_Write = '0000FFF0-0000-1000-8000-00805F9B34FB'

    function onDisconnect() {
      console.log('Device disconnected')
      connectedDeviceId.value = null
      connectedDeviceName.value = null
      isConnected.value = false
    }

    async function scanForDevices() {
      try {
        devices.value = [] // 清空设备列表
        await BleClient.initialize()
        isScanning.value = true

        await BleClient.requestLEScan({}, (device) => {
          if (device.device.name != null) {
            const existingDevice = devices.value.find((d) => d.displayId === device.device.deviceId)
            if (!existingDevice) {
              devices.value.push({
                displayName: device.device.name,
                displayId: device.device.deviceId,
                displayRssi: device.rssi,
              })
            }
          }
        })

        // 停止扫描
        setTimeout(async () => {
          await BleClient.stopLEScan()
          isScanning.value = false
        }, SCAN_DURATION.value)
      } catch (error) {
        console.error('Error scanning for devices:', error)
        isScanning.value = false
        await BleClient.stopLEScan() // 确保扫描被正确停止
      }
    }

    async function connectToDevice(device) {
      try {
        await BleClient.connect(device.displayId, () => onDisconnect())
        connectedDeviceId.value = device.displayId
        connectedDeviceName.value = device.displayName || 'Unknown Device'
        // CHARACTERISTIC_UUID.value = device.uuids
        isConnected.value = true
        console.log('Connected to device:', device)
        await startNotifications()
      } catch (error) {
        console.error('Error connecting to device:', error)
      }
    }

    async function startNotifications() {
      await BleClient.startNotifications(
        connectedDeviceId.value,
        SERVICE_UUID_Notify,
        CHARACTERISTIC_UUID_Notify,
        (value) => {
          const receivedNumbers = dataViewToNumbers(value)
          receivedData.value.push(receivedNumbers)
          console.log('Received data:', receivedNumbers)
        },
      )
    }

    async function sendMessage() {
      if (!connectedDeviceId.value || !messageToSend.value) {
        console.warn('No device connected or message is empty')
        return
      }
      try {
        const data = numbersToDataView(Array.from(messageToSend.value, (c) => c.charCodeAt(0)))
        await BleClient.writeWithoutResponse(
          connectedDeviceId.value,
          SERVICE_UUID_Write,
          CHARACTERISTIC_UUID_Write,
          data,
        )
        console.log('Message sent:', messageToSend.value)
      } catch (error) {
        console.error('Error sending message:', error)
      }
    }

    function disconnectDevice() {
      if (!connectedDeviceId.value) return

      try {
        BleClient.disconnect(connectedDeviceId.value)
        onDisconnect()
        console.log('Device disconnected successfully')
      } catch (error) {
        console.error('Error disconnecting device:', error)
      }
    }

    return {
      messageToSend,
      receivedData,
      isConnected,
      connectedDeviceName,
      devices,
      isScanning,
      scanForDevices,
      connectToDevice,
      sendMessage,
      disconnectDevice,
    }
  },
})
</script>
