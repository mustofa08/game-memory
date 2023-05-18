cmake_minimum_required(VERSION 3.0.0)
project(Game)

set(SFML_DIR "C:\Users\Mustofa\OneDrive - Institut Teknologi Sepuluh Nopember\Dokumen\SFML-2.5.1")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(Game main.cpp)
target_link_libraries(Game sfml-graphics)
