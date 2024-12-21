# Список исходных файлов для директории
set(SOURCES Air.cpp)
set(HEADERS Air.h)
include_directories(${CMAKE_SOURCE_DIR}/lib1)
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
add_library(Air SHARED ${SOURCES} ${HEADERS})

# Использовать библиотеку в Transport.dll
target_link_libraries(Air PRIVATE Transport)
