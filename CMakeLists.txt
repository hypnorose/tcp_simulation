cmake_minimum_required(VERSION 3.14)
project(tcp_simulation VERSION 0.1.0)

#add_library(add src/add.cpp)
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tcp_simulation main.cpp)
#target_link_libraries(tcp_simulation PRIVATE add)

## TESTS ##
 
enable_testing()
add_executable(test1 tests/test1.cpp)
target_link_libraries(
  test1
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(test1)

#target_link_libraries(test1 PRIVATE add)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
