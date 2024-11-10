# NoClose
A Simple C++ Program to trigger Blue Screen of Death (BSoD) Easily.

# How to use
Run NoClose or NoClose_NonNMF.exe **as admininistrator**. then close the console window. it will trigger BSoD.

# Requirements (For NoClose.exe, not for NoClose_NonNMF.exe)
You will need NotMyFault to be installed to `C:\Windows\Sysnative\NMF.exe`.
<br> For NoClose.exe, You'll need Windows XP and later. earlier Version, such as Windows 2000 will not work.
This affects for `NoClose.exe` only. Not affected for `NoClose_NonNMF.exe`.

## For Building
You need Visual Studio 2019 and later to build it. C++ Compiler Required.
<br> If you're trying to add other stop codes, Look for `{ 0xF4 }`, if you are adding random multiple stop code, change like `{ 0xF4, 0xEA }`.
