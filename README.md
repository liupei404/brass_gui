# TRX Brass GUI

**TRX Brass 收发机固件的图形用户界面**

## 项目概述

TRX Brass GUI 是一个基于 LVGL 的业余无线电收发机图形用户界面，运行在嵌入式 Linux 系统上。该项目为 TRX Brass 硬件平台提供了完整的电台控制功能，包括频率控制、模式切换、频谱显示、数字模式处理等。

### 版本信息
- **当前版本**: v0.6.0
- **许可证**: LGPL-2.1-or-later
- **版权**: (c) 2022-2025 Belousov Oleg aka R1CBU

---

## 功能特性

### 核心功能
- ✅ **多模式支持**: LSB、USB、CW、CWR、AM、NFM、RTTY、Olivia
- ✅ **频率控制**: 精确的频率调节，支持步进选择（10Hz-5000Hz）
- ✅ **频谱显示**: 实时 FFT 频谱分析
- ✅ **数字模式**: FT8、RTTY、Olivia 等数字通信模式
- ✅ **CW 电报**: 完整的 CW 编码/解码功能
- ✅ **ATU 天调**: 自动天线调谐器支持
- ✅ **SWR 扫描**: 驻波比扫描功能
- ✅ **记忆频道**: 多个频率记忆存储

### 硬件控制
- ✅ **射频控制**: GPIO 控制的 BPF/LPF 滤波器切换
- ✅ **变频控制**: VHF/UHF 频段变频器控制
- ✅ **IIO 接口**: 直接控制射频硬件
- ✅ **FPGA 通信**: 通过 UIO 接口与 FPGA 通信
- ✅ **背光控制**: 可调节的屏幕背光控制
- ✅ **电源管理**: 完整的开关机控制（v0.6.0 新增）

### 用户界面
- ✅ **触摸屏支持**: 800x480 分辨率触摸屏
- ✅ **旋钮控制**: 多个编码器输入（主旋钮、VOL、MFK）
- ✅ **按键输入**: 面板按键和 GPIO 按键支持
- ✅ **语音反馈**: 语音提示和状态播报
- ✅ **可自定义**: 丰富的设置选项和快捷键配置

---

## 项目结构

```
gui/
├── src/                    # 源代码目录
│   ├── main.c              # 主程序入口
│   ├── main_screen.c        # 主屏幕逻辑
│   ├── radio.c             # 电台状态机和控制
│   ├── dsp.c               # 数字信号处理
│   ├── buttons.c            # 按钮控制
│   ├── events.c            # 事件系统
│   ├── queue.c             # 任务队列
│   ├── keyboard.c          # 键盘输入
│   ├── keypad.c            # 面板按键
│   ├── rotary.c            # 旋钮输入
│   ├── encoder.c           # 编码器输入
│   ├── hkey.c             # 硬件按键
│   ├── audio.c             # 音频处理
│   ├── recorder.c          # 音频录制
│   ├── mic.c              # 麦克风输入
│   ├── voice.cpp           # 语音反馈
│   ├── pannel.c           # 面板显示
│   ├── backlight.c         # 背光控制
│   ├── msg.c              # 消息显示
│   ├── screenshot.c        # 截图功能
│   ├── util.c             # 工具函数
│   ├── dialog.c           # 对话框框架
│   ├── memory.c           # 记忆管理
│   ├── gfsk.c            # GFSK 调制
│   ├── two_tone.c         # 双音测试
│   ├── generator.c        # 信号发生器
│   ├── textarea_window.c   # 文本输入窗口
│   ├── smeter.h           # 信号强度计
│   │
│   ├── bands/             # 波段管理
│   │   ├── bands.c        # 波段切换
│   │   ├── list.c         # 波段列表
│   │   ├── tree.c         # 波段树
│   │   └── interval.c     # 频率区间
│   │
│   ├── settings/          # 设置管理
│   │   ├── audio.c        # 音频设置
│   │   ├── bands.c        # 波段设置
│   │   ├── modes.c        # 模式设置
│   │   ├── options.c      # 选项设置
│   │   ├── rf.c           # 射频设置
│   │   ├── memory.c       # 记忆设置
│   │   ├── hw.c           # 硬件设置
│   │   ├── filter.c       # 滤波器设置
│   │   └── ft8.c         # FT8 设置
│   │
│   ├── dialog/            # 对话框实现
│   │   ├── dialog_settings.c      # 设置对话框
│   │   ├── dialog_audio_settings.c # 音频设置对话框
│   │   ├── dialog_rf_settings.c    # 射频设置对话框
│   │   ├── dialog_ft8.c          # FT8 对话框
│   │   ├── dialog_gps.c          # GPS 对话框
│   │   ├── dialog_recorder.c      # 录音对话框
│   │   ├── dialog_freq.c         # 频率输入对话框
│   │   ├── dialog_msg_cw.c       # CW 消息对话框
│   │   ├── dialog_msg_voice.c     # 语音消息对话框
│   │   ├── dialog_qth.c          # QTH 对话框
│   │   ├── dialog_callsign.c      # 呼号对话框
│   │   └── dialog_swrscan.c      # SWR 扫描对话框
│   │
│   ├── cw/                # CW 功能
│   │   ├── cw.c           # CW 主模块
│   │   ├── cw_encoder.c    # CW 编码器
│   │   ├── cw_decoder.c    # CW 解码器
│   │   └── cw_key.c       # CW 电键
│   │
│   ├── rtty/              # RTTY 模式
│   │   └── rtty.c
│   │
│   ├── olivia/            # Olivia 模式
│   │   ├── mfsk_encoder.cpp      # MFSK 编码器
│   │   ├── mfsk_demodulator.cpp  # MFSK 解调器
│   │   ├── mfsk_inputprocessor.cpp # 输入处理器
│   │   ├── mfsk_iterdecoder.cpp   # 迭代解码器
│   │   ├── mfsk_modulator.cpp    # 调制器
│   │   └── mfsk_parameters.cpp   # 参数设置
│   │
│   ├── fpga/              # FPGA 控制
│   │   ├── control.c      # 主控制寄存器
│   │   ├── adc.c          # ADC 控制
│   │   ├── dac.c          # DAC 控制
│   │   └── mb.c           # 主板控制
│   │
│   └── hw/                # 硬件抽象层
│       ├── gpio.c         # GPIO 控制
│       ├── iio.c          # IIO 接口
│       ├── pa_bias.c      # 功放偏置控制
│       ├── xvrt.c         # 变频器控制
│       └── power.c        # 电源管理（v0.6.0 新增）
│
├── lvgl/                 # LVGL 图形库
├── lv_drivers/          # LVGL 驱动程序
├── lv_conf.h            # LVGL 配置
├── lv_drv_conf.h        # LVGL 驱动配置
├── CMakeLists.txt       # 主构建文件
├── LICENSE             # LGPL-2.1 许可证
└── README.md           # 本文件
```

