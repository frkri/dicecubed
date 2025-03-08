#pragma once

#include "Window.hpp"
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

class App {
  public:
    App(const raylib::Window window = raylib::Window(250, 250, "dicecubed"),
        const int targetFPS = GetMonitorRefreshRate(0));
    const void Run();

  protected:
    const int TargetFPS;
    raylib::Window MainWin;

    void Update();
};
