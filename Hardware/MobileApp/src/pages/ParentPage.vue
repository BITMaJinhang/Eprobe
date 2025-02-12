<!-- ParentPage.vue -->
<template>
  <div>
    <h1>Parent Page</h1>

    <!-- 父组件的输入框，用于修改数据 -->
    <input v-model="dataFromParent" placeholder="修改父组件数据" />

    <!-- 子组件的v-model绑定 -->
    <ChildPage v-model="dataFromParent" />
  </div>
</template>

<script setup>
import { ref } from 'vue'
import ChildPage from './ChildPage.vue'

// 父组件的数据
const dataFromParent = ref('初始值')
</script>
