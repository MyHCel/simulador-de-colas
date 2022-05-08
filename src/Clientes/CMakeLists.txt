# Archivos C
add_library(Clientes bruh.c cliente.c cajero.c)
target_link_libraries(Clientes PUBLIC ListaLigada)

# Algo que no sé bien que hace, pero que es necesario :v
target_include_directories(Clientes INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
