<template>
  <q-card
    class="q-pa-none"
    style="overflow-y: auto; height: 93%; background-color: rgba(255, 255, 255, 0.8)"
    flat
  >
    <q-card-section class="q-pa-none q-ma-none" style="height: 100%; width: 100%; overflow-y: auto">
      <label
        style="text-align: center; color: black; font-size: 12px; width: 100% !important"
        class="q-pl-md"
        >{{ ChnTechnique || '*Technique*' }}</label
      >
      <q-card
        flat
        class="q-pa-none q-ma-none"
        style="height: 90px; width: 143px; background-color: rgba(255, 255, 255, 0.2)"
      >
        <Scatter
          ref="scatterChart"
          class="q-pa-none q-ma-none"
          style="width: 100%; height: 100%"
          :data="chartData"
          :options="chartOptions"
        />
      </q-card>
    </q-card-section>
  </q-card>
</template>

<script setup>
import { Scatter } from 'vue-chartjs'
import { ref, watch, onUnmounted } from 'vue'
import { defineProps, defineEmits } from 'vue'
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

// 接收父组件传递的 DevicesChnState
const props = defineProps({
  modelValue: Object,
  ThumbDataUpdateInterval: Number, // ThumbDataUpdateInterval
})

const ThumbnailChnState = ref(props.modelValue)

// options 数组
const options = ['CV', 'LSV', 'SCV', 'AFEL', 'CA', 'CC', 'DPV', 'NPV', 'DNPV', 'SWV', 'i-t', 'STEP']

// ChnTechnique 为响应式变量，用于存储当前选择的技术名称
const ChnTechnique = ref('')

// 当数据变化时，通知父组件或子组件更新
const emit = defineEmits(['update:modelValue'])
let ThumbDataUpdateInterval = props.ThumbDataUpdateInterval

watch(
  () => props.ThumbDataUpdateInterval,
  (newValue) => {
    ThumbDataUpdateInterval = newValue
    console.log('ThumbDataUpdateInterval changed to:', newValue)
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
    console.log('ThumbChartData updated')
  },
)
// 监听prop变化，确保父组件或子组件的数据更新时，孙组件也能反映
watch(
  () => props.modelValue,
  (newValue) => {
    ThumbnailChnState.value = newValue
  },
)

watch(ThumbnailChnState, (newValue) => {
  emit('update:modelValue', newValue)
})

// watch 监听 configParams[1] 的变化
watch(
  () => ThumbnailChnState.value.configParams[1], // 监听 configParams 中的第二个 float 值
  (newValue) => {
    // 直接使用索引来更新 ChnTechnique，如果 newValue 在 options 范围内
    if (newValue >= 0 && newValue < options.length) {
      ChnTechnique.value = options[newValue]
    } else {
      ChnTechnique.value = 'Unknown Technique' // 如果索引不在有效范围，设置默认值
    }
  },
  { immediate: true }, // 立即执行一次，以确保初始值正确
)
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

const displayData = ref(ThumbnailChnState.value.displayData)

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
  radius: 1.5, // 设置点的大小
  animation: {
    duration: 0, // 动画持续时间，单位是毫秒
    easing: 'linear',
  },
  backgroundColor: 'black',
  pointBackgroundColor: 'black', // 点的背景颜色
  scales: {
    x: {
      type: 'linear',
      position: 'bottom',
      title: {
        display: false, // 去掉X轴标题
      },
      ticks: {
        display: false, // 去掉X轴刻度数值
      },
      grid: {
        display: false, // 去掉网格线
      },
      // 移除X轴刻度线标记
      offset: true, // 使得刻度线不会显示
    },
    y: {
      beginAtZero: true,
      title: {
        display: false, // 去掉Y轴标题
      },
      ticks: {
        display: false, // 去掉Y轴刻度数值
      },
      grid: {
        display: false, // 去掉网格线
      },
      // 移除Y轴刻度线标记
      offset: true, // 使得刻度线不会显示
    },
  },
  layout: {
    padding: {
      left: 10,
      right: 10,
      top: 10,
      bottom: 10,
    },
  },
  elements: {
    point: {
      animation: {
        duration: 10, // 动画持续时间
        easing: 'none', // 弹跳缓动效果
      },
    },
  },
})

// 获取图表实例的引用
const scatterChart = ref(null)

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
    console.log('ThumbChartData updated')
  }, ThumbDataUpdateInterval) // 使用 ThumbDataUpdateInterval 作为定时器间隔
}

// 启动定时器
startUpdatingChart()

// 清除定时器，防止内存泄漏
onUnmounted(() => {
  if (updateInterval) {
    clearInterval(updateInterval)
  }
})

// watch 监听 ThumbnailChnState 中的 displayData
watch(
  () => ThumbnailChnState.value.displayData,
  (newValue) => {
    // console.log('newValue:', newValue)

    if (!newValue || !Array.isArray(newValue.data) || newValue.data.length === 0) {
      console.warn('newValue.data 已清空或不是数组')
      return
    }

    const updatedData = newValue.data[0]
    // console.log('updatedData:', updatedData) // 打印 updatedData 以查看其结构

    // 如果 x 和 y 不是数组，将它们包装成数组
    const xValues = Array.isArray(updatedData.x) ? updatedData.x : [updatedData.x]
    const yValues = Array.isArray(updatedData.y) ? updatedData.y : [updatedData.y]

    // 确保 displayData.value.data 是数组
    if (!Array.isArray(displayData.value.data)) {
      console.log('初始化 displayData.value.data 为数组')
      displayData.value.data = []
    }

    // 假设 x 和 y 的长度一致，进行更新
    xValues.forEach((xVal, index) => {
      if (displayData.value.data[index]) {
        displayData.value.data[index].x = xVal
        displayData.value.data[index].y = yValues[index]
      } else {
        displayData.value.data.push({
          x: xVal,
          y: yValues[index],
        })
      }
    })
  },
  { deep: true },
)
</script>
