# mock-stock-rag-advisor

A minimal C++/Python project using the [Crow](https://github.com/CrowCpp/crow) microframework, with dependencies managed via [vcpkg](https://github.com/microsoft/vcpkg) and built using CMake.

This project emulates a stock platform and is written in C++, leveraging Boost and modern CMake practices.
Users buy and sell mock stocks.
A helper Python function scrapes the web for real world performance of a stock
This information is fed into a rag pipeline, relevent bits of information is used to query an LLM for stock advice

---

## ✅ Prerequisites

Before getting started, make sure you have the following installed on your system:

- [CMake](https://cmake.org/download/) (version 3.15+ recommended)
- A C++17-compatible compiler (e.g., MSVC, GCC, or Clang)
- Git
- [vcpkg](https://github.com/microsoft/vcpkg)

---

## 📦 Step-by-Step Installation Guide

1. Install CMAKE   
2. Install crow, boost using vcpkg  
3. Create a build directory within crow_project  
4. Change the file locations for vcpkg.cmake in run.bat and CMakeLists.txt to that on your system  
5. Move run.bat to the build directory  
6. cd into build  
7. .\run.bat  
