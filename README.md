<div align="center">
  <h1>SLK SteamTools</h1>

  <p>
    <strong>Core Steam Client Instrumentation & Runtime Tooling for SLK Unlocker</strong>
  </p>

  <p>
    <img src="https://img.shields.io/badge/C%2B%2B-20%2B-2ea44f?logo=cplusplus&logoColor=white" alt="C++ 20+">
    <img src="https://img.shields.io/badge/CMake-3.20%2B-2ea44f?logo=cmake&logoColor=white" alt="CMake 3.20+">
    <img src="https://img.shields.io/badge/Windows-only-d73a49?logo=windows&logoColor=white" alt="Windows only">
    <img src="https://img.shields.io/badge/Release-v1.0.5%20SLK-blue?logo=github&logoColor=white" alt="Release">
  </p>
</div>

---

## Overview

**SLK SteamTools** is the high-performance native C++ core library powering Steam client interactions inside the **SLK Unlocker** ecosystem. It provides real-time client hooking, memory pattern resolution, automated signature synchronisation via `DrxmReal/slk-steam-monitor`, dynamic DLC & inventory unlocking, and Lua configuration hot-reloading.

---

## Key Features

### 1. Dynamic Pattern & Signature Engine
- SHA-256 binary validation on every Steam launch for `steamclient64.dll` and `steamui.dll`.
- Automated remote signature retrieval directly from the official SLK Steam Monitor mirror:
  - **Primary Mirror:** `https://raw.githubusercontent.com/DrxmReal/slk-steam-monitor/pattern/...`
  - **CDN Fallback:** `https://fast.jsdelivr.net/gh/DrxmReal/slk-steam-monitor@pattern/...`
  - **Local Persistence Cache:** `<Steam>\opensteamtool\pattern\<subdir>\<sha256>.toml`
- Instant notification and Discord support links if Steam pushes an uncatalogued update.

### 2. Core Unlocks & Library Emulation
- Real-time DLC and unowned app unlock integration.
- Automated depot decryption key injection from Lua configurations.
- Manifest downloads and offline binding mechanisms to protect against unwanted game overwrites.
- Steam Family Sharing restriction bypass for shared titles added via Lua.

### 3. Denuvo & SteamStub Compatibility
- Built-in ticket caching and local ticket forging mechanisms via Steam ConfigStore off-by-four parsing.
- Support for `setAppTicket(appid, "hex")` and `setETicket(appid, "hex")` credentials.
- Third-party CD-Key response synthesiser preventing the "Updating product key" hang on titles requiring activation.

### 4. Lua Hot-Reloading
- Directory watchers monitor all `.lua` configs in real time.
- Adding, editing, or removing configs triggers instant runtime re-indexing without restarting Steam or toggling offline mode.

---

## Configuration

Configuration is managed via `opensteamtool.toml` located in your root Steam installation directory:

```toml
[general]
enabled = true

[remote]
# Custom mirror override (defaults to DrxmReal/slk-steam-monitor)
url_template = "https://raw.githubusercontent.com/DrxmReal/slk-steam-monitor/{channel}/{component}/{sha256}.toml"

[log]
level = "info"
```

---

## Build Instructions

### Prerequisites
- Windows 10/11 x64
- Visual Studio 2022 (MSVC v143 toolchain with C++20 support)
- CMake 3.20+
- Ninja Build System (optional, recommended)

### Quick Build
```powershell
.\build.bat
```

Compiled binaries will be generated in:
- `build/Release/OpenSteamTool.dll`
- `build/Release/dwmapi.dll`
- `build/Release/xinput1_4.dll`

---

## Ecosystem & Integration

SLK SteamTools is integrated out-of-the-box with:
- **[SLK Unlocker](https://github.com/DrxmReal/SLK-Unlocker)** — The primary desktop GUI application.
- **[SLK Steam Monitor](https://github.com/DrxmReal/slk-steam-monitor)** — The automated Steam client binary analysis and signature tracker.

---

## Contributors & Maintainers

- **Lead Developer & Maintainer:** **Dr4m** ([@DrxmReal](https://github.com/DrxmReal))
- **Core Team:** **SLK Team**
- **Community & Support:** [Discord Community](https://discord.gg/FPNGs3NszJ)

---

## Disclaimer
SLK SteamTools is developed for personal research, educational analysis, and game preservation purposes. Users are responsible for complying with local regulations and terms of service.
