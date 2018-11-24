find_path(JSONRPCCCP_SERVER_INCLUDE_DIR server.h NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/jsonrpccpp/")
find_library(JSONRPCCCP_SERVER_LIBRARY jsonrpccpp-server NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(JSONRPCCCP_SERVER DEFAULT_MSG JSONRPCCCP_SERVER_LIBRARY JSONRPCCCP_SERVER_INCLUDE_DIR)
