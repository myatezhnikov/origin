# Список исходных файлов для директории 
set(SOURCES Functions.cpp)
set(HEADERS Functions.h)
include_directories(${CMAKE_SOURCE_DIR}/lib_racers)
include_directories(${CMAKE_SOURCE_DIR}/lib1)
include_directories(${CMAKE_SOURCE_DIR}/app)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 

set(LIBRARIES
Air
All_terrain_boots
Broom
Camel
Centaur
Eagle
Ground
Magic_Carpet
Speedy_Camel
Transport
Racers
)



# Создание библиотеки из файлов в директории
add_library(Functions SHARED ${SOURCES} ${HEADERS})

# Использовать библиотеку в racing.exe
target_link_libraries(Functions ${LIBRARIES})
target_link_libraries(Racing Functions Racers)
