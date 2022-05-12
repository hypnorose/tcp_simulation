cmake_minimum_required(VERSION 3.0.0)
project(tcp_simulation VERSION 0.1.0)

include(CTest)
add_library(add src/add.cpp)

add_executable(tcp_simulation main.cpp)
target_link_libraries(tcp_simulation PRIVATE add)

add_executable(test1 tests/test1.cpp)
target_link_libraries(test1 PRIVATE add)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_test(NAME test COMMAND $<TARGET_FILE:test1>)