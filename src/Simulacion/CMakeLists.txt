# Archivos C
add_library(Simulacion sim.c)
target_link_libraries(Simulacion PUBLIC Clientes ListaLigada)

# Algo que no sé bien que hace, pero que es necesario :v
target_include_directories(Simulacion INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
