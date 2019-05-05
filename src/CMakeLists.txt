set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# SDL Library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Gather library sources and headers
FILE(GLOB PONG_HEADERS ${SRC_DIR}/*.h)
FILE(GLOB PONG_SOURCES ${SRC_DIR}/*.cpp)
LIST(REMOVE_ITEM PONG_SOURCES ${SRC_DIR}/main.cpp) # Remove main.cpp

#Add library
add_library(lib-pong ${PONG_SOURCES} ${PONG_HEADERS})

# Executable
add_executable(pong WIN32 ${SRC_DIR}/main.cpp)

# Link dependencies
target_link_libraries(pong lib-pong)
target_link_libraries(pong ${SDL2_LIBRARIES})
