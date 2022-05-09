cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(main)

# Ejecutable
add_executable(main main.c)

# Librerias
add_subdirectory(ListaLigada)
add_subdirectory(Clientes)
add_subdirectory(Simulacion)
target_link_libraries(main PUBLIC ListaLigada Clientes Simulacion)
target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}")
