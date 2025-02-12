<template>
  <q-page style="width: 100%; height: 100%">
    <q-card-section class="q-pb-none q-pt-none">
      <div class="q-pl-sm q-mt-none text-weight-medium text-h5">Techniques</div>
    </q-card-section>
    <!-- 显示卡片 -->
    <div class="q-pa-sm" style="width: 100%; height: 78vh">
      <q-card class="q-pa-sm q-mb-md q-ma-sm bg-grey-2" :style="mainCardStyle">
        <div class="card-grid bg-grey-2">
          <q-card
            flat
            v-for="(card, index) in cards"
            style="width: 100% !important; height: 90% !important"
            :key="index"
            :class="['card', { expanded: TechniquesChnState.expandedCard === card.id }]"
            :ref="
              (el) => {
                cardRefs[index] = el
              }
            "
            @click="zoomCard(index)"
            :style="{
              backgroundColor: card.color,
              ...cardStyle,
              ...(TechniquesChnState.expandedCard === card.id ? expandedCardStyle : {}),
            }"
          >
            <q-card-actions style="width: 100% !important; height: 100% !important">
              <q-btn
                v-if="TechniquesChnState.expandedCard === card.id"
                icon="navigate_before"
                flat
                @click.stop="zoomCard(index, 1)"
              />
              <div class="q-pl-sm q-ma-none text-h6">Channel{{ index + 1 }}</div>
              <!-- 小窗显示缩略图 -->
              <div
                v-show="TechniquesChnState.expandedCard != card.id"
                style="height: 80% !important; width: 100% !important ; overflow-y: scroll"
              >
                <ThumbnailChn
                  v-model="TechniquesChnState[index]"
                  :ThumbDataUpdateInterval="dataUpdateInterval[0]"
                />
              </div>
              <!-- 大窗显示详细图 -->
              <div
                v-show="TechniquesChnState.expandedCard === card.id"
                style="height: 100% !important; width: 100% !important ; overflow-y: scroll"
              >
                <DisplayChn
                  v-model="TechniquesChnState[index]"
                  :DispDataUpdateInterval="dataUpdateInterval[1]"
                  :BLEConfig="BLEConfig"
                  :numOfChn="index"
                />
              </div>
            </q-card-actions>
          </q-card>
        </div>
      </q-card>
    </div>
    <!-- 悬浮按钮 -->
    <q-fab
      color="blue-grey"
      icon="keyboard_arrow_up"
      direction="up"
      style="position: absolute; bottom: 1em; right: 2em"
    >
      <q-fab-action
        label-class="bg-grey-4 text-black"
        label-style="font-size: 14px"
        external-label
        label-position="left"
        :label="btn.name"
        v-for="(btn, index) in buttons"
        :disable="TechniquesChnState.connectedDeviceId === null ? true : false"
        :key="index"
        round
        :name="btn.name"
        :icon="btn.icon"
        :color="btn.color"
        @click="btn.action"
        class="q-ma-sm"
      >
      </q-fab-action>
    </q-fab>
  </q-page>
</template>
<script setup>
import { ref, onBeforeUpdate, watch } from 'vue'
import { morph } from 'quasar'
import DisplayChn from '../components/DisplayChn.vue'
import ThumbnailChn from '../components/ThumbnailChn.vue'
import { defineProps, defineEmits } from 'vue'
import { BleClient } from '@capacitor-community/bluetooth-le'

// 接收父组件传递的 DevicesChnState
const props = defineProps({
  modelValue: Object,
})

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
  connectedDeviceId: props.modelValue.connectedDeviceId, // 已连接设备的 ID
  devices: [], // 扫描到的设备列表
  devicesFound: 0, // 扫描到的设备数量
  SCAN_DURATION: 5000, // 扫描持续时间
  CHARACTERISTIC_UUID_Notify: '0000FFF1-0000-1000-8000-00805F9B34FB', // 监听的特征值 UUID
  SERVICE_UUID_Notify: '0000FFF0-0000-1000-8000-00805F9B34FB', // 服务 UUID
  CHARACTERISTIC_UUID_Write: '0000FFF2-0000-1000-8000-00805F9B34FB', // 可选写入特征值 UUID
  SERVICE_UUID_Write: '0000FFF0-0000-1000-8000-00805F9B34FB', // 可选写入服务 UUID
})
const TechniquesChnState = ref(props.modelValue)
const dataUpdateInterval = ref([3000, 30000]) // 数据更新间隔，单位毫秒
// 触发事件更新父组件的值
const emit = defineEmits(['update:modelValue'])

// 监听prop变化，确保父组件的数据更新时，子组件也能反映
watch(
  () => props.modelValue,
  (newValue) => {
    TechniquesChnState.value = newValue
  },
  { deep: true },
)

// 监听 activeTab 的变化，关闭大卡片
watch(
  () => props.modelValue.activeTab,
  (newValue) => {
    if (newValue !== 'Techniques' && TechniquesChnState.value.expandedCard !== null) {
      // 关闭大卡片
      TechniquesChnState.value.expandedCard = null
      console.log('Active tab changed, closing expanded card.')
    }
  },
)

// 监听prop变化，确保父组件的数据更新时，子组件也能反映
watch(
  () => props.modelValue.connectedDeviceId,
  (newValue) => {
    BLEConfig.value.connectedDeviceId = newValue
  },
)

