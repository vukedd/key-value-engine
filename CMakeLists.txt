cmake_minimum_required(VERSION 3.20)
project(kvengine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main main.cpp)
add_library(kvengine src/kv_store.cpp)

target_include_directories(kvengine PUBLIC include)

target_link_libraries(main PRIVATE kvengine)

target_compile_options(kvengine PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)