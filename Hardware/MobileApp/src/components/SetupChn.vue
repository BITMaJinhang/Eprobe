<template>
  <div class="q-pa-sm" style="height: 90%">
    <q-card style="height: 100%; border-radius: 1em" flat bordered>
      <q-card-section class="scroll-container">
        <!-- Technique 选择框 -->
        <q-select
          filled
          transition-show="flip-up"
          transition-hide="flip-down"
          v-model="model"
          :options="options"
          label="Technique"
          dense
          options-dense
        />

        <!-- 动态显示对应参数 -->
        <div class="param-grid" style="height: 100%; max-height: 340px">
          <q-input
            v-for="(param, index) in selectedParams"
            :key="index"
            v-model="param.value"
            :label="param.label"
            dense
            type="number"
          />
          <!-- {{ SetupChnState }}
          {{ parameters }} -->
        </div>
      </q-card-section>
    </q-card>
  </div>
</template>

<script setup>
import { ref, watch } from 'vue'
import { defineProps, defineEmits } from 'vue'

// 接收父组件传递的 DevicesChnState
const props = defineProps({
  modelValue: Object,
})

const SetupChnState = ref(props.modelValue)

// 当数据变化时，通知父组件或子组件更新
const emit = defineEmits(['update:modelValue'])

// 监听prop变化，确保父组件或子组件的数据更新时，孙组件也能反映
watch(
  () => props.modelValue,
  (newValue) => {
    SetupChnState.value = newValue
  },
)

watch(SetupChnState, (newValue) => {
  emit('update:modelValue', newValue)
})

// 选择的Technique
const model = ref(null)

// Technique选项
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

// 不同的Technique对应的参数
const parameters = {
  'Cyclic Voltammetry (CV)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'HighE (V)', value: '0' },
    { label: 'LowE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Direct', value: '1' },
    { label: 'Scan Rate (V/s)', value: '0.01' },
    { label: 'Segments', value: '1' },
    { label: 'SampleInt (s)', value: '0.002' },
    { label: 'Quiet Time (s)', value: '1' },
  ],
  'Linear Sweep Voltammetry (LSV)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Scan Rate (V/s)', value: '0.01' },
    { label: 'SampleInt (s)', value: '0.002' },
    { label: 'Quiet Time (s)', value: '1' },
  ],
  'Staircase Voltammetry (SCV)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Scan Rate (V/s)', value: '0.01' },
    { label: 'Segments', value: '10' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'IncrE (V)', value: '0' },
    { label: 'Sample Width (s)', value: '0.2' },
    { label: 'Step Period (s)', value: '0.1' },
  ],
  'Tafel Plot (TAFEL)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Scan Rate (V/s)', value: '0.01' },
    { label: 'Segments', value: '2' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'IncrE (V)', value: '0' },
    { label: 'Hold Time (s)', value: '2' },
  ],
  'Chronoamperometry (CA)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'HighE (V)', value: '0' },
    { label: 'LowE (V)', value: '0' },
    { label: 'Direct', value: '1' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'Steps', value: '2' },
    { label: 'Pulse Width (s)', value: '2' },
    { label: 'SampleInt (s)', value: '0.2' },
  ],
  'Chronocoulometry (CC)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'Steps', value: '3' },
    { label: 'Pulse Width (s)', value: '0' },
    { label: 'SampleInt (s)', value: '0.2' },
  ],
  'Differential Pulse Voltammetry (DPV)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'IncrE (V)', value: '0' },
    { label: 'Sample Width (s)', value: '0.1' },
    { label: 'Pulse Width (s)', value: '0' },
    { label: 'Amplitude (A)', value: '0.1' },
    { label: 'Pulse Period (s)', value: '0.2' },
  ],
  'Normal Pulse Voltammetry (NPV)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'IncrE (V)', value: '0' },
    { label: 'Sample Width (s)', value: '0.1' },
    { label: 'Pulse Width (s)', value: '0' },
    { label: 'Pulse Period (s)', value: '0.2' },
  ],
  'Differential Normal Pulse Voltammetry (DNPV)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'IncrE (V)', value: '0' },
    { label: 'Sample Width (s)', value: '0.1' },
    { label: 'Amplitude (A)', value: '0.1' },
    { label: 'Pulse Period (s)', value: '0.2' },
    { label: 'Pulse Width 1 (s)', value: '0' },
    { label: 'Pulse Width 2 (s)', value: '0' },
  ],
  'Square Wave Voltammetry (SWV)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'FinalE (V)', value: '0' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'IncrE (V)', value: '0' },
    { label: 'Amplitude (A)', value: '0.1' },
    { label: 'Frequency (Hz)', value: '10' },
  ],
  'Amperometric i-t Curve (i-t)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'SampleInt (s)', value: '0.1' },
    { label: 'Run Time (s)', value: '60' },
    { label: 'Scales During Run', value: '1' },
  ],
  'Multi-Potential Steps (STEP)': [
    { label: 'InitE (V)', value: '0' },
    { label: 'Quiet Time (s)', value: '1' },
    { label: 'SampleInt (s)', value: '0.1' },
    { label: 'E1 (V)', value: '0' },
    { label: 'T1 (s)', value: '0' },
    { label: 'E2 (V)', value: '0' },
    { label: 'T2 (s)', value: '0' },
    { label: 'E3 (V)', value: '0' },
    { label: 'T3 (s)', value: '0' },
    { label: 'E4 (V)', value: '0' },
    { label: 'T4 (s)', value: '0' },
    { label: 'E5 (V)', value: '0' },
    { label: 'T5 (s)', value: '0' },
    { label: 'E6 (V)', value: '0' },
    { label: 'T6 (s)', value: '0' },
    { label: 'E7 (V)', value: '0' },
    { label: 'T7 (s)', value: '0' },
    { label: 'E8 (V)', value: '0' },
    { label: 'T8 (s)', value: '0' },
    { label: 'E9 (V)', value: '0' },
    { label: 'T9 (s)', value: '0' },
    { label: 'E10 (V)', value: '0' },
    { label: 'T10 (s)', value: '0' },
    { label: 'E11 (V)', value: '0' },
    { label: 'T11 (s)', value: '0' },
    { label: 'T12 (s)', value: '0' },
    { label: 'E12 (V)', value: '0' },
    { label: 'Cycles', value: '1' },
  ],
}

