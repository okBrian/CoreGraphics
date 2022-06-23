#include <Core.hpp>
using namespace Core;

class App : public Core::CoreApp
{
private:
    // Everything needed to make a Square on the screen;
    Renderer renderer;
    WindowsPlatform window; 
    VAO vao;
    VBO vbo;
    IBO ibo;
    VBOLayout layout;
    Shader shader;
    ImGuiClass imgui;

    float vertices[8] 
    {
        // Coords       // texCoords
        -0.5f, -0.5f, //  0.0f, 0.0f,  // 0
         0.5f, -0.5f, //  1.0f, 0.0f,  // 1
         0.5f,  0.5f, //  1.0f, 1.0f,  // 2
        -0.5f,  0.5f //  0.0f, 1.0f   // 3
    };

    GLuint indices[6]  
    {
        0, 1, 2,
        2, 3, 0
    };

    // Vertices and Indices Explanition // The Quad is made up of 2 seperate triangles
    //
    // -1.0, 1.0 // 3                    1.0, 1.0 // 2
    //  ---------------------------------
    //  |                           /   |
    //  |                         /     |
    //  |                       /       |
    //  |                    /          | 
    //  |                  /            |
    //  |               /               |
    //  |            /                  |
    //  |         /                     |
    //  |      /                        | 
    //  |   /                           |
    //  | /                             |
    //  ---------------------------------
    // -1.0, -1.0 // 0                   1.0, -1.0 // 1
public:
    App()
        : CoreApp(), window(WindowsPlatform("Square - CoreGraphics", 800, 800))
    {
        if(!LoadOpenGLContext())
        {
            window.Close();
        }
        window.setVSync(true);


        vao.init();
        vbo.init(vertices, sizeof(vertices), GL_STATIC_DRAW);
        ibo.init(indices, sizeof(indices));
        shader.init("../../res/Color.vert", "../../res/Color.frag");
        imgui.init(window.getWindow());


        layout.Push<float>(2); // Our data contains 2 floats of x, y so we push to the layout that we have 2 floats so it reads the data correctly
        vao.AddBuffer(vbo, layout);
        shader.Bind();


        vao.Unbind();
        vbo.Unbind();
        ibo.Unbind();
        shader.Unbind();

    }

    ~App()
    {
        vao.Unbind();
        vbo.Unbind();
        ibo.Unbind();
        shader.Unbind();
    }

    void run()
    {
        float ClearColor[] = { 1.0f, 1.0f, 1.0f, 1.0f};
        while(window.WindowRunning)
        {
            renderer.Clear();
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            
            shader.Bind();
            shader.SetUniform4f("aColor", ClearColor[0], ClearColor[1], ClearColor[2], ClearColor[3]);

            renderer.Draw(vao, ibo, shader);

            imgui.ImGuiNewFrame();
            ImGui::Begin("Options");
            ImGui::ColorEdit4("Clear Color", ClearColor);
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
            imgui.ImGuiRenderFrame();

            window.onUpdate();

        }
    }
};

Core::CoreApp* Core::CreateApp()
{
    return new App();
}