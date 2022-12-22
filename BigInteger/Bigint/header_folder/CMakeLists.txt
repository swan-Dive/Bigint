project(BigIntegerHeader)
add_library(BigInteger BigInt.cpp header.hpp)
target_include_directories(BigInteger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
