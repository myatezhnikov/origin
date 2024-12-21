# Список исходных файлов для директории
set(SOURCES Speedy_Camel.cpp)
set(HEADERS Speedy_Camel.h)
include_directories(${CMAKE_SOURCE_DIR}/lib1.2)
include_directories(
/lib_func
/lib_racers
/lib1
/lib1.1
/lib1.1.1
/lib1.1.2
/lib1.1.3
/lib1.2
/lib1.2.1
/lib1.2.2
/lib1.2.3
/lib1.2.4
)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 

# Создание библиотеки из файлов в директории
add_library(Speedy_Camel SHARED ${SOURCES} ${HEADERS})

# Использовать библиотеку в Ground.dll
target_link_libraries(Speedy_Camel PRIVATE Ground Transport)