// 选择的Technique对应的参数集
const selectedParams = ref([])

// 监听model的变化，动态更新selectedParams和configParams
watch(model, (newValue) => {
  if (newValue && parameters[newValue]) {
    selectedParams.value = parameters[newValue]

    // 更新configParams的第二个float为n-1
    SetupChnState.value.configParams = [
      ...SetupChnState.value.configParams.slice(0, 1), // 保持第一个值不变
      options.indexOf(newValue), // 第二个值为n-1，即索引值
      ...Array(4).fill(0), // 填充configParams的索引3到索引4的空值
      ...selectedParams.value.map((param) => param.value), // 将selectedParams的第一个浮动值赋值到configParams的第5个开始的位置
    ]
  } else {
    selectedParams.value = []
  }
})

// 监听 selectedParams 的变化
watch(
  selectedParams,
  (newSelectedParams) => {
    // 如果 selectedParams 不为空，提取其中的每个 param.value
    const newParams = newSelectedParams.map((param) => param.value)

    // 更新configParams，确保第5个起始位置的赋值
    SetupChnState.value.configParams = [
      ...SetupChnState.value.configParams.slice(0, 4), // 保持前4个值不变
      ...newParams, // 将剩余的值填充到从第5个浮动值开始
    ]
  },
  { deep: true },
)

// 默认初始化时，给model一个值，触发watch，显示对应的参数
if (options.length > 0) {
  model.value = options[0]
}
</script>

<style scoped>
.param-grid {
  display: grid;
  grid-template-columns: repeat(3, 1fr); /* 3列 */
  gap: 20px;
  row-gap: 5px;
  width: 100%;
  height: 100%;
  position: relative;
}
.scroll-container {
  max-height: 300px; /* 限制容器高度，防止内容超出 */
  overflow-y: auto; /* 允许垂直滚动 */
  padding-right: 15px; /* 保证滚动条不遮挡输入框 */
}
</style>
