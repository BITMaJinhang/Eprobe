<template>
  <q-card
    class="q-pa-none"
    style="overflow-y: auto; height: 93%; background-color: rgba(255, 255, 255, 0.5)"
    flat
  >
    <q-card-section style="height: 40em; width: 100%; overflow-y: auto">
      <label style="color: black" class="q-pl-sm">{{ ChnTechnique || '*Technique*' }}</label>
      <div class="q-pa-none q-ma-none" style="width: 100%; margin: 0 auto; height: 100%">
        <q-card class="q-pa-none q-ma-none" style="height: 200px; width: 280px">
          <Scatter
            ref="scatterChart"
            class="q-pa-none q-ma-none"
            style="width: 100%; height: 220px !important"
            :data="chartData"
            :options="chartOptions"
          />
          <q-card
            class="q-pt-md q-mt-sm"
            style="
              justify-content: center;
              align-items: center;
              text-align: center;
              border-radius: 0.3em;
              height: inherit;
              box-shadow: 0 2px 4px rgba(0, 0, 0, 0.3);
              background-color: rgba(255, 255, 255，1);
            "
          >
            <!-- 显示 x 和 y 数据的文本框 -->
            <div
              class="q-pb-sm q-mb-md"
              readonly
              style="
                background-color: rgba(0, 100, 255, 0.1);
                text-align: center;
                border-radius: 0.3em;
                width: fit-content;
                color: #212121;
                width: 60%;
                margin: 0 auto; /* 水平居中 */
              "
            >
              {{ receivedData }}
            </div>
            <!-- <div>过多数据显示会导致程序卡顿，请及时复制到剪切板之后清除数据</div> -->
            <!-- Stop/Replay 按钮 -->
            <q-btn
              class="q-mt-lg q-mr-md q-mb-sm"
              @click="toggleStopReplay"
              :label="isStopped ? 'Restart' : 'Stop'"
              :icon="isStopped ? 'replay' : 'stop'"
              :color="isStopped ? 'blue' : 'red'"
            ></q-btn>

            <!-- Pause/Continue 按钮 -->
            <q-btn
              class="q-mt-lg q-ml-md q-mb-sm"
              @click="togglePauseContinue"
              :label="isPaused ? 'Continue' : 'Pause'"
              :icon="isPaused ? 'play_arrow' : 'pause'"
              :color="isPaused ? 'green' : 'grey'"
            ></q-btn>
            <div>
              <q-btn
                @click="copyDataToClipboard"
                label="Copy"
                color="black"
                icon="file_copy"
                class="q-ma-md"
              />
              <!-- <q-btn @click="saveFile" :disable="true" label="Export Data to CSV" color="primary" /> -->
              <q-btn @click="Clear" label="Clear" color="black" icon="clear" class="q-ma-md" />
            </div>
          </q-card>
        </q-card>
      </div>
    </q-card-section>
  </q-card>
</template>
<script setup>
import { Scatter } from 'vue-chartjs'
import { ref, watch, onUnmounted } from 'vue'
import {
  Chart as ChartJS,
  Title,
  Tooltip,
  Legend,
  CategoryScale,
  LinearScale,
  ScatterController,
  PointElement,
} from 'chart.js'
import { BleClient } from '@capacitor-community/bluetooth-le'

// 接收父组件传递的 DevicesChnState
const props = defineProps({
  modelValue: Object,
  DispDataUpdateInterval: Number, // 接收DispDataUpdateInterval参数
  BLEConfig: Object,
  numOfChn: Number,
})

const DisplayChnState = ref(props.modelValue)

// 状态变量
const isStopped = ref(false) // 默认是 Stop 状态
const isPaused = ref(false) // 默认是 Pause 状态

// 切换 Stop/Replay 状态
const toggleStopReplay = () => {
  if (isStopped.value) {
    // 当前是 Replay 状态，点击后执行 Restart
    cmdChn('restart', props.numOfChn)
  } else {
    // 当前是 Stop 状态，点击后执行 Stop
    cmdChn('stop', props.numOfChn)
  }
  isStopped.value = !isStopped.value // 切换状态
}

// 切换 Pause/Continue 状态
const togglePauseContinue = () => {
  if (isPaused.value) {
    // 当前是 Continue 状态，点击后执行 Continue
    cmdChn('continue', props.numOfChn)
  } else {
    // 当前是 Pause 状态，点击后执行 Pause
    cmdChn('pause', props.numOfChn)
  }
  isPaused.value = !isPaused.value // 切换状态
}

