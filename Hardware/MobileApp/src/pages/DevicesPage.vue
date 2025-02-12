<template>
  <q-page class="bg-grey-3">
    <q-card-section class="q-pb-none q-pt-none">
      <div class="q-pl-sm q-mt-none text-weight-medium text-h5">Devices</div>
    </q-card-section>
    <q-card class="q-ma-sm bg-grey-2" style="height: 75.8vh; border-radius: 1em">
      <q-card-section class="q-pa-sm q-pb-sm bg-grey-2" style="border-radius: 1em">
        <!-- 设备连接卡片 -->
        <div class="q-pl-md text-h6 text-blck">Connections</div>
        <q-card class="bg-white q-pt-sm q-pb-sm" style="border-radius: 1em">
          <q-card-section class="q-pl-xs row no-wrap">
            <div class="q-ma-none bg-white text-center" style="width: 40%">
              <div class="q-pa-none text-blck">
                *{{ BLEConfig.connectedDeviceName || 'No Decive' }}*
              </div>
              <div class="q-pa-none text-blck">Connected</div>
            </div>
            <q-btn
              :disable="!BLEConfig.isConnected"
              :loading="BLEConfig.isConnecting"
              class="text-caption text-weight-medium text-capitalize"
              color="red-6"
              label="Disconnect"
              size="14px"
              style="width: 90px; height: 40px"
              @click="disconnectDevice"
            >
              <template v-slot:loading>
                <q-spinner-facebook />
              </template>
            </q-btn>
            <q-btn
              :disable="BLEConfig.isConnected"
              dense
              v-morph:btn:mygroup:300.resize="morphGroupModel"
              label="SCAN"
              icon-right="arrow_drop_down"
              color="black"
              size="12px"
              style="
                width: 90px;
                height: 40px;
                position: absolute;
                right: 0;
                margin-right: 1em;
                border-radius: 1em;
              "
              class="text-caption text-weight-medium q-ml-sm"
              @click="scanForDevices"
            >
            </q-btn>
            <q-card
              v-morph:card1:mygroup:500.resize="morphGroupModel"
              class="q-pa-none q-ma-none bg-blue-2"
              style="
                border-radius: 1em;
                width: 90%;
                min-height: 40px;
                max-height: 650%;
                position: absolute;
                right: 1em;
                z-index: 10;
              "
            >
              <q-card-section class="q-pa-none q-ma-none text-black">
                <q-btn
                  :loading="BLEConfig.isScanning"
                  dense
                  flat
                  icon="arrow_drop_up"
                  color="black"
                  size="18px"
                  style="width: 100%; height: 40px; border-radius: 1em"
                  @click="nextMorph()"
                >
                  <template v-slot:loading>
                    <q-spinner-rings />
                  </template>
                </q-btn>
                <q-list
                  v-if="
                    (BLEConfig.devices.length > 0 || BLEConfig.isScanning) && !BLEConfig.isConnected
                  "
                  class="q-pl-md"
                >
                  <q-separator color="q-pa-none black" />
                  <q-item
                    v-for="(device, index) in BLEConfig.devices"
                    :key="index"
                    clickable
                    @click="connectToDevice(device)"
                    class="q-pb-sm q-pa-none"
                  >
                    <q-item-section class="q-pa-none">
                      <div class="text-subtitle2 q-pa-none">
                        {{ device.displayName }}
                      </div>
                      <div style="position: absolute; right: 0; margin-right: 1em">
                        RSSI: {{ device.displayRssi || 'N/A' }}
                      </div>
                    </q-item-section>
                  </q-item>
                </q-list>
                <div v-else-if="!BLEConfig.isConnected" class="q-pl-md text-black">
                  No devices found. Please try again.
                </div>
              </q-card-section>
            </q-card>
          </q-card-section>
        </q-card>

        <q-separator color="grey-2" style="height: 1vh" />

        <!-- 设置通道卡片 -->
        <q-card class="q-pb-none bg-grey-2" style="height: 54.6vh" flat>
          <div class="text-weight-medium text-h6 q-ml-md q-pa-none text-black">Setup Channels</div>
          <q-card-section
            class="q-pa-xs q-mb-none bg-grey-2"
            style="height: 46vh; overflow-y: auto"
          >
            <!-- 渲染每个通道卡片 -->
            <q-card
              flat
              v-for="(card, index) in cards"
              :key="index"
              :class="['card q-mb-xs', { expanded: expandedCard === card.id }]"
              :ref="(el) => (cardRefs[index] = el)"
              :style="{
                backgroundColor: card.color,
                ...cardStyle,
                ...(expandedCard === card.id ? expandedCardStyle : {}),
              }"
            >
              <q-card-section class="q-pt-md q-ma-none" style="width: 100%">
                <!-- 展开按钮 -->
                <q-btn
                  v-if="!(expandedCard === card.id) && toggleOn[index]"
                  icon="expand_more"
                  size="20px"
                  flat
                  @click.stop="zoomCard(index, 1)"
                  style="position: absolute; left: 40%; top: 0"
                />
                <!-- 收起按钮 -->
                <q-btn
                  v-if="expandedCard === card.id"
                  icon="expand_less"
                  size="20px"
                  flat
                  @click.stop="zoomCard(index)"
                  style="position: absolute; left: 40%; top: 0"
                />
                <!-- 开关按钮 -->
                <q-toggle
                  :disable="!BLEConfig.isConnected"
                  v-model="toggleOn[index]"
                  class="q-ma-xs"
                  style="position: absolute; right: 0; top: 0"
                  size="md"
                  @click.stop="(zoomCard(index), (BLEConfig.setupSucceed = false))"
                />
                <!-- 通道名称 -->
                <div
                  class="q-pl-md q-ma-none text-weight-regular text"
                  style="position: absolute; left: 0"
                >
                  Channel{{ index + 1 }}
                </div>
              </q-card-section>
              <SetupChn v-model="DevicesChnState[index]" v-show="expandedCard === card.id" />
            </q-card>
          </q-card-section>
          <!-- SETUP 按钮 -->
          <q-btn
            :loading="BLEConfig.isSetuping"
            :disable="!BLEConfig.isConnected"
            class="q-mt-xs q-ml-lg"
            color="white"
            text-color="black"
            style="width: 39%; border-radius: 1em"
            @click="paramSetup"
          >
            <div v-if="!BLEConfig.setupSucceed">SETUP</div>
            <q-icon v-if="BLEConfig.setupSucceed" name="done" />
            <template v-slot:loading>
              <q-spinner-gears />
            </template>
          </q-btn>
          <!-- START 按钮 -->
          <q-btn
            :disable="!BLEConfig.setupSucceed"
            class="q-mt-xs q-ml-lg"
            color="green-6"
            text-color="white"
            style="width: 39%; border-radius: 1em"
            @click="start"
          >
            >START</q-btn
          >
        </q-card>
      </q-card-section>
    </q-card>
    <!-- 输入框用于修改子组件中的数据 -->
    <!-- {{ DevicesChnState }} -->
    <!-- <input v-model="DevicesChnState" placeholder="修改子组件数据" /> -->
  </q-page>
