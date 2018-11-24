find_path(XAYAGAME_INCLUDE_DIR gamerpcserver.hpp NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/xayagame/")
find_library(XAYAGAME_LIBRARY xayagame NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(XAYAGAME DEFAULT_MSG XAYAGAME_LIBRARY XAYAGAME_INCLUDE_DIR)
