set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 
# Добавление директории 
include_directories(..)


# Список исходных файлов
set(PROJECTNAME Racing)
set(SOURCES 
main.cpp
)
set(LIBRARIES
Functions
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


add_executable(${PROJECTNAME} ${SOURCES})
#target_link_libraries(${PROJECTNAME} ${LIBRARIES})


