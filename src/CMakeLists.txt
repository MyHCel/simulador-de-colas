cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(main)

# Ejecutable
add_executable(main main.c)

# Librerias
add_subdirectory(ListaLigada)
target_link_libraries(main PUBLIC ListaLigada)
target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}")
