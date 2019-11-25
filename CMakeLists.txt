####################################################################################################
### Yandex music library
### library based on Qt project
### (c) 2019 - Valery Oshuev - oshuev.valery@yandex.ru
####################################################################################################

cmake_minimum_required(VERSION 3.11)
project(ymlcpp VERSION 1.0 LANGUAGES CXX)

set(TARGET_NAME ymlcpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON) # включаем автоматическую генерацию moc-файлов qt

find_package(Qt5 COMPONENTS Core Network REQUIRED CONFIG)

set(PROJECT_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE TARGET_HDR ${PROJECT_INCLUDES}/*.h)
file(GLOB_RECURSE TARGET_SRC ${PROJECT_SOURCES}/*.cpp)

add_library(${TARGET_NAME} SHARED ${TARGET_SRC} ${TARGET_HDR})

target_sources(${TARGET_NAME} PUBLIC ${TARGET_SRC} PUBLIC ${TARGET_HDR})
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Qt5::Network)

target_include_directories(${TARGET_NAME} PUBLIC include)
