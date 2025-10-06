cmake_minimum_required(VERSION 3.14)
project(BitStringProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    BitString.cpp
)

set(HEADERS
    BitString.h
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(bitstring_demo
    ${SOURCES}
    main.cpp
)

add_executable(test_bitstring
    ${SOURCES}
    test_bitstring.cpp
)

target_link_libraries(test_bitstring
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_bitstring)
