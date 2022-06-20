#pragma once

extern Core::CoreApp* Core::CreateApp();

int main(int argc, char** argv)
{   
    auto App = Core::CreateApp();
    App->run();
    delete App;
}