watch(TechniquesChnState, (newValue) => {
  emit('update:modelValue', newValue)
})

// 监听 activeChn 的变化，更新 Thumbnail 的 dataUpdateInterval
watch(
  () => TechniquesChnState.value.activeChns,
  (newValue) => {
    console.log('Active channels changed to:', newValue)
    dataUpdateInterval.value[0] = newValue === 0 ? 100000 : 500 + newValue * 500
    console.log('Thumbnail dataUpdateInterval changed to:', dataUpdateInterval.value[0])
  },
)

// 当前被展开的卡片 ID
// const expandedCard = ref(null)

// 监听 expandedCard 的变化，更新 Thumbnail 的 dataUpdateInterval
watch(
  () => TechniquesChnState.value.expandedCard,
  (newValue) => {
    console.log('Expanded card changed to:', newValue)
    dataUpdateInterval.value[0] =
      newValue === null
        ? TechniquesChnState.value.activeChns === 0
          ? 100000
          : 500 + TechniquesChnState.value.activeChns * 500
        : 100000
    dataUpdateInterval.value[1] =
      newValue === null ? 100000 : TechniquesChnState.value.activeChns === 0 ? 100000 : 400
    // console.log('Thumbnail dataUpdateInterval changed to:', dataUpdateInterval.value[0])
    // console.log('Display dataUpdateInterval changed to:', dataUpdateInterval.value[1])
  },
)

// 存储每个卡片的 DOM 引用
const cardRefs = ref([])

// 小卡片
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
  width: '100% ',
  height: '100% ',
  cursor: 'pointer',
  transition: 'all 0.5s ease',
  borderRadius: '1em',
  justifyContent: 'center',
  alignItems: 'center',
  flexDirection: 'column',
  display: 'flex',
}

// 扩展卡片时的样式
const expandedCardStyle = {
  width: '100% !important', // 展开时宽度占满父容器
  height: '100% !important', // 展开时高度占满父容器
  position: 'absolute', // 使用绝对定位来铺满整个主卡片
  top: '0',
  left: '0',
  zIndex: '10', // 保证展开的卡片在最上层
  transition: 'all 0.5s ease',
  borderRadius: '1em',
}

// 主卡片样式，保证它居中并占据 90% 高度和 95% 宽度
const mainCardStyle = {
  height: '100% ',
  width: '100% ',
  margin: '0 auto', // 居中对齐
  display: 'flex',
  justifyContent: 'center',
  alignItems: 'center',
  flexDirection: 'column',
  borderRadius: '1em',
}

// 点击卡片时的处理函数
const zoomCard = (index, back) => {
  const previousExpandedCard = TechniquesChnState.value.expandedCard
  let cancel = undefined

  // 如果当前卡片已经展开，则收回
  if (TechniquesChnState.value.expandedCard === cards[index].id && back) {
    TechniquesChnState.value.expandedCard = null
  } else {
    // 如果是新的卡片，执行展开动画
    cancel = morph({
      from: cardRefs.value[index].$el,
      onToggle: () => {
        TechniquesChnState.value.expandedCard = cards[index].id
      },
      duration: 400,
    })
  }

  // 如果有卡片正在展开且当前操作没有取消动画，恢复原状态
  if (previousExpandedCard !== null && (cancel === undefined || cancel() === false)) {
    morph({
      from: cardRefs.value[cards.findIndex((card) => card.id === previousExpandedCard)].$el,
      waitFor: 0,
      duration: 400,
    })
  }
}

// 在每次更新前，重置引用
onBeforeUpdate(() => {
  cardRefs.value = []
})

const buttons = ref([
  { name: 'Stop all', icon: 'stop', action: stopAll, color: 'red-8' },
  { name: 'Restart all', icon: 'replay', action: restartAll, color: 'black' },
  { name: 'Clear all', icon: 'clear', action: clearAll, color: 'blue-8' },
])

async function clearAll() {
  for (let index = 0; index < 6; index++) {
    TechniquesChnState.value[index].displayData.data = []
  }
}

async function stopAll() {
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
  } catch (error) {
    console.error('Error sending data:', error)
  }
}

async function restartAll() {
  try {
    console.log('Restart all')
    // 创建一个包含 32 个 8 字节数的 Uint8Array
    const data = new Uint8Array(32 * 4) // 32 个 8 字节数，合计 256 字节

    // 填充第一个 4 字节为 '02 00 00 10'
    const first4Bytes = new Uint8Array([0x00, 0x00, 0x00, 0x10])

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
    for (let index = 0; index < 6; index++) {
      TechniquesChnState.value[index].displayData.data = []
    }
    console.log('Restart all')
  } catch (error) {
    console.error('Error sending data:', error)
  }
}
</script>
<style scoped>
/* 使用 Grid 布局，确保卡片以三行两列排列 */
.card-grid {
  display: grid;
  grid-template-columns: repeat(2, minmax(0, 1fr)); /* 允许卡片大小适应 */
  grid-template-rows: repeat(3, minmax(0, 1fr)); /* 限制行的大小 */
  gap: 10px;
  width: 100%;
  height: 100%;
  position: relative;
}

/* 展开时的样式 */
.card.expanded {
  width: 90% !important; /* 展开时宽度占满父容器 */
  height: 68% !important; /* 展开时高度占满父容器 */
}
</style>
