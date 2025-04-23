cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)

# Укажите путь к установленной библиотеке libpqxx
include_directories("C:/Program Files (x86)/libpqxx/include")

# Укажите путь к библиотекам libpqxx и PostgreSQL
link_directories("C:/Program Files (x86)/libpqxx/lib")  # Путь к папке с .lib файлами
link_directories("C:/Program Files/PostgreSQL/17/lib")  # Путь к папке с .lib файлами

# Найдите пакет PQXX
find_package(libpqxx REQUIRED)

# Найдите пакет PostgreSQL
find_package(PostgreSQL REQUIRED)

# Добавьте исполняемый файл
add_executable(MyProject main.cpp)

# Укажите директории включения и связывание с библиотеками
target_include_directories(MyProject PRIVATE ${libpqxx_INCLUDE_DIRS} ${PostgreSQL_INCLUDE_DIRS})
target_link_libraries(MyProject PRIVATE pqxx ${PostgreSQL_LIBRARIES} Ws2_32.lib)