</template>
<script setup>
import { ref, onBeforeUpdate, nextTick, watch, computed } from 'vue'
import { morph } from 'quasar'
import { BleClient } from '@capacitor-community/bluetooth-le'
// import { numbersToDataView , dataViewToNumbers} from '@capacitor-community/bluetooth-le'
import SetupChn from '../components/SetupChn.vue'
import { defineProps, defineEmits } from 'vue'
// import { toRaw } from 'vue'

// 接收父组件传递的 DevicesChnState
const props = defineProps({
  modelValue: Object,
})
const DevicesChnState = ref(props.modelValue)

// 触发事件更新父组件的值
const emit = defineEmits(['update:modelValue'])

const nextMorphStep = {
  btn: 'card1',
  card1: 'btn',
}

//蓝牙连接相关参数
const BLEConfig = ref({
  // 蓝牙连接相关参数
  messageToSend: new Array(32).fill(0.0), // 创建一个包含 32 个 0.0 的数组
  receivedData: [], // 接收到的数据
  isScanning: false, // 扫描状态
  isConnected: false, // 连接状态
  isConnecting: false, // 连接中状态
  isSetuping: false, // 设置中状态
  setupSucceed: false, // 设置成功状态
  connectedDeviceName: '未连接设备', // 已连接设备的名称
  connectedDeviceId: null, // 已连接设备的 ID
  devices: [], // 扫描到的设备列表
  devicesFound: 0, // 扫描到的设备数量
  SCAN_DURATION: 5000, // 扫描持续时间
  CHARACTERISTIC_UUID_Notify: '0000FFF1-0000-1000-8000-00805F9B34FB', // 监听的特征值 UUID
  SERVICE_UUID_Notify: '0000FFF0-0000-1000-8000-00805F9B34FB', // 服务 UUID
  CHARACTERISTIC_UUID_Write: '0000FFF2-0000-1000-8000-00805F9B34FB', // 可选写入特征值 UUID
  SERVICE_UUID_Write: '0000FFF0-0000-1000-8000-00805F9B34FB', // 可选写入服务 UUID
})

