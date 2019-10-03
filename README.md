# libxayagame Wrapper for C#

You can compile libxayagame and a C# wrapper for it for Windows using cmake and MSYS2. 

You may need to replace the file and folder paths in the various files and with those of your own environment. 

Precompiled binaries for Windows are available in the [xayalib_unity repository here](https://github.com/xaya/xayalib_unity) and in the [XAYA_tutorial_code repository here](https://github.com/xaya/XAYA_tutorial_code). See [Downloads for developers](https://github.com/xaya/xaya_tutorials/wiki/Downloads) for more information. 

**Note:** You must have already compiled libxayagame as per the instructions in the [Compile libxayagame in Windows](https://github.com/xaya/xaya_tutorials/wiki/How-to-Compile-libxayagame-in-Windows) tutorial before you compile the C# wrapper.

## Compiling the Wrapper

To compile the libxayagame wrapper for C#, you must use MSYS2 (Mingw-w64 64 bit). Use the following commands to compile the wrapper:

    cmake . -G"MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=$MINGW_PREFIX
    make

This will create the `libxayawrap.dll` file. Copy this file into your C# (or .NET) project along with all other libxayagame dependencies. You can find the list of dependencies [here](https://github.com/xaya/XAYA_tutorial_code/blob/master/Hello-World/Hello-World-C%2B%2B/Required%20dependencies.txt). 


