find_path(JSONRPCCCP_COMMON_INCLUDE_DIR server.h NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/jsonrpccpp/")
find_library(JSONRPCCCP_COMMON_LIBRARY jsonrpccpp-common NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(JSONRPCCCP_COMMON DEFAULT_MSG JSONRPCCCP_COMMON_LIBRARY JSONRPCCCP_COMMON_INCLUDE_DIR)