// 扫描按钮的模型
const morphGroupModel = ref('btn')

// 当前被展开的卡片 ID
const expandedCard = ref(null)
// 存储每个卡片的 DOM 引用
const cardRefs = ref([])
const toggleOn = ref(Array(6).fill(false))
// 使用computed来实时获取有几个toggle被打开
DevicesChnState.value.activeChns = computed(() => {
  return toggleOn.value.filter((value) => value).length
})
// 小卡片的数据
const cards = [
  { id: 'card1', title: 'Card 1', color: 'lightblue' },
  { id: 'card2', title: 'Card 2', color: 'lightgreen' },
  { id: 'card3', title: 'Card 3', color: 'lightcoral' },
  { id: 'card4', title: 'Card 4', color: 'lightgoldenrodyellow' },
  { id: 'card5', title: 'Card 5', color: 'lightpink' },
  { id: 'card6', title: 'Card 6', color: 'lightseagreen' },
]

// 卡片的默认样式
const cardStyle = {
  width: '100%',
  height: '15.7%',
  cursor: 'pointer',
  transition: 'all 0.3s ease',
  borderRadius: '1em',
}

// 扩展卡片时的样式
const expandedCardStyle = {
  width: '100%!important',
  height: '100%!important',
  borderRadius: '1em',
}

// 点击卡片时，展开或收起卡片
const zoomCard = (index, act) => {
  const previousExpandedCard = expandedCard.value
  let cancel = undefined
  // 只有在 act === 1 或者卡片已经展开时才进行动画处理
  if (act === 1 || toggleOn.value[index] || expandedCard.value === cards[index].id) {
    // 如果当前卡片已经展开，则执行收回动画
    if (expandedCard.value === cards[index].id) {
      // 使用 morph 动画来收回卡片，确保收回时完全对称
      cancel = morph({
        from: cardRefs.value[index].$el, // 从当前的展开位置开始
        to: cardRefs.value[index].$el, // 目标是回到原来的位置
        waitFor: 0,
        duration: 300, // 收回的动画时长与展开保持一致
        onToggle: () => {
          // 动画完成后再修改状态
          nextTick(() => {
            expandedCard.value = null
          })
        },
      })
    } else {
      // 如果是新的卡片，执行展开动画
      cancel = morph({
        from: cardRefs.value[index].$el, // 从当前位置展开
        to: cardRefs.value[index].$el, // 到达展开后的最大尺寸
        waitFor: 0,
        duration: 300, // 展开的动画时长
        onToggle: () => {
          nextTick(() => {
            expandedCard.value = cards[index].id
          })
        },
      })
    }
  }
  // 如果有卡片正在展开且当前操作没有取消动画，恢复原状态
  if (previousExpandedCard !== null && (cancel === undefined || cancel() === false)) {
    morph({
      from: cardRefs.value[cards.findIndex((card) => card.id === previousExpandedCard)].$el,
      waitFor: 0,
      duration: 200,
    })
  }
}

