#include "include/imgui/imgui.h"
#include "include/imgui/backends/imgui_impl_glfw.h"
#include "include/imgui/backends/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <iostream>

class Monster {
public:
    int hp;
    int atk;
    int def;
};

int main() {
    // 初始化 GLFW
        if (!glfwInit())
            return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(1280, 720, "game", nullptr, nullptr);
    if (!window)
        return -1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // 初始化 ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();


        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

       // glfwMaximizeWindow(window);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //因为窗口无法铺满整个ui，所以在这里实现窗口铺满ui的功能(读取ui的大小，设置窗口的大小)
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(display_w, display_h));
        //此处的ImGuiWindowFlags_NoMove是一个标志位，用于设置ImGui窗口的属性,在这里是不可移动的意思，即用户无法拖动窗口
        //nullptr则取消掉窗口的关闭按钮
        //ImGuiWindowFlags_NoResize则是让窗口不可缩放，这样在循环中窗口就会自适应ui的大小，而不会被另外调整
        //ImGuiWindowFlags_NoTitleBar则是让窗口没有标题栏，这样就可以让窗口铺满ui
        ImGui::Begin("START", nullptr   , ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);

        double start_button_w=display_w/2;
        double start_button_h=display_h/2;
        ImGui::SetCursorPos(ImVec2(start_button_w-55, start_button_h));
        if (ImGui::Button("start", ImVec2(100, 100)))
        {
            std::cout << "你点击了按钮" << std::endl;
        }
        ImGui::End();
        ImGui::Render();

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // 清理
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
