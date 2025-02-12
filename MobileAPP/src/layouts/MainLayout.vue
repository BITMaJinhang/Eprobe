<template>
  <q-layout view="lHh Lpr lFf" style="width: 100%" class="bg-grey-1">
    <q-header style="width: 100%" class="bg-grey-3 text-black">
      <q-toolbar>
        <q-toolbar-title class="text-weight-bold" style="font-size: 30px">
          Eprobe Assistant
        </q-toolbar-title>
        <q-btn
          :disable="true"
          flat
          @click="drawer = !drawer"
          round
          dense
          icon="account_circle"
          size="24px"
          color="blue-8"
        />
      </q-toolbar>
    </q-header>

    <q-drawer
      side="right"
      v-model="drawer"
      show-if-above
      :width="200"
      :breakpoint="500"
      bordered
      class="bg-grey-3"
    >
      <q-scroll-area class="fit">
        <q-list>
          <template v-for="(menuItem, index) in menuList" :key="index">
            <q-item clickable :active="menuItem.label === 'Outbox'" v-ripple>
              <q-item-section avatar>
                <q-icon :name="menuItem.icon" />
              </q-item-section>
              <q-item-section>
                {{ menuItem.label }}
              </q-item-section>
            </q-item>
            <q-separator :key="'sep' + index" v-if="menuItem.separator" />
          </template>
        </q-list>
      </q-scroll-area>
    </q-drawer>

    <q-page-container class="bg-grey-3">
      <div class="q-pa-none q-ma-none" style="width: 100%; height: 100%">
        <Devices v-model="MainChnState" v-show="MainChnState.activeTab === 'Devices'" />
        <Technique v-model="MainChnState" v-show="MainChnState.activeTab === 'Techniques'" />
        <Documents v-show="MainChnState.activeTab === 'Documents'" />
      </div>
    </q-page-container>

    <q-footer bordered reveal class="bg-white text-primary">
      <div class="q-pt-none q-pb-none">
        <div class="q-gutter-y-md q-pt-none" style="width: 100%">
          <q-tabs
            v-model="MainChnState.activeTab"
            no-caps
            active-color="blue"
            indicator-color="transparent"
            class="bg-grey-3 text-weight-thin text-grey-7"
          >
            <q-tab icon="devices" name="Devices" label="Devices" />
            <q-tab
              icon="monitor_heart"
              name="Techniques"
              label="Techniques"
              @click="MainChnState.expandedCard = null"
            />
            <q-tab icon="pending_actions" name="Documents" label="Documents" :disable="true" />
          </q-tabs>
        </div>
      </div>
    </q-footer>
  </q-layout>
</template>

<script setup>
import Technique from '../pages/TechniquesPage.vue'
import Devices from '../pages/DevicesPage.vue'
import Documents from '../components/BluetoothTest.vue'
import { ref } from 'vue'

const MainChnState = ref([
  {
    configParams: new Array(32).fill(0), // 32个配置参数，默认值为0
    displayData: {
      data: [], // 显示数据，默认为空数组
    },
  },
  {
    configParams: new Array(32).fill(0), // 32个配置参数，默认值为0
    displayData: {
      data: [], // 显示数据，默认为空数组
    },
  },
  {
    configParams: new Array(32).fill(0), // 32个配置参数，默认值为0
    displayData: {
      data: [], // 显示数据，默认为空数组
    },
  },
  {
    configParams: new Array(32).fill(0), // 32个配置参数，默认值为0
    displayData: {
      data: [], // 显示数据，默认为空数组
    },
  },
  {
    configParams: new Array(32).fill(0), // 32个配置参数，默认值为0
    displayData: {
      data: [], // 显示数据，默认为空数组
    },
  },
  {
    configParams: new Array(32).fill(0), // 32个配置参数，默认值为0
    displayData: {
      data: [], // 显示数据，默认为空数组
    },
  },
  {
    connectedDeviceId: 'null', // 连接的设备ID
    activeTab: ref('Devices'),
    activeChns: ref(0), // 激活的通道数
    expandedCard: ref(''), // 当前展开的卡片索引
  },
])

// 更新前六个通道的 configParams，第一个 float 值为通道数-1
MainChnState.value.slice(0, 6).forEach((channel, index) => {
  channel.configParams[0] = index // 每个通道的第一个float设为通道号-1
})

const drawer = ref(false)
// 控制哪个Tab被激活
// const activeTab = ref('Devices')
MainChnState.value.activeTab = 'Devices'
const menuList = [
  {
    icon: 'inbox',
    label: 'Inbox',
    separator: true,
  },
  {
    icon: 'send',
    label: 'Outbox',
    separator: false,
  },
  {
    icon: 'delete',
    label: 'Trash',
    separator: false,
  },
  {
    icon: 'error',
    label: 'Spam',
    separator: true,
  },
  {
    icon: 'settings',
    label: 'Settings',
    separator: false,
  },
  {
    icon: 'feedback',
    label: 'Send Feedback',
    separator: false,
  },
  {
    icon: 'help',
    iconColor: 'primary',
    label: 'Help',
    separator: false,
  },
]
</script>
