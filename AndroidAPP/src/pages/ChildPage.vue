<!-- ChildPage.vue -->
<template>
  <div>
    <h2>Child Page</h2>
    <input v-model="childData" placeholder="修改子组件数据" />

    <!-- 孙组件的v-model绑定 -->
    <GrandChildPage v-model="childData" />
  </div>
</template>

<script setup>
import { defineProps, defineEmits, ref, watch } from 'vue'
import GrandChildPage from './Child2Page.vue'

// 接收父组件传递的数据
const props = defineProps({
  modelValue: String,
})

// 内部数据，用于双向绑定
const childData = ref(props.modelValue)

// 当数据变化时，通知父组件更新
const emit = defineEmits(['update:modelValue'])

// 监听prop变化，确保父组件的数据更新时，子组件也能反映
watch(
  () => props.modelValue,
  (newValue) => {
    childData.value = newValue
  },
)

watch(childData, (newValue) => {
  emit('update:modelValue', newValue)
})
</script>
