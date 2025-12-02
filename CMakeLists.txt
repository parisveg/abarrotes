cmake_minimum_required(VERSION 4.0)
project(abarrotes)

set(CMAKE_CXX_STANDARD 20)

add_executable(abarrotes main.cpp
        helper.cpp
        helper.h
        Inventario.cpp
        Inventario.h
        Producto.cpp
        Producto.h
        Lote.cpp
        Lote.h)
