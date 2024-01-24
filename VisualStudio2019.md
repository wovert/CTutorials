# Visual Studio 2019

## Windwos 10  

- 安装 Visual Studio Community 2019

- 使用 C++ 人桌面开发
  - 安全详细信息
    - **适用于最新v142 生成工具人C++ MFC (x86 和...)**
    - **Windows 10 SDK**
- **位置：更改**


## Window7

1. Windows 7 升级 Window7 SP1

http://www.catalog.update.microsoft.com/Search.aspx?q=kb976932


2. download Visual Studio 2019
https://visualstudio.microsoft.com/zh-hans/vs

3. .net 4.6
https://visualstudio.microsoft.com/zh-hans/vs/support/visual-studio-requires-net-framework-4-6-highter

4. .net 4.6 download
https://www.microsoft.com/zh-CN/download/details.aspx?id=48137

### 闪退配置的文件夹

```
C:\Program Fiels(x86)\Microsoft Visual Studio\Installer
setup.exe
vs_installer.exe
vs_installershell.exe
vs_community_xxxxxx.exe （安装文件）

更改以上4表文件属性的兼容模式
属性->兼容性->兼容模式(Windows7)


//kb4474419
http://www.catalog.update.microsft.com/Search.aspx?q=kb4474419

//kb4490528
http://www.catalog.update.microsoft.com/Search.aspx?q=KB4490628
```

## VS2019 下载速度太慢

1. 测试 DNS
  - baidu: DNS 查询
  - IP: download.visualstudio.microsoft.com
2. 修改 HOST

## Windows 10 download

https://www.microsoft.com/zh-cn/software-download/windows10

8G 以上的U盘

1. 进入BIOSU盘作为第一启动顺序
2. 密钥
3. 88GKV-6M776-46KPD-RFVCC-BXJ33

## 大量头文件缺失的修复方法

1. 删除操作系统安装的 SDK
2. 删除 VS2019
3. 重新安装 VS2019

## 云主机

- 2Core 4G 5M 带宽
- Ubuntu 18.04

## VS 2019 工具使用

- 解决方案名称
  - 项目名称1(login)
  - 项目名称2(game)


- 生成解决方案
- 重新生成解决方案
- 清理（清除额外信息，保留源代码）
- F5(调试)
- Ctrl+F5(不调试执行)

### 环境配置

- 下载开发字体：https://fonts.google.com/specimen/Source+Code+Pro

- 调试 -> 选项
  - 项目和解决方案
    - 位置
      - 项目位置
- 选择项目 -> 属性 -> 常规
  - C++ 语言标准 -> ISO C++ 17 标准
  - C 语言标砖 -> ISO C 17 标准
  - 生成
  - 重新生成

### 快捷键

- VS
  - 自动格式化：Ctrl+k, Ctrl+f
  - 注释代码：Ctrl+k, Ctrl+c
  - 取消注释代码：Ctrl+k, Ctrl+u
  - 设置断点：F9
  - 调试运行：F5
  - 不调试运行：Ctrl+F5
  - 编译不运行：Ctrl+Shift+b
  - 调试next: F10
  - 调试step: F11
  - 选中内容上下挪动：Alt + 上下箭头
- QT
  - 自动格式化代码：Ctrl+i
  - 注释/取消注释：Ctrl+/
  - 自动完成类函数定义：Alt+Enter
  - .h文件和对应.cpp文件切换：F4
  - 设置断点：F9
  - 调试运行：F5

## VS2019控制台输出中文乱码

1. 扩展 -> 管理扩展 -> Format on Save(科学上网)
2. 工具 -> 自定义 -> 命令 -> (菜单栏)文件 -> 新建 -> 文件 -> 高级保存选项 -> 确定
3. 高级保存选项 -> 关闭
4. 文件 -> 高级保存选项 -> Unicode(UTF-8 带签名) - 代码页 65001
5. 区域 -> 管理 -> 更改系统区域设置 -> 勾选 Beta版本: 使用Unicode UTF-8...

项目 -> 配置属性 -> C/C++ -> 命令行 -> /utf-8