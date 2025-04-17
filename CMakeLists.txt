cmake_minimum_required(VERSION 3.12)
project(crow_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Dell/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

find_package(Boost REQUIRED)
find_package(Crow CONFIG REQUIRED)

add_executable(crow_project main.cpp controller.hpp model.hpp view.hpp)
target_link_libraries(crow_project PRIVATE Crow::Crow Boost::boost)
