find_path(OPENSSL_INCLUDE_DIR opensslv.h NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/include/openssl/")
find_library(OPENSSL_LIBRARY libcrypto NO_CMAKE_FIND_ROOT_PATH NO_DEFAULT_PATH PATHS "C:/msys64/mingw64/lib/")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OPENSSL DEFAULT_MSG OPENSSL_LIBRARY OPENSSL_INCLUDE_DIR)
