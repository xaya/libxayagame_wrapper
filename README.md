# libxayagame_wrapper

You can compile libxayagame for Windows using cmake and MSYS2.

You may need to replace the file and folder paths in the various files and with those of your own environment. 

Precompiled binaries for Windows are available in the xayalib_unity respository [here](https://github.com/xaya/xayalib_unity). See [Downloads for developers](https://github.com/xaya/xaya_tutorials/wiki/Downloads) for more information. 

To compile the libxayagame wrapper for C#, you must use MSYS2 (Mingw-w64 64 bit). Use the following command:

    cmake . -G"MSYS Makefiles" -DCMAKE_INSTALL_PREFIX=$MINGW_PREFIX
    make
