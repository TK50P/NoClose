# NoClose
A Simple C++ Program to trigger Blue Screen of Death (BSoD) Easily.

# How to use

Run NoClose or NoClose_NonNMF.exe as administrator, then close the console window. It will trigger a BSoD.

# Requirements

- **NotMyFault** needs to be installed to `C:\Windows\Sysnative\NMF.exe`. (For NoClose.exe Only)
- **Windows Version**: Windows XP and later are supported.
- **Visual C++ 2010 Redistributable**: Required to run `NoClose.exe` and `NoClose_NonNMF.exe` on systems that don’t have Visual Studio 2010 installed. You can download the 2010 redistributable from the [Microsoft website](https://www.microsoft.com/en-us/download/details.aspx?id=26999).
- I often Recommended to use abbodi1406's [VisualCppRedist AIO](https://github.com/abbodi1406/vcredist/releases/tag/v0.85.0).

## For Building

- You need Visual Studio 2019 or later to build it. C++ compiler is required.
- If you’re trying to add other stop codes, look for `{ 0xF4 }`. You can change this to include additional stop codes like `{ 0xF4, 0xEA }`.

- Here’s an updated version of your README section with the note about the Visual C++ 2010 Redistributable requirement:

---

## NoClose

A Simple C++ Program to trigger Blue Screen of Death (BSoD) Easily.

### How to use

Run NoClose or NoClose_NonNMF.exe as administrator, then close the console window. It will trigger a BSoD.

### Requirements (For NoClose.exe, not for NoClose_NonNMF.exe)

- **NotMyFault** needs to be installed to `C:\Windows\Sysnative\NMF.exe`.
- **Windows Version**: Windows XP and later are supported. Older versions, like Windows 2000, will not work. This requirement applies only to `NoClose.exe` and does not affect `NoClose_NonNMF.exe`.
- **Visual C++ 2010 Redistributable**: Required to run `NoClose.exe` on systems that don’t have Visual Studio 2010 installed. You can download the 2010 redistributable from the [Microsoft website](https://aka.ms/vs/10/download/visual-cpp-redist).
- https://aka.ms/vs/10/download/visual-cpp-redist](https://www.microsoft.com/en-us/download/details.aspx?id=26999
- 

### For Building

- You need Visual Studio 2019 or later to build it. C++ compiler is required.
- If you’re trying to add other stop codes, look for `{ 0xF4 }`. You can change this to include additional stop codes like `{ 0xF4, 0xEA }`.

---

This should clarify the need for the Visual C++ 2010 Redistributable for users. Let me know if you need further changes!
