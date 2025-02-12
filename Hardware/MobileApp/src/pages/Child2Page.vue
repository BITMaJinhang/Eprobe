<!-- GrandChildPage.vue -->
<template>
  <div>
    <h3>GrandChild Page</h3>
    <input v-model="grandChildData" placeholder="修改孙组件数据" />
  </div>
</template>

<script setup>
import { defineProps, defineEmits, ref, watch } from 'vue'

// 接收来自父组件/子组件传递的数据
const props = defineProps({
  modelValue: String,
})

// 内部数据，用于双向绑定
const grandChildData = ref(props.modelValue)

// 当数据变化时，通知父组件或子组件更新
const emit = defineEmits(['update:modelValue'])

// 监听prop变化，确保父组件或子组件的数据更新时，孙组件也能反映
watch(
  () => props.modelValue,
  (newValue) => {
    grandChildData.value = newValue
  },
)

watch(grandChildData, (newValue) => {
  emit('update:modelValue', newValue)
})
</script>
