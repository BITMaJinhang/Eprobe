import { BluetoothLe } from '@capacitor-community/bluetooth-le'

// 定义蓝牙模块的方法
const bluetooth = {
  /**
   * 初始化蓝牙功能
   */
  async initialize() {
    try {
      const result = await BluetoothLe.initialize()
      console.log('Bluetooth initialized:', result)
      return result
    } catch (error) {
      console.error('Bluetooth initialization failed:', error)
      throw error
    }
  },

  /**
   * 扫描蓝牙设备
   */
  async scanDevices() {
    const devices = []
    try {
      await BluetoothLe.requestDevice({
        services: [], // 可选：指定需要的服务 UUID 列表，空数组表示发现所有设备
      })

      BluetoothLe.addListener('onDeviceFound', (device) => {
        console.log('Found device:', device)
        devices.push(device) // 收集发现的设备
      })

      console.log('Scanning for devices...')
    } catch (error) {
      console.error('Error scanning devices:', error)
      throw error
    }
    return devices
  },

  /**
   * 连接蓝牙设备
   * @param {string} deviceId - 蓝牙设备 ID
   */
  async connectToDevice(deviceId) {
    try {
      const result = await BluetoothLe.connect({ deviceId })
      console.log('Connected to device:', result)
      return result
    } catch (error) {
      console.error('Failed to connect to device:', error)
      throw error
    }
  },

  /**
   * 发送数据到蓝牙设备
   * @param {string} deviceId - 蓝牙设备 ID
   * @param {string} service - 服务 UUID
   * @param {string} characteristic - 特征值 UUID
   * @param {string} data - 发送的数据（必须是 base64 格式）
   */
  async sendData(deviceId, service, characteristic, data) {
    try {
      const result = await BluetoothLe.write({
        deviceId,
        service,
        characteristic,
        value: btoa(data), // 将字符串转换为 base64
      })
      console.log('Data sent:', result)
      return result
    } catch (error) {
      console.error('Error sending data:', error)
      throw error
    }
  },

  /**
   * 接收数据
   * @param {string} deviceId - 蓝牙设备 ID
   * @param {string} service - 服务 UUID
   * @param {string} characteristic - 特征值 UUID
   */
  async startNotification(deviceId, service, characteristic) {
    try {
      await BluetoothLe.startNotifications({
        deviceId,
        service,
        characteristic,
      })

      BluetoothLe.addListener('onDataReceived', (data) => {
        console.log('Data received:', data)
      })
    } catch (error) {
      console.error('Error receiving data:', error)
      throw error
    }
  },
}

export default bluetooth
