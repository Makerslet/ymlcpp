####################################################################################################
### Yandex music library
### library based on Qt project
### (c) 2019 - Valery Oshuev - oshuev.valery@yandex.ru
####################################################################################################

set(TARGET_NAME ymlcpp)

file(GLOB_RECURSE TARGET_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE TARGET_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} 
		PUBLIC ${TARGET_SRC}
		PUBLIC ${TARGET_HDR})

target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Qt5::Network Qt5::Xml)

