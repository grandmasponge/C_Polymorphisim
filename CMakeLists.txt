cmake_minimum_required(VERSION 3.29)
project(c_class C)


set(CMAKE_C_STANDARD 11)


add_executable(exec src/main.c)


target_include_directories(exec PRIVATE ${CMAKE_SOURCE_DIR}/include)
