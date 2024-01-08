cmake_minimum_required(VERSION 3.20)
project(imgui)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
add_subdirectory(glfw)

add_library(imgui
  imgui/imgui.cpp
  imgui/imgui.h
  imgui/imconfig.h
  imgui/imgui_demo.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_internal.h
  imgui/imgui_tables.cpp
  imgui/imgui_widgets.cpp
  imgui/imstb_rectpack.h
  imgui/imstb_textedit.h
  imgui/imstb_truetype.h
  imgui/backends/imgui_impl_glfw.cpp
  imgui/backends/imgui_impl_glfw.h
  imgui/backends/imgui_impl_opengl3_loader.h
  imgui/backends/imgui_impl_opengl3.cpp
  imgui/backends/imgui_impl_opengl3.h
)

target_link_libraries(imgui
  PUBLIC glfw
)

target_include_directories(imgui 
	PUBLIC imgui/
  PUBLIC imgui/backends/
	PUBLIC glfw/include/
)