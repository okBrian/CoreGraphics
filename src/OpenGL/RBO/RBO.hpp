#pragma once
#include <glObject.hpp>
namespace Core
{

    // Render Buffer Object: Stores an image to be used with the FBO can't be accesed in shader
    class RBO : public glObject
    {
    public:
        // Initialize the RBO & store it in depth buffer
        void init(int width, int height);
        // Delete the RBO
        ~RBO();

        // Binds the RBO for current use
        void Bind() const override;
        // Unbind the RBO from current usage
        void Unbind() const override;
        // Attach the RBO to the FBO
        void AttachRBO() const;
    };
};