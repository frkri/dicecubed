#pragma once

#include "Camera3D.hpp"
#include "Window.hpp"
#include "raylib.h"
#include "scene.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

class App {
  public:
    App(const int targetFPS = GetMonitorRefreshRate(0));
    const void Run();

  protected:
    const int TargetFPS;
    raylib::Window Win;
    raylib::Camera3D Cam;
    raylib::Texture2D DiceTexture;
    Scene MainScene;

    int CamMode = CAMERA_CUSTOM;

    void HandleKeyPress();
    void Update();
};
