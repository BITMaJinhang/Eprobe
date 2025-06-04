# [Eprobe] Engineering Files Repository  

This repository contains engineering files for a multi-platform system, organized by functional modules to facilitate project management and collaboration.  


## Directory Structure and Descriptions  

### 1. Hardware/  
- **Content**: Hardware design engineering files  
- **Includes**:  
  - BOM — Bill of Materials (component models and quantities)  
  - PCB — PCB design diagrams  
  - Schematics — Circuit schematic diagrams  
  - 3DShell — 3D casing source files  
- **Purpose**: Reference for hardware development and manufacturing  


### 2. BLE_CH582/  
- **Content**: CH582 coprocessor firmware project  
- **Includes**:  
  - APP/ — Core functional code directory  
  - All_EVT.zip/ — All functional examples for CH58x, including firmware libraries  
- **Development Tool**: MounRiver Studio  


### 3. MCU_STM32/  
- **Content**: STM32 main processor firmware project  
- **Includes**:  
  - EprobeSTAT_V4.zip — STM32CubeIDE full project file (zipped)  
  - Core/ — Core functional code directory  
- **Development Tool**: STM32CubeIDE  


### 4. MatLabApp/  
- **Content**: MATLAB PC application project  
- **Includes**:  
  - EprobeUART.mlapp — MATLAB App Designer project file  
  - code.m — Source code for the project  
- **Development Tool**: MATLAB R20A  


### 5. MobileAPP/  
- **Content**: Mobile application project  
- **Includes**:  
  - src/ — Application source code (Vue.js)  
  - quasar.config.js — Quasar framework configuration  
  - package.json — Dependency management file  
- **Technology Stack**: Quasar + Capacitor  


## Engineering File Organization Principles  
1. Each folder corresponds to an independent functional module with complete project configurations.  
2. Standard project file formats for each platform are adopted.  
3. Hardware and software files are separated to enable collaborative development.  


## Quick Access  
- Hardware design: Directly view PDF diagrams in `Hardware/`.  
- Firmware development: Open project files via the corresponding IDE.  
- PC application debugging: Run projects as required by each platform tool.  
