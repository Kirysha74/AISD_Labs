cmake_minimum_required(VERSION 3.11)

project(vector CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)

    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)


    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()


include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(vector SHARED
    "include/vector/vector.h"
    "src/vector.cc"
)

add_executable(vector-tests
    "test/vector_tests.cc"
)

target_include_directories(vector PUBLIC "include")
target_link_libraries(vector-tests vector GTest::gtest_main)
