cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)

# ������� ���� � ������������� ���������� libpqxx
include_directories("C:/Program Files (x86)/libpqxx/include")

# ������� ���� � ����������� libpqxx � PostgreSQL
link_directories("C:/Program Files (x86)/libpqxx/lib")  # ���� � ����� � .lib �������
link_directories("C:/Program Files/PostgreSQL/17/lib")  # ���� � ����� � .lib �������

# ������� ����� PQXX
find_package(libpqxx REQUIRED)

# ������� ����� PostgreSQL
find_package(PostgreSQL REQUIRED)

# �������� ����������� ����
add_executable(MyProject main.cpp)

# ������� ���������� ��������� � ���������� � ������������
target_include_directories(MyProject PRIVATE ${libpqxx_INCLUDE_DIRS} ${PostgreSQL_INCLUDE_DIRS})
target_link_libraries(MyProject PRIVATE pqxx ${PostgreSQL_LIBRARIES} Ws2_32.lib)