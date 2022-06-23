#pragma once
#define STB_IMAGE_IMPLEMENTATION
extern Core::CoreApp* Core::CreateApp();

int main(int argc, char** argv)
{   
    auto App = Core::CreateApp();
    App->run();
    delete App;
}