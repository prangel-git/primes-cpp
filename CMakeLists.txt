cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(primesSieve)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${PROJECT_NAME} include)

add_subdirectory(include)

target_link_libraries(${PROJECT_NAME} primes)