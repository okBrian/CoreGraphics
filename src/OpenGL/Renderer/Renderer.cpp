#include "Renderer.hpp"

namespace Core
{
    void Renderer::Clear() const
    {
        CORE_DEBUG("Cleared the Color and Depth Buffer!");
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::Draw(const VAO& va, const IBO& ibo, const Shader& shader) const
    {
        shader.Bind();
        va.Bind();
        ibo.Bind();
        CORE_DEBUG("Drawing the elements!");
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr);
        shader.Unbind();
        va.Unbind();
        ibo.Unbind();
    }

    void Renderer::Draw(const VAO& va, const GLuint count, const Shader& shader) const
    {
        shader.Bind();
        va.Bind();
        CORE_DEBUG("Drawing the elements!");
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
        shader.Unbind();
        va.Unbind();
    }
};