---

## 构建说明

### 依赖项
- **CMake**: >= 3.23
- **编译器**: GCC/G++
- **LVGL**: 子模块
- **LVGL Drivers**: 子模块
- **Freetype**: 字体渲染库
- **Linux Kernel**: >= 4.0（推荐）

### 编译步骤

```bash
# 1. 进入项目目录
cd gui

# 2. 创建构建目录
mkdir -p build && cd build

# 3. 配置构建
cmake ..

# 4. 编译
make -j$(nproc)

# 5. 安装（可选）
sudo make install
```

### 交叉编译

对于 ARM 平台的交叉编译：

```bash
# 设置交叉编译工具链
export CC=arm-linux-gnueabihf-gcc
export CXX=arm-linux-gnueabihf-g++
export CMAKE_TOOLCHAIN_FILE=path/to/toolchain.cmake

# 正常编译流程
mkdir -p build && cd build
cmake ..
make -j$(nproc)
```

---

## 硬件要求

### 目标平台
- **CPU**: ARM Cortex-A7 或更高
- **RAM**: >= 512MB
- **存储**: >= 2GB 可用空间
- **显示屏**: 800x480 LCD 触摸屏
- **音频**: 支持 ALSA 音频接口
- **GPIO**: 多个 GPIO 控制线
- **FPGA**: Zynq-7000 系列

### 输入设备
- `/dev/input/event0` - VOL 旋钮
- `/dev/input/event1` - MFK 编码器
- `/dev/input/event2` - 主频率旋钮
- `/dev/input/event3` - 面板按键
- `/dev/input/event4` - GPIO 按键

---

## 使用指南

### 基本操作

#### 频率控制
- **主旋钮**: 快速调整频率
- **FST 键**: 切换频率步进（10Hz/100Hz/500Hz/1kHz/5kHz）
- **波段上/下**: 快速切换业余波段

#### 模式切换
- **MODE 键**: 短按切换主模式（LSB→USB→AM→NFM→RTTY→CW→Olivia）
- **MODE 键**: 长按切换子模式（如 USB↔LSB, CW↔CWR）

#### 按钮功能
- **VOL 键**: 切换音量控制页面
- **MFK 键**: 切换多功能按键页面
- **APP 键**: 切换应用页面
- **POWER 键**: 短按切换背光，长按关机

#### 数字模式
- **FT8**: 支持 FT8 数字模式，自动解码
- **RTTY**: 支持 RTTY 模式，可调参数
- **Olivia**: 支持 Olivia 模式，多个预设

#### CW 电报
- **支持 Iambic 模式**
- **可调节键速**
- **内置 CW 编码/解码器**

### 电源管理（v0.6.0 新增）

#### 背光控制
```
短按 POWER 键 → 背光开关
```
- 关闭背光时系统继续运行
- 适用于夜间操作和省电

#### 系统关机
```
长按 POWER 键（2-3秒）→ 系统关机
```
- 自动保存所有设置
- 关闭背光和射频输出
- 完整的系统关机流程

