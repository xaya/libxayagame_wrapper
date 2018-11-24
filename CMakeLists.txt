cmake_minimum_required(VERSION 3.12.3)
project (xayawrap LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS ON)

set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
add_definitions( -DGLOG_NO_ABBREVIATED_SEVERITIES)


set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS, true)


set(BASE_DIR ./)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(xayagame REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(glog REQUIRED)
find_package(gflags REQUIRED)
find_package(protobuf REQUIRED)
find_package(sqlite3 REQUIRED)
find_package(jsonrpccppcommon REQUIRED)
find_package(jsonrpccppclient REQUIRED)
find_package(jsonrpccppserver REQUIRED)
find_package(zmq REQUIRED)
find_package(lmdb REQUIRED)

include(FindProtobuf)
find_package(Protobuf REQUIRED)



get_filename_component(HEADERS src REALPATH)
include_directories(${LMDB_INCLUDE_DIR} ${ZMQ_INCLUDE_DIR} ${GFLAGS_INCLUDE_DIR} ${PROTOBUF_INCLUDE_DIR} ${SQLITE3_INCLUDE_DIR} ${JSONRPCCCPCLIENT_INCLUDE_DIR} ${JSONRPCCCP_CLIENT_LIBRARY} ${JSONRPCCCP_SERVER_LIBRARY} ${JSONRPCCCP_COMMON_LIBRARY}${JSONCPP_INCLUDE_DIR} ${XAYAGAME_INCLUDE_DIRS} ${GLOG_INCLUDE_DIRS} ${HEADERS})
set(SOURCE_FILES xayawrap.cpp)

add_library(xayawrap SHARED ${SOURCE_FILES})
add_library(xayagame STATIC IMPORTED)
add_library(jsoncpp STATIC IMPORTED)
add_library(glog STATIC IMPORTED)
add_library(gflags STATIC IMPORTED)
add_library(protobuf STATIC IMPORTED)
add_library(sqlite3 STATIC IMPORTED)
add_library(jsonrpccppcommon STATIC IMPORTED)
add_library(jsonrpccppclient STATIC IMPORTED)
add_library(jsonrpccppserver STATIC IMPORTED)
add_library(zmq STATIC IMPORTED)
add_library(lmdb STATIC IMPORTED)

target_include_directories (xayawrap PUBLIC ${BASE_DIR})


target_link_libraries( ${PROJECT_NAME} 
${XAYAGAME_LIBRARY}
${JSONCPP_LIBRARY}
${JSONRPCCCP_COMMON_LIBRARY}
${JSONRPCCCP_CLIENT_LIBRARY}
${JSONRPCCCP_SERVER_LIBRARY}
${GFLAGS_LIBRARY}
${PROTOBUF_LIBRARY}
${SQLITE3_LIBRARY}
${GLOG_LIBRARY}
${ZMQ_LIBRARY}
${LMDB_LIBRARY}
stdc++fs
)


install(TARGETS xayawrap DESTINATION /usr/TestXaya/TextXaya/TextXaya/bin/Debug)
