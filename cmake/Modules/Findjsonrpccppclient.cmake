find_path(JSONRPCCCP_CLIENT_INCLUDE_DIR client.h NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/jsonrpccpp/")
find_library(JSONRPCCCP_CLIENT_LIBRARY jsonrpccpp-client NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(JSONRPCCCP_CLIENT DEFAULT_MSG JSONRPCCCP_CLIENT_LIBRARY JSONRPCCCP_CLIENT_INCLUDE_DIR)
