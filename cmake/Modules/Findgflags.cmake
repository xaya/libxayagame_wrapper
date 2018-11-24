find_path(GFLAGS_INCLUDE_DIR gflags.h NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/gflags/")
find_library(GFLAGS_LIBRARY gflags NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GFLAGS DEFAULT_MSG GFLAGS_LIBRARY GFLAGS_INCLUDE_DIR)
