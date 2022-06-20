#pragma once

#include <VAO/VAO.hpp>
#include <IBO/IBO.hpp>
#include <Shader/Shader.hpp>

    namespace Core
    {

    // Basic Renderer to Clear the buffers and Draw the triangles
    class Renderer
    {
    public:
        void Clear() const;
        void Draw(const VAO& va, const IBO& ibo, const Shader& shader) const;
    };
};