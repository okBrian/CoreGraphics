#include "Renderer.hpp"

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(const VAO& va, const IBO& ibo, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ibo.Bind();

    glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr);
}