// options 数组
const options = [
  'Cyclic Voltammetry (CV)',
  'Linear Sweep Voltammetry (LSV)',
  'Staircase Voltammetry (SCV)',
  'Tafel Plot (TAFEL)',
  'Chronoamperometry (CA)',
  'Chronocoulometry (CC)',
  'Differential Pulse Voltammetry (DPV)',
  'Normal Pulse Voltammetry (NPV)',
  'Differential Normal Pulse Voltammetry (DNPV)',
  'Square Wave Voltammetry (SWV)',
  'Amperometric i-t Curve (i-t)',
  'Multi-Potential Steps(STEP)',
]

// ChnTechnique 为响应式变量，用于存储当前选择的技术名称
const ChnTechnique = ref('')

// 定义每种模式对应的 X 和 Y 轴标签
const axisLabels = {
  'Cyclic Voltammetry (CV)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Linear Sweep Voltammetry (LSV)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Staircase Voltammetry (SCV)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Tafel Plot (TAFEL)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Chronoamperometry (CA)': { x: 'Time (s)', y: 'Current (mA)' },
  'Chronocoulometry (CC)': { x: 'Time (s)', y: 'Charge (mC)' },
  'Differential Pulse Voltammetry (DPV)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Normal Pulse Voltammetry (NPV)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Differential Normal Pulse Voltammetry (DNPV)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Square Wave Voltammetry (SWV)': { x: 'Potential (V)', y: 'Current (mA)' },
  'Amperometric i-t Curve (i-t)': { x: 'Time (s)', y: 'Current (mA)' },
  'Multi-Potential Steps(STEP)': { x: 'Time (s)', y: 'Current (mA)' },
}

// 当数据变化时，通知父组件或子组件更新
const emit = defineEmits(['update:modelValue'])
let DispDataUpdateInterval = props.DispDataUpdateInterval

const DispBLEConfig = ref(props.BLEConfig)

watch(
  () => props.numOfChn.value,
  () => {
    console.log('index:', props.numOfChn.value)
  },
)

watch(
  () => props.BLEConfig.connectedDeviceId,
  (newValue) => {
    DispBLEConfig.value.connectedDeviceId = newValue
    console.log('Disp Connected device ID:', DispBLEConfig.value.connectedDeviceId)
  },
)

watch(
  () => props.DispDataUpdateInterval,
  (newValue) => {
    DispDataUpdateInterval = newValue
    console.log('DispDataUpdateInterval changed to:', newValue)
    startUpdatingChart() // 更新定时器间隔
    // 更新 chartData
    chartData.value = {
      datasets: [
        {
          label: 'Plot Points',
          data: displayData.value.data,
        },
      ],
    }
    console.log('DispChartData updated')
  },
)
// 监听prop变化，确保父组件或子组件的数据更新时，孙组件也能反映
watch(
  () => props.modelValue,
  (newValue) => {
    DisplayChnState.value = newValue
  },
)

watch(DisplayChnState, (newValue) => {
  emit('update:modelValue', newValue)
})

const displayData = ref(DisplayChnState.value.displayData)

// 注册需要的组件
ChartJS.register(
  Title,
  Tooltip,
  Legend,
  CategoryScale,
  LinearScale,
  ScatterController,
  PointElement,
)

const chartData = ref({
  datasets: [
    {
      label: 'Plot Points',
      data: displayData.value.data,
    },
  ],
})

const chartOptions = ref({
  responsive: true,
  plugins: {
    legend: {
      display: false, // 去掉图例
    },
  },
  radius: 2, // 设置点的大小
  animation: {
    duration: 0, // 禁用动画
    easing: 'linear',
  },
  backgroundColor: 'black',
  pointBackgroundColor: 'black', // 点的背景颜色

  scales: {
    x: {
      type: 'linear',
      position: 'bottom',
      title: {
        display: true,
        text: 'X Axis',
        align: 'end', // X轴标签右对齐
      },
      grid: {
        color: 'rgba(169, 169, 169, 0.5)', // 灰色参考线
        borderColor: 'rgba(169, 169, 169, 0.5)', // 灰色参考线
        borderDash: [5, 5], // 虚线样式
      },
    },
    y: {
      beginAtZero: true,
      title: {
        display: true,
        text: 'Y Axis',
        align: 'center', // Y轴标签居中对齐
      },
      grid: {
        color: 'rgba(169, 169, 169, 0.5)', // 灰色参考线
        borderColor: 'rgba(169, 169, 169, 0.5)', // 灰色参考线
        borderDash: [5, 5], // 虚线样式
      },
    },
  },
  layout: {
    padding: {
      left: 10,
      right: 20,
      top: 20,
      bottom: 20,
    },
  },
})

