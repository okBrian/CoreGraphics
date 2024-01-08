# CoreGraphics
A Basic OpenGL Graphics Engine that abstracts many of the OpenGL features into classes

## Usage

This Engine uses CMake as its primary build tool, and uses Git Submodules to add support for glad, glfw, glm, imgui, and spdlog

For usage into a project simply do -
```
add_subdirectory(CoreGraphics CoreGraphics)

target_link_libraries(${PROJECT_NAME}
    PRIVATE CoreGraphics
)
```

Use MSVC as the compiler 

## Example Program

Am example program I made [Okoyo](https://github.com/okBrian/Okoyo.git). A simple gui application that uses imgui to apply color masking to an image.
