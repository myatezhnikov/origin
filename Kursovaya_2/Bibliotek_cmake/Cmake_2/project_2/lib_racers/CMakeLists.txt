# Список исходных файлов для директории
set(SOURCES Racers.cpp)
set(HEADERS Racers.h)
include_directories(${CMAKE_SOURCE_DIR}/lib_func)
include_directories(${CMAKE_SOURCE_DIR}/app)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 

# Создание библиотеки из файлов в директории
add_library(Racers SHARED ${SOURCES} ${HEADERS})

# Использовать библиотеку в Functions.dll
#target_link_libraries(Functions PRIVATE Racers)
#target_link_libraries(Racing PRIVATE Racers)