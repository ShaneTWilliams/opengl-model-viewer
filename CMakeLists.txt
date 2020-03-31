cmake_minimum_required(VERSION 3.10)
project(opengl-model-viewer)

set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "src/*.cpp") 
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/assimp/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/stbimage/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/glm/include)

add_executable(${PROJECT_NAME} ${SOURCES})
LINK_DIRECTORIES(/usr/local/lib)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/glfw/lib/libglfw3.a)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/assimp/lib/libassimp.4.1.0.dylib)

target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
target_link_libraries(${PROJECT_NAME} "-framework IOKit")
target_link_libraries(${PROJECT_NAME} "-framework CoreVideo")
target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