// 在每次更新前，重置引用
onBeforeUpdate(() => {
  cardRefs.value = []
})

//BLE

function paramSetup() {
  try {
    BLEConfig.value.isSetuping = true
    // 设置参数具体内容
    // 遍历每个toggle，单独进行赋值和发送
    for (let i = 0; i < toggleOn.value.length; i++) {
      // 当某个toggle被选中时，设定对应的参数并发送
      if (toggleOn.value[i]) {
        //设定参数：
        BLEConfig.value.messageToSend = DevicesChnState.value[i].configParams
        console.log('messageToSend:', BLEConfig.value.messageToSend)

        //发送：
        sendMessage()
        //结束循环
        setTimeout(async () => {}, 500)
      }
    }

    //等待设备response：

    setTimeout(async () => {
      BLEConfig.value.isSetuping = false
      BLEConfig.value.setupSucceed = true
    }, 1000)
  } catch (error) {
    console.error('Error setup parameters:', error)
    BLEConfig.value.setupSucceed.value = false
  }
}

function onDisconnect() {
  console.log('Device disconnected')
  BLEConfig.value.connectedDeviceId = null
  BLEConfig.value.connectedDeviceName = null
  BLEConfig.value.isConnected = false
}

async function scanForDevices() {
  try {
    BLEConfig.value.devices = [] // 清空设备列表
    await BleClient.initialize()
    BLEConfig.value.isScanning = true
    morphGroupModel.value = nextMorphStep[morphGroupModel.value]
    await BleClient.requestLEScan({}, (device) => {
      if (device.device.name != null) {
        const existingDevice = BLEConfig.value.devices.find(
          (d) => d.displayId === device.device.deviceId,
        )
        if (!existingDevice) {
          BLEConfig.value.devicesFound += 1
          BLEConfig.value.devices.push({
            displayName:
              device.device.displayName === ' ch583_ble_uart' ? 'Erpobe' : device.device.name,
            displayId: device.device.deviceId,
            displayRssi: device.rssi,
          })
        }
      }
    })

    // 停止扫描
    setTimeout(async () => {
      await BleClient.stopLEScan()
      BLEConfig.value.isScanning = false
      setTimeout(async () => {
        if (morphGroupModel.value === 'card1' && BLEConfig.value.devicesFound === 0) {
          morphGroupModel.value = nextMorphStep[morphGroupModel.value]
        }
      }, 5000)
    }, BLEConfig.value.SCAN_DURATION)
  } catch (error) {
    console.error('Error scanning for devices:', error)
    BLEConfig.value.isScanning = false
    await BleClient.stopLEScan() // 确保扫描被正确停止
  }
}
async function nextMorph() {
  try {
    morphGroupModel.value = nextMorphStep[morphGroupModel.value]
  } catch (error) {
    console.error('Error connecting to device:', error)
  }
}
async function connectToDevice(device) {
  try {
    BLEConfig.value.isConnecting = true
    morphGroupModel.value = nextMorphStep[morphGroupModel.value]
    await BleClient.connect(device.displayId, () => onDisconnect())
    BLEConfig.value.connectedDeviceId = device.displayId
    BLEConfig.value.connectedDeviceName = device.displayName || 'Unknown Device'
    console.log('Connected to device:', device)

    await startNotifications()
    BLEConfig.value.isConnected = true
    BLEConfig.value.isConnecting = false
  } catch (error) {
    console.error('Error connecting to device:', error)
  }
}

