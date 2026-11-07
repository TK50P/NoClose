# NoClose

A simple C++ program to trigger a native Blue Screen of Death (BSOD) easily.

## How to use

Run `NoClose.exe` as administrator, then attempt to close the console window. It will instantly trigger a native BSoD.

*Note: You can safely close the window without crashing by pressing the `T` + `Z` + `H` keys simultaneously.*

## Requirements

* **Windows Version:** Requires Windows 2000, XP, and later. Full native compatibility with modern operating systems (Windows XP up to Windows 11).
* **Dependencies:** None. The application is completely standalone and zero-dependency. No external tools like NotMyFault or Visual C++ Redistributable packages are required.

## For Building

* You can use the **MSYS2 MinGW-w64 G++ (32-bit)** toolchain to compile the standalone binary.
* Open the **MSYS2 MinGW x86** terminal, navigate to the folder containing your source file, and run:

```bash
g++ main.cpp -o NoClose.exe -static -static-libgcc -luser32 -ladvapi32
```