// 获取图表实例的引用
const scatterChart = ref(null)

const Clear = () => {
  DisplayChnState.value.displayData.data = []
}

// 用于执行命令
const cmdChn = async (cmd, index) => {
  try {
    // 创建一个包含 32 个 8 字节数的 Uint8Array
    const data = new Uint8Array(32 * 4) // 32 个 8 字节数，合计 256 字节

    // 根据 index 动态修改第一个 4 字节的数据
    let first4Bytes
    let forth4Bytes
    const byteValue = 0x10 + index * 0x10 // 动态计算第一个字节的值
    first4Bytes = new Uint8Array([byteValue, 0x00, 0x00, 0x00])
    forth4Bytes = new Uint8Array([0x00, 0x00, 0x00, 0x00])
    switch (cmd) {
      case 'stop':
        console.log('Stop chn', index + 1)
        forth4Bytes = new Uint8Array([0x02, 0x00, 0x00, 0x00])
        break
      case 'restart':
        // 清除 DisplayChnState
        for (let index = 0; index < 6; index++) {
          DisplayChnState.value.displayData.data = []
        }
        console.log('Restart chn', index + 1)
        forth4Bytes = new Uint8Array([0x03, 0x00, 0x00, 0x00])
        break
      case 'pause':
        console.log('Pause chn', index + 1)
        forth4Bytes = new Uint8Array([0x04, 0x00, 0x00, 0x00])
        break
      case 'continue':
        console.log('Continue chn', index + 1)
        forth4Bytes = new Uint8Array([0x05, 0x00, 0x00, 0x00])
        break
      default:
        console.warn(`Unknown command: ${cmd}`)
        return
    }

    // 将第一个 4 字节数放入 data 数组的前面
    data.set(first4Bytes, 0)

    // 将第四个 4 字节数放入 data 数组的第四个位置
    data.set(forth4Bytes, 12) // 放在第12到第15个字节的位置（第4个四字节数）

    if (data.length !== 128) {
      console.warn(`The data length is ${data.length}, but it should be 128 bytes.`)
    }

    // DispBLEConfig.value.connectedDeviceId = props.BLEConfig.connectedDeviceId // 填充你的连接设备ID
    console.log('Disp ConnectedID:', DispBLEConfig.value.connectedDeviceId)
    // 使用 BleClient.writeWithoutResponse 发送数据
    await BleClient.writeWithoutResponse(
      DispBLEConfig.value.connectedDeviceId,
      DispBLEConfig.value.SERVICE_UUID_Write,
      DispBLEConfig.value.CHARACTERISTIC_UUID_Write,
      data, // 发送 ArrayBuffer 格式的数据
    )
    console.log('Command executed:', cmd)
    console.log([...data].map((byte) => byte.toString(16).padStart(2, '0')).join(' '))
  } catch (error) {
    console.error('Error sending data:', error)
  }
}

const copyDataToClipboard = () => {
  const data = displayData.value.data

  // 检查是否支持 Clipboard API
  if (navigator.clipboard) {
    // Clipboard API 支持
    if (!data || data.length === 0) {
      alert('No data to copy.')
      return
    }

    const textToCopy = data
      .map((point) => `${point.x.toFixed(4)}, ${point.y.toFixed(4)}`)
      .join('\n')

    navigator.clipboard.writeText(textToCopy).then(
      () => {
        alert('Data has been copied to the clipboard!')
      },
      (err) => {
        console.error('Failed to copy text: ', err)
        alert('Failed to copy data.')
      },
    )
  } else {
    // 如果 Clipboard API 不支持，使用备用方法
    // alert('Clipboard API is not supported, using execCommand for copying.')

    const textToCopy = data
      .map((point) => `${point.x.toFixed(4)}, ${point.y.toFixed(4)}`)
      .join('\n')

    const textArea = document.createElement('textarea')
    textArea.value = textToCopy
    document.body.appendChild(textArea)
    textArea.select()
    try {
      document.execCommand('copy')
      alert('Data has been successfully copied!')
    } catch (err) {
      console.error('Fallback copy method failed:', err)
      alert('Failed to copy data.')
    }
    document.body.removeChild(textArea)
  }
}

