# NoClose

A simple C++ program to trigger a native Blue Screen of Death (BSOD) easily.

## How to use

Run `NoClose.exe` as administrator, then attempt to close the console window. It will instantly trigger a native BSoD.

*Note: You can safely close the window without crashing by pressing the `T` + `Z` + `H` keys simultaneously.*

## Requirements

* **Windows Version:** *It supports Windows NT 4.0 as minimum!!!* Full compatibility with the entire Windows NT lineage (NT 4.0, 2000, XP, and up).
* **Dependencies:** None. The application is completely standalone and zero-dependency. No external tools like NotMyFault or Visual C++ Redistributable packages are required.

## For Building

* You can use the **MSYS2 MinGW-w64 G++ (32-bit)** toolchain to compile the standalone binary.
* Open the **MSYS2 MinGW x86** terminal, navigate to the folder containing your source file, and run:

```bash
g++ main.cpp -o NoClose.exe -static -static-libgcc -Wl,--subsystem,console:4.0 -luser32 -ladvapi32
```
