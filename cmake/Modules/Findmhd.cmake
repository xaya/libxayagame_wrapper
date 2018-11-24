find_path(MHD_INCLUDE_DIR microhttpd.h NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/")
find_library(MHD_LIBRARY microhttpd NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLOG DEFAULT_MSG MHD_LIBRARY MHD_INCLUDE_DIR)
