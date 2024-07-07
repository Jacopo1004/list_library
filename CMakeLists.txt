cmake_minimum_required(VERSION 3.10)

project(list_library)

# Definisci le directory delle librerie
set(SUB_DIRS "elemtype" "list" "main_list")

# Itera attraverso ogni sottodirectory
FOREACH(subdir ${SUB_DIRS})
    # Ottieni i file sorgente e header della sottodirectory
    file(GLOB sources "${subdir}/*.c")
    file(GLOB headers "${subdir}/*.h")

    # Ottieni il nome del target (trasformato in maiuscolo)
    string(TOUPPER ${subdir} target_name_uppercase)

    # Aggiungi la libreria corrente
    add_library(${target_name_uppercase} STATIC ${sources} ${headers})

    # Specifica le directory di inclusione per la libreria corrente
    target_include_directories(${target_name_uppercase} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
ENDFOREACH

# Link della libreria `elemtype` a `list`
target_link_libraries(list PRIVATE elemtype)

# Link delle librerie `list` e `elemtype` a `main_list`
target_link_libraries(main_list PRIVATE list elemtype)