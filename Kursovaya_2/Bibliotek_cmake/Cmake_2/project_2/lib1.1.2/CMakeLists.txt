# Список исходных файлов для директории
set(SOURCES Eagle.cpp)
set(HEADERS Eagle.h)
include_directories(${CMAKE_SOURCE_DIR}/lib1.1)
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
add_library(Eagle SHARED ${SOURCES} ${HEADERS})

# Использовать библиотеку в Air.dll
target_link_libraries(Eagle PRIVATE Air Transport)
