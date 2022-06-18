cmake_minimum_required(VERSION 3.20)

Project(CoreGraphics)

file(GLOB_RECURSE CORE_SOURCE src/*.hpp src/*cpp)

add_library(${PROJECT_NAME} ${CORE_SOURCE})

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

file(GLOB_RECURSE CORE_SOURCE src/Core/*.cpp src/Core/*.hpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC glfw
    PUBLIC glad::glad
    PUBLIC imgui::imgui
    PUBLIC spdlog::spdlog spdlog::spdlog_header_only
    PUBLIC glm::glm
)

find_path(STB_INCLUDE_DIRS "stb_c_lexer.h")
target_include_directories(${PROJECT_NAME}
    PUBLIC ${STB_INCLUDE_DIRS}
    PUBLIC src/
)