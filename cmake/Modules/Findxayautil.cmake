find_path(XAYAUTIL_INCLUDE_DIR uint256.hpp NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/xayautil//")
find_library(XAYAUTIL_LIBRARY xayautil NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(XAYAUTIL DEFAULT_MSG XAYAUTIL_LIBRARY XAYAUTIL_INCLUDE_DIR)
