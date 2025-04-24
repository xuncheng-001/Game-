cmake_minimum_required(VERSION 3.10)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(OpeanGL_GL_PREFERENCE GLVND)

##设置Imgui的路径
include_directories(include)
include_directories(include/imgui)
include_directories(include/imgui/backends)
include_directories(include/imgui/examples/libs/glfw/include)

find_package(OpenGL REQUIRED)


#源文件的列表
set(IMGUI_SRC
        include/imgui/imgui.cpp
        include/imgui/imgui_demo.cpp
        include/imgui/imgui_draw.cpp
        include/imgui/imgui_tables.cpp
        include/imgui/imgui_widgets.cpp
        include/imgui/backends/imgui_impl_opengl3.cpp
        include/imgui/backends/imgui_impl_glfw.cpp
)

##add_subdirectory(include/ImGui/examples/libs/glfw)

add_executable(game main.cpp ${IMGUI_SRC})

target_link_libraries(game
        glfw
        ${OPENGL_LIBRARIES}
        dl
        X11
        pthread
)