async function startNotifications() {
  await BleClient.startNotifications(
    BLEConfig.value.connectedDeviceId,
    BLEConfig.value.SERVICE_UUID_Notify,
    BLEConfig.value.CHARACTERISTIC_UUID_Notify,
    (value) => {
      const uint8Array = new Uint8Array(value.buffer, value.byteOffset, value.byteLength)
      const receivedNumbers = uint8ArrayToFloatArray(uint8Array)
      // 调用decodeData函数进行数据解码和处理
      decodeData(receivedNumbers)

      BLEConfig.value.receivedData.push(receivedNumbers)
      // console.log('Received data:', receivedNumbers)
    },
  )
}

async function decodeData(receivedNumbers) {
  // 临时对象用于收集每个通道的数据
  const channelData = {}

  // 遍历接收到的数据并按通道分类
  for (let i = 0; i < receivedNumbers.length; i += 3) {
    const chn = receivedNumbers[i] // 通道编号
    const data_x = receivedNumbers[i + 1] // x数据
    const data_y = receivedNumbers[i + 2] // y数据

    // 确保通道有效
    if (chn >= 0 && chn < DevicesChnState.value.length) {
      // 获取目标通道的原始数据（避免响应式影响）
      // const targetChannel = toRaw(DevicesChnState.value[chn])

      // 初始化通道的数据存储
      if (!channelData[chn]) {
        channelData[chn] = []
      }

      // 将接收到的数据添加到临时通道数据中
      channelData[chn].push({ x: data_x, y: data_y })

      // console.log(`Channel ${chn}: Added data (x: ${data_x}, y: ${data_y})`)
    } else {
      console.warn(`Invalid channel number: ${chn}`)
    }
  }

  // 使用 nextTick 确保数据更新不会立刻触发 watch
  await nextTick(() => {
    for (let chn in channelData) {
      const targetChannel = DevicesChnState.value[chn]

      // 合并数据，确保不触发递归
      targetChannel.displayData.data = [...targetChannel.displayData.data, ...channelData[chn]]
    }
  })
}

function uint8ArrayToFloatArray(byteArray) {
  // 创建一个 DataView 来操作字节数据
  const dataView = new DataView(byteArray.buffer)

  const floatArray = []

  // 遍历 byteArray，每 4 个字节转换成一个 float
  for (let i = 0; i < byteArray.length; i += 4) {
    const floatValue = dataView.getFloat32(i, true) // true 表示小端法
    floatArray.push(floatValue)
  }

  return floatArray
}

