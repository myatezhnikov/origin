# Список исходных файлов для директории
set(SOURCES Broom.cpp)
set(HEADERS Broom.h)
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
add_library(Broom SHARED ${SOURCES} ${HEADERS})

# зависимости
target_link_libraries(Broom PRIVATE Air Transport)
