cmake_minimum_required(VERSION 3.20)

# name the project and define the language for which compiler CMake is looking for
project(kvengine LANGUAGES CXX)

# define cpp version
set(CMAKE_CXX_STANDARD 20)

# if cpp20 isn't available refuse to start
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# use standard cpp only
set(CMAKE_CXX_EXTENSIONS OFF)

# build runnable program target from this file
add_executable(main main.cpp)

# build a reusable library target from this file
add_library(kvengine src/kv_store.cpp)

# tells the compiler to look into 'include' directory when some file includes kv/kv_store - #include "kv/kv_store.h"
target_include_directories(kvengine PUBLIC include)

# links the engines lib compiled code to main, so when main calls something like store store.put("","") the call is
# actually connected to a real implementation
target_link_libraries(main PRIVATE kvengine)

# adds compiling arguments, Wall - shows common warnings, Wextra - show uncommon warnings, Wpedantic - checks if the code
# is standard cpp or does it rely on something a special GCC allows.
target_compile_options(kvengine PRIVATE -Wall -Wextra -Wpedantic)

# -||-
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)