async function sendMessage() {
  if (!BLEConfig.value.connectedDeviceId || !Array.isArray(BLEConfig.value.messageToSend)) {
    console.warn('No device connected or message is empty or not an array')
    return
  }

  console.log('SERVICE_UUID_Write:', BLEConfig.value.SERVICE_UUID_Write)
  console.log('CHARACTERISTIC_UUID_Write:', BLEConfig.value.CHARACTERISTIC_UUID_Write)

  if (!BLEConfig.value.SERVICE_UUID_Write || !BLEConfig.value.CHARACTERISTIC_UUID_Write) {
    console.error('UUIDs are missing!')
    return
  }

  try {
    // 获取messageToSend的长度并进行检测
    const messageLength = BLEConfig.value.messageToSend.length
    const expectedLength = 32 // 期望的float数量

    // 如果messageToSend长度大于32个float，抛出错误
    if (messageLength > expectedLength) {
      console.error(`Error: messageToSend has more than ${expectedLength} floats!`)
      return
    }

    // 如果messageToSend长度小于32个float，补充零值
    if (messageLength < expectedLength) {
      console.warn(`messageToSend has only ${messageLength} floats, padding with zero values.`)
      const padding = new Array(expectedLength - messageLength).fill(0.0) // 用0填充到32个float
      BLEConfig.value.messageToSend = BLEConfig.value.messageToSend.concat(padding) // 合并原数据和填充的数据
    }

    // 分别处理前四个uint32和28个float
    const uint32Array = BLEConfig.value.messageToSend.slice(0, 4) // 获取前四个uint32
    const floatArray = BLEConfig.value.messageToSend.slice(4) // 获取剩余的float数据

    // 将uint32转换为Uint8Array（4个uint32）
    const uint32Data = new Uint8Array(4 * 4) // 4个uint32，每个32位，占4字节
    uint32Array.forEach((value, index) => {
      const view = new DataView(uint32Data.buffer)
      view.setUint32(index * 4, value, true) // true表示小端字节序
    })

    // 将float转换为Uint8Array（28个float）
    const floatData = new Uint8Array(28 * 4) // 28个float，每个32位，占4字节
    floatArray.forEach((value, index) => {
      const view = new DataView(floatData.buffer)
      view.setFloat32(index * 4, value, true) // true表示小端字节序
    })

    // 合并uint32数据和float数据
    const data = new Uint8Array(uint32Data.length + floatData.length)
    data.set(uint32Data) // 先设置uint32数据
    data.set(floatData, uint32Data.length) // 然后设置float数据

    // 确保发送的数据长度为128字节（32个float）
    if (data.length !== 128) {
      console.warn(`The data length is ${data.length}, but it should be 128 bytes.`)
    }

    // 使用蓝牙API发送数据
    await BleClient.writeWithoutResponse(
      BLEConfig.value.connectedDeviceId,
      BLEConfig.value.SERVICE_UUID_Write,
      BLEConfig.value.CHARACTERISTIC_UUID_Write,
      data,
    )
    console.log('Message sent successfully:')
    console.log([...data].map((byte) => byte.toString(16).padStart(2, '0')).join(' '))
  } catch (error) {
    console.error('Error sending message:', error) // 发送失败，输出错误信息
  }
}

// function floatArrayToUint8Array(floatArray) {
//   // 创建一个字节数组，用于存储所有的字节数据
//   let byteArray = new Uint8Array(floatArray.length * 4) // 每个float占4字节
//   const dataView = new DataView(byteArray.buffer)

//   floatArray.forEach((floatValue, index) => {
//     // 使用 setFloat32 将浮动数值以小端法存储
//     dataView.setFloat32(index * 4, floatValue, true) // true 表示小端法
//   })

//   return byteArray // 返回 Uint8Array 格式的数据
// }

async function start() {
  try {
    // 创建一个包含 32 个 8 字节数的 Uint8Array
    const data = new Uint8Array(32 * 4) // 32 个 8 字节数，合计 256 字节

    // 填充第一个 4 字节为 '10 00 00 00'
    const first4Bytes = new Uint8Array([0x10, 0x00, 0x00, 0x00])

    // 将第一个 4 字节数放入 data 数组的前面
    data.set(first4Bytes, 0)

    if (data.length !== 128) {
      console.warn(`The data length is ${data.length}, but it should be 128 bytes.`)
    }
    // 使用 BleClient.writeWithoutResponse 发送数据
    await BleClient.writeWithoutResponse(
      BLEConfig.value.connectedDeviceId,
      BLEConfig.value.SERVICE_UUID_Write,
      BLEConfig.value.CHARACTERISTIC_UUID_Write,
      data, // 发送 ArrayBuffer 格式的数据
    )
    // console.log('Start')
    console.log([...data].map((byte) => byte.toString(16).padStart(2, '0')).join(' '))

    for (let index = 0; index < 6; index++) {
      DevicesChnState.value[index].displayData.data = []
    }

    setTimeout(async () => {
      DevicesChnState.value.activeTab = 'Techniques' // 切换到 Techniques 页面
    }, 400)
  } catch (error) {
    console.error('Error sending data:', error)
  }
}

async function disconnectDevice() {
  if (!BLEConfig.value.connectedDeviceId) return
  BLEConfig.value.setupSucceed = false
  try {
    // 创建一个包含 32 个 8 字节数的 Uint8Array
    const data = new Uint8Array(32 * 4) // 32 个 8 字节数，合计 256 字节

    // 填充第一个 4 字节为 '00 00 00 10'
    const first4Bytes = new Uint8Array([0x10, 0x00, 0x00, 0x00])
    const forth4Bytes = new Uint8Array([0x01, 0x00, 0x00, 0x00])

    // 将第一个 4 字节数放入 data 数组的前面
    data.set(first4Bytes, 0)
    // 将第四个 4 字节数放入 data 数组的第四个位置
    data.set(forth4Bytes, 12) // 放在第12到第15个字节的位置（第4个四字节数）

    if (data.length !== 128) {
      console.warn(`The data length is ${data.length}, but it should be 128 bytes.`)
    }
    // 使用 BleClient.writeWithoutResponse 发送数据
    await BleClient.writeWithoutResponse(
      BLEConfig.value.connectedDeviceId,
      BLEConfig.value.SERVICE_UUID_Write,
      BLEConfig.value.CHARACTERISTIC_UUID_Write,
      data, // 发送 ArrayBuffer 格式的数据
    )
    console.log('Stop all')
    BleClient.disconnect(BLEConfig.value.connectedDeviceId)
    onDisconnect()

    console.log('Device disconnected successfully')
  } catch (error) {
    console.error('Error disconnecting device:', error)
  }
}

watch(
  () => BLEConfig.value.isConnected, // 观察 isConnected 的变化
  (newIsConnected) => {
    // 如果 isConnected 变成 false，则重置所有状态
    if (!newIsConnected) {
      BLEConfig.value.isScanning = false // 扫描状态
      BLEConfig.value.isConnecting = false // 连接中状态
      BLEConfig.value.isSetuping = false // 设置中状态
      BLEConfig.value.setupSucceed = false // 设置成功状态
      BLEConfig.value.connectedDeviceName = '未连接设备' // 已连接设备的名称
      BLEConfig.value.connectedDeviceId = null // 已连接设备的 ID
      toggleOn.value = Array(6).fill(false) // 重置 toggleOn 数组
    }
  },
  { immediate: true }, // 在初始化时就执行一次 watch 的回调，确保一开始状态是正确的
)
// 监听prop变化，确保父组件的数据更新时，子组件也能反映
watch(
  () => props.modelValue,
  (newValue) => {
    DevicesChnState.value = newValue
  },
)

watch(
  DevicesChnState, // 监听整个对象
  (newValue) => {
    nextTick(() => {
      emit('update:modelValue', newValue) // 触发更新事件
      // console.log('DevicesChnState changed:', newValue) // 打印变化
    })
  },
  { deep: true },
)

watch(
  () => BLEConfig.value.connectedDeviceId, // 监听 BLEConfig 的 connectedDeviceId
  async (newValue) => {
    DevicesChnState.value.connectedDeviceId = newValue // 当值变化时同步到 DevicesChnState
    console.log(
      ' New DevicesChnState.value.connectedDeviceId:',
      DevicesChnState.value.connectedDeviceId,
    ) // 打印新的 connectedDeviceId
  },
)
</script>
<style scoped>
/* 使用 Grid 布局 */
.card-grid {
  display: grid;
  grid-template-columns: repeat(1, 1fr); /* 1列 */
  grid-template-rows: repeat(6, 1fr); /* 6行 */
  gap: 10px;
  width: 100%;
  height: 100%;
  position: relative;
}

/* 展开时的样式 */
.card.expanded {
  width: 90% !important;
  height: 40% !important;
}
</style>
