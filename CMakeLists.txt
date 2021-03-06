cmake_minimum_required(VERSION 3.13)
project(janken C)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set(CMAKE_C_CLANG_TIDY clang-tidy -header-filter=.,-checks=-*,readability-*)

# Debug Mode
if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo" OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(ENABLE_SANITIZER_ADDRESS:BOOL=True)
    set(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR:BOOL=True)
    set(ENABLE_CPPCHECK:BOOL=True)

    set(COMPILER_WARNING_FLAGS "-Wall -Wextra -Wshadow -Wpedantic -Werror -Wcast-align -Wunused -Wconversion -Wmisleading-indentation -Wnull-dereference -Wsign-conversion -Wdouble-promotion -Wformat=2")
    set(COMPILER_WARNING_FLAGS_BLACKLIST "-Wno-padded")
    set(COMPILER_WARNING_FLAGS_CLANG "") # -Wlifetime")
    set(COMPILER_WARNING_FLAGS_GNU "-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast")

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_WARNING_FLAGS} ${COMPILER_WARNING_FLAGS_BLACKLIST} -g -fno-omit-frame-pointer -fsanitize=address -fno-exceptions")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_WARNING_FLAGS_GNU} -static-libasan")
    endif()
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_WARNING_FLAGS_CLANG}")
    endif()
endif()

# Release Mode
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")
endif()

include_directories(src/janken)

file(GLOB_RECURSE janken_sources ${PROJECT_SOURCE_DIR}/src/*.c)

set(SRC ${janken_sources})

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
