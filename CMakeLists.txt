cmake_minimum_required(VERSION 3.27)
project(ASD_EXAM)

set(CMAKE_C_STANDARD 11)

#[[MAIN per Casual_Exercises Folder]]
add_executable(dividi_con_riferimento Casual_Exercises/dividi_con_riferimento.cpp)
add_executable(2_anfore Casual_Exercises/2_anfore.cpp)
add_executable(libro Casual_Exercises/libro.cpp)
add_executable(point Casual_Exercises/point.cpp)
add_executable(radice_slide Casual_Exercises/radice_slide.cpp)
add_executable(file_exercise Casual_Exercises/file_exercise.cpp)
add_executable(sommatoria_templata Casual_Exercises/sommatoria_templata.cpp)
add_executable(Stack_generico_template Casual_Exercises/Stack_Generico_Template/Stack_generico_template.cpp)



#[[MAIN per ABR Folder]]
add_executable(main ABR/ABR_PANICO/main.cpp)
add_executable(main2 ABR/main.cpp)

#[[MAIN per Algoritmi_Prova Folder]]
add_executable(Dijkstra_BellmanFord_Kruskal_GRAPH Algoritmi_Prova/Dijkstra_BellmanFord_Kruskal_GRAPH.cpp)
add_executable(greedy_activity_selector Algoritmi_Prova/greedy_activity_selector.cpp)
add_executable(hashtable_exercise Algoritmi_Prova/hashtable_exercise.cpp)
add_executable(huffman_codifica_decodifica Algoritmi_Prova/huffman_codifica_decodifica.cpp)
add_executable(LCS_exercise Algoritmi_Prova/LCS_exercise.cpp)
add_executable(recursive_BFS_exercise Algoritmi_Prova/recursive_BFS_exercise.cpp)
add_executable(zaino_01_Frazionario_exercise Algoritmi_Prova/zaino_01_Frazionario_exercise.cpp)
add_executable(heap_exercise Algoritmi_Prova/Min_Heap/heap_exercise.cpp)






