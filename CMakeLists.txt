cmake_minimum_required(VERSION 3.0.0)
project(AVL VERSION 1.0)

# include(CTest)
# enable_testing()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(./include ./src)

# add_compile_options(/Qspectre)
add_executable("${PROJECT_NAME}" ./src/main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
