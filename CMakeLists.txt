cmake_minimum_required(VERSION 3.0.0)
project(AVL VERSION 1.0)

# include(CTest)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(./include ./src ./tests)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest/
  GIT_TAG        release-1.10.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# add_compile_options(/Qspectre)


# This is the main executable
add_executable("${PROJECT_NAME}" ./src/main.cpp)

# Separate sanity checker g_test executable
add_executable("${PROJECT_NAME}_test" ./tests/AVLTreeSanityCheck.cpp)

enable_testing()
target_link_libraries("${PROJECT_NAME}_test" gtest_main)
include(GoogleTest)
gtest_discover_tests("${PROJECT_NAME}_test")