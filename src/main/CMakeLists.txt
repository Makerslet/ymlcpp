####################################################################################################
### Yandex music library
### library based on Qt project
### (c) 2019 - Valery Oshuev - oshuev.valery@yandex.ru
####################################################################################################

set(TARGET_NAME ymlcpp)

file(GLOB_RECURSE TARGET_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${TARGET_NAME})
target_sources(${TARGET_NAME} PRIVATE ${TARGET_SRC})

target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Qt5::Network)

