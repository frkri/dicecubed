#include "app.h"

App::App(raylib::Window window, const int targetFPS)
    : TargetFPS(targetFPS), MainWin(window) {
    window.SetFullscreen(true);
}

const void App::Run() {
    raylib::Window window(250, 250, "dicecubed");
    window.SetFullscreen(true);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(Update, 0, 1);
#else
    SetTargetFPS(this->TargetFPS);

    while (!window.ShouldClose()) {
        Update();
    }
#endif
}

void App::Update() {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first raylib-cpp window!", 160, 200,
             20, LIGHTGRAY);

    EndDrawing();
}