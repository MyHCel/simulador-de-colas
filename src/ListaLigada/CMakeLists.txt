# Archivos C
add_library(ListaLigada nodo.c lista.c)

# Algo que no sé bien que hace, pero que es necesario :v
target_include_directories(ListaLigada INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
