####################################################################################################
### Yandex music library
### library based on Qt project
### (c) 2019 - Valery Oshuev - oshuev.valery@yandex.ru
####################################################################################################

cmake_minimum_required(VERSION 3.11)
project(ymlcpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON) # включаем автоматическую генерацию moc-файлов qt

find_package(Qt5 COMPONENTS Core Network REQUIRED CONFIG)

add_subdirectory(src)