// 监听 configParams[1] 的变化，更新 ChnTechnique 和轴标签
watch(
  () => DisplayChnState.value.configParams[1],
  (newValue) => {
    if (newValue >= 0 && newValue < options.length) {
      ChnTechnique.value = options[newValue]
      // 更新轴标签
      chartOptions.value.scales.x.title.text = axisLabels[ChnTechnique.value].x
      chartOptions.value.scales.y.title.text = axisLabels[ChnTechnique.value].y
    } else {
      ChnTechnique.value = 'Unknown Technique'
    }
  },
  { immediate: true },
)

// 定时器更新 chartData
let updateInterval

// 用于重新启动定时器
function startUpdatingChart() {
  if (updateInterval) {
    clearInterval(updateInterval) // 清除旧的定时器
  }
  updateInterval = setInterval(() => {
    // 更新 chartData
    chartData.value = {
      datasets: [
        {
          label: 'Plot Points',
          data: displayData.value.data,
        },
      ],
    }
    console.log('DispChartData updated')
  }, DispDataUpdateInterval) // 使用 DispDataUpdateInterval 作为定时器间隔
}

// 启动定时器
startUpdatingChart()

// 清除定时器，防止内存泄漏
onUnmounted(() => {
  if (updateInterval) {
    clearInterval(updateInterval)
  }
})
const receivedData = ref('') // 用来显示最新的 x 和 y 数据

// watch 监听 DisplayChnState 中的 displayData
watch(
  () => DisplayChnState.value.displayData,
  (newValue) => {
    if (!newValue || !Array.isArray(newValue.data) || newValue.data.length === 0) {
      console.warn('newValue.data 已清空或不是数组')
      return
    }

    // 取整个数据数组，而非第一个数据点
    const updatedData = newValue.data

    // 确保 displayData.value.data 是数组
    if (!Array.isArray(displayData.value.data)) {
      console.log('初始化 displayData.value.data 为数组')
      displayData.value.data = []
    }

    // 假设 x 和 y 的长度一致，进行更新
    updatedData.forEach((item, index) => {
      const xValues = Array.isArray(item.x) ? item.x : [item.x]
      const yValues = Array.isArray(item.y) ? item.y : [item.y]

      xValues.forEach((xVal, i) => {
        if (displayData.value.data[index * xValues.length + i]) {
          displayData.value.data[index * xValues.length + i].x = xVal
          displayData.value.data[index * xValues.length + i].y = yValues[i]
        } else {
          displayData.value.data.push({
            x: xVal,
            y: yValues[i],
          })
        }
      })
    })

    // 只取最后一个数据点生成字符串并赋值给 receivedData
    const lastItem = updatedData[updatedData.length - 1]
    const xUnit = axisLabels[ChnTechnique.value].x.split(' ')[1] // 获取 X 轴单位
    const yUnit = axisLabels[ChnTechnique.value].y.split(' ')[1] // 获取 Y 轴单位
    const dataStr = `x: ${lastItem.x.toFixed(4)} ${xUnit}, y: ${lastItem.y.toFixed(4)} ${yUnit}`

    receivedData.value = dataStr // 更新文本框显示的内容
    console.log('receivedData:', receivedData.value)
  },
  { deep: true },
)

//可能导致栈溢出，非必要
// watch(
//   () => displayData.value.data,
//   (newData) => {
//     // 将 displayData.data 中的 x 和 y 值同步到 DisplayChnState.displayData
//     const updatedX = []
//     const updatedY = []

//     // 遍历新的 displayData.data，提取 x 和 y 值
//     newData.forEach((item) => {
//       updatedX.push(item.x)
//       updatedY.push(item.y)
//     })

//     // 更新 DisplayChnState.displayData
//     DisplayChnState.value.displayData[0].x = updatedX
//     DisplayChnState.value.displayData[0].y = updatedY
//   },
//   { deep: true }, // 深度监听，确保监听到内部数组或对象的变化
// )
// import { Filesystem, Directory, Encoding } from '@capacitor/filesystem'

// 使用 `ref` 来存储文件内容
// const fileName = 'sample.txt'
// const fileContent = 'Hello, this is a sample text!'

// 保存文件的函数
// const saveFile = async () => {
//   try {
//     // 创建文件并写入内容
//     const result = await Filesystem.writeFile({
//       path: fileName,
//       data: fileContent,
//       directory: Directory.Documents, // 你可以选择不同的目录，如 `Directory.Data`, `Directory.ExternalStorage`
//       encoding: Encoding.UTF8, // 设置文件编码
//     })

//     // 文件保存成功后的反馈
//     console.log('File saved:', result)
//     alert('File saved successfully!')
//   } catch (e) {
//     console.error('Error saving file:', e)
//     alert('Failed to save file.')
//   }
// }
</script>
