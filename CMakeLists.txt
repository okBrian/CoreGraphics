cmake_minimum_required(VERSION 3.20)

Project(CoreGraphics)

file(GLOB_RECURSE CORE_SOURCE src/*.hpp src/*cpp)

add_subdirectory(vendor/glad/)
add_subdirectory(vendor/)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glm)

add_library(${PROJECT_NAME} ${CORE_SOURCE}) 

file(GLOB_RECURSE CORE_SOURCE src/Core/*.cpp src/Core/*.hpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC glad 
    PUBLIC imgui
    PUBLIC spdlog
    PUBLIC glm
)    

target_include_directories(${PROJECT_NAME}
    PUBLIC src/
    PUBLIC src/OpenGL 
    PUBLIC src/Window/
    PUBLIC src/vendor/stb/
) 