详细信息请参考：
- `src/hw/POWER_QUICK_REFERENCE.md` - 快速参考
- `src/hw/POWER_CONTROL.md` - 详细说明
- `src/hw/POWER_USAGE_EXAMPLE.md` - 使用示例

---

## 配置文件

### 系统配置
- `/mnt/settings/options.yaml` - 用户选项
- `/mnt/settings/bands.yaml` - 波段配置
- `/mnt/settings/modes.yaml` - 模式配置
- `/mnt/settings/rf.yaml` - 射频配置

### 硬件配置
- `/sys/class/gpio/` - GPIO 控制
- `/dev/uio0` - FPGA 寄存器映射
- `/dev/iio:device0` - IIO 设备

---

## 故障排除

### 编译问题
```bash
# 清理构建目录
rm -rf build && mkdir build

# 检查依赖
cmake .. 2>&1 | grep "not found"

# 详细编译输出
make VERBOSE=1
```

### 运行时问题
```bash
# 查看系统日志
journalctl -u brass -f

# 查看内核日志
dmesg | tail

# 检查输入设备
ls -la /dev/input/

# 检查 GPIO
ls -la /sys/class/gpio/
```

### 常见问题

**Q: 显示屏无显示**
- 检查 framebuffer 设备: `ls /dev/fb*`
- 检查背光设备: `ls /sys/class/backlight/`

**Q: 音频无输出**
- 检查音频设备: `aplay -l`
- 检查音量设置

**Q: 控制无响应**
- 检查输入设备权限: `ls -la /dev/input/`
- 检查 GPIO 权限

**Q: 关机失败**
- 检查 root 权限
- 检查 `/sys/power/state` 可访问性

---

## 开发指南

### 代码规范
- 遵循 Linux 内核代码风格
- 使用 Doxygen 风格注释
- SPDX 许可证标识

### 添加新功能
1. 在相应目录创建模块文件
2. 更新 `CMakeLists.txt`
3. 在 `main.c` 中初始化
4. 在 `main_screen.c` 中添加事件处理
5. 更新文档

### 测试
```bash
# 单元测试（需要实现）
make test

# 集成测试
# 部署到硬件设备进行测试
```

---

## 贡献指南

欢迎贡献代码和改进建议！

1. Fork 本项目
2. 创建功能分支: `git checkout -b feature/your-feature`
3. 提交更改: `git commit -m 'Add some feature'`
4. 推送分支: `git push origin feature/your-feature`
5. 提交 Pull Request

### 贡献规范
- 遵循现有代码风格
- 添加适当的注释
- 更新相关文档
- 测试代码功能
- 提供清晰的提交信息

---

## 版本历史

### v0.6.0 (2025-02-16)
- ✅ 新增完整的电源管理功能
- ✅ 实现背光开关控制
- ✅ 实现系统关机功能
- ✅ 添加电源状态检测
- ✅ 完善关机流程
- ✅ 添加电源管理文档

### v0.5.x
- 数字模式优化
- 性能改进
- Bug 修复

### v0.4.x
- FT8 支持
- RTTY 支持
- Olivia 支持

### v0.3.x
- CW 功能完善
- 频谱显示优化
- 滤波器控制

### v0.2.x
- 基础 GUI 框架
- LVGL 集成
- 硬件抽象层

### v0.1.x
- 初始版本
- 基本频率控制

---

## 许可证

本项目采用 LGPL-2.1-or-later 许可证。

详见 [LICENSE](LICENSE) 文件。

## 作者

- **主要作者**: Belousov Oleg aka R1CBU
- **版权**: (c) 2022-2025

## 致谢

- LVGL 图形库
- Xilinx Zynq 平台支持
- 业余无线电社区

## 相关链接

- [项目主页](https://github.com/R1CBU/TRX-Brass)
- [问题跟踪](https://github.com/R1CBU/TRX-Brass/issues)
- [文档](https://github.com/R1CBU/TRX-Brass/wiki)

---

## 附录

### 技术术语
- **BPF**: Band-Pass Filter（带通滤波器）
- **LPF**: Low-Pass Filter（低通滤波器）
- **ATU**: Antenna Tuning Unit（天线调谐器）
- **SWR**: Standing Wave Ratio（驻波比）
- **FFT**: Fast Fourier Transform（快速傅里叶变换）
- **IIO**: Industrial I/O（工业 I/O 接口）
- **CW**: Continuous Wave（连续波/电报）
- **LSB/USB**: Lower/Upper Side Band（下/上边带）
- **RTTY**: Radio Teletype（无线电电传）
- **FT8**: Franke-Taylor design, 8-FSK（数字模式）

### 支持的频段
- HF: 160m, 80m, 40m, 30m, 20m, 17m, 15m, 12m, 10m, 6m
- VHF: 2m
- UHF: 70cm

### 支持的模式
- **SSB**: LSB, USB
- **CW**: CW, CWR
- **AM**: AM
- **FM**: NFM
- **数字**: RTTY, Olivia, FT8

---

**TRX Brass GUI - 业余无线电收发机图形用户界面**

*让业余无线电更简单、更强大！*

