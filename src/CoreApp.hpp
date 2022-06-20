#pragma once
#include <glad/glad.h>
#include <Logging/Logging.hpp>
namespace Core
{
    // Base class that is to be super class for client class
    class CoreApp
    {
    public:
        CoreApp()
        {
            gladLoadGL();
            Logging::init();
        }

        virtual void run() = 0;
    };

    // Defined by user
    CoreApp* CreateApp();
};