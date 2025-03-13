#include "app.h"

#include "Camera3D.hpp"
#include "Texture.hpp"
#include "Vector3.hpp"
#include "algorithm"
#include "raylib.h"
#include "scene.h"

App::App(const int targetFPS)
    : TargetFPS(targetFPS), Win(raylib::Window(1000, 800, "dicecubed")),
      Cam(raylib::Camera3D(raylib::Vector3(4, 3, 0), raylib::Vector3(0, 0, 0),
                           raylib::Vector3(0, 1, 0), 80)),
      DiceTexture(raylib::Texture2D("../../resources/dice.png")),
      MainScene(Cam, DiceTexture) {}

const void App::Run() {
    HideCursor();
    DisableCursor();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(Update, 0, 1);
#else
    SetTargetFPS(this->TargetFPS);

    while (!Win.ShouldClose())
        Update();
#endif

    Win.Close();
}

void App::Update() {
    HandleKeyPress();
    Cam.Update(CamMode);

    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);

    MainScene.Update();
    EndDrawing();
}

void App::HandleKeyPress() {
    switch (GetKeyPressed()) {
    case 'F':
        if (CamMode == CAMERA_FREE) {
            CamMode = CAMERA_CUSTOM;
            Cam.SetFovy(80);
            Cam.SetPosition(raylib::Vector3(4, 3, 0));
            Cam.SetTarget(raylib::Vector3(0, 0, 0));
            Cam.SetUp(raylib::Vector3(0, 1, 0));
        } else
            CamMode = CAMERA_FREE;
        break;
    case KEY_SPACE:
        MainScene.RollDice(RollCount);
        break;
    case KEY_UP:
        MainScene.AddDice();
        break;
    case KEY_DOWN:
        MainScene.RemoveDice();
        break;
    case KEY_LEFT:
        RollCount = std::clamp(RollCount - 1, 1, 10);
        MainScene.SetRollCount(RollCount);
        break;
    case KEY_RIGHT:
        RollCount = std::clamp(RollCount + 1, 1, 10);
        MainScene.SetRollCount(RollCount);
        break;
    }

    if (IsKeyDown('Q') || IsKeyDown('E') && CamMode == CAMERA_CUSTOM) {
        const float orbitSpeed = IsKeyDown('Q') ? -3.0f : 3.0f;

        Vector3 view = Vector3Subtract(Cam.GetPosition(), Cam.GetTarget());
        view = Vector3Transform(
            view, MatrixRotate(Cam.GetUp(), orbitSpeed * GetFrameTime()));
        Cam.SetPosition(Vector3Add(Cam.GetTarget(), view));
    }
}
