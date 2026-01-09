# ⏱️ CronosQt — Minimalist Desktop Timer

CronosQt is a lightweight and highly customizable desktop timer built with **C++ and Qt 6**, designed for streamers, content creators, and anyone who needs a simple, always-on-top countdown or stopwatch.

---

## 🚀 Features

✔ **Start / Pause / Resume**
✔ **Reset**
✔ **Borderless window**
✔ **Always-on-top mode**
✔ **Optional transparency**
✔ **Movable by dragging with the mouse**
✔ **Configurable hotkeys**

### Hotkey Summary

| Key    | Action                                          |
| ------ | ----------------------------------------------- |
| **F1** | Close application                               |
| **F2** | Start / Pause / Resume timer                    |
| **F3** | Reset timer                                     |
| **F4** | Move window between screen corners              |
| **F5** | Open color picker to change label text color    |

---

## 🎨 Customization

CronosQt allows full visual customization, including:

* Text color (via color picker popup)
* Window background mode (solid or translucent)
* Adjustable position on screen
* Lightweight design suitable for OBS Browser Scene or screen overlays

---

## 📦 Download

Download the latest release:

👉 **[Click here to download](https://github.com/ikidoncc/cronosqt/releases/tag/v1.0.0-beta)**

---

## 🧩 Technologies Used

* **C++17**
* **Qt 6.x (Widgets)**
* QTimer
* QLabel
* QShortcut
* QColorDialog
* CMake

---

## 📁 Project Structure

```
CronosQt/
 ├─ main.cpp
 ├─ mainwindow.cpp
 ├─ mainwindow.h
 ├─ mainwindow.ui
 ├─ CMakeLists.txt
 └─ README.md
```

---

## 🔧 Build Instructions

### Requirements

* Qt 6.x (with Qt Creator or qmake)
* MSVC 2022 64-bit toolchain
* CMake 3.16 or newer

### Steps

1. Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/CronosQt.git
cd CronosQt
```

2. Configure CMake:

```bash
cmake -B build -S .
```

3. Build the project:

```bash
cmake --build build --config Release
```

4. Run:

```bash
./build/Release/CronosQt.exe
```

---

## 📦 Packaging for Distribution (Windows)

To distribute the application, run:

```bash
windeployqt CronosQt.exe
```

This will generate all required Qt DLLs and plugin folders, such as:

* Qt6Core.dll
* Qt6Gui.dll
* Qt6Widgets.dll
* platforms/
* styles/
* imageformats/

Copy everything into a single folder and share it as a portable ZIP or create an installer.

---

## ⭐ License

This project is licensed under the [**MIT License**](https://github.com/ikidoncc/cronosqt/blob/main/LICENSE).
You are free to use, modify, and distribute it.
