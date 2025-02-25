#include "raylib-cpp.hpp" // IWYU pragma: keep
#include <iostream>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void Update(void);

int main() {
    raylib::Window window(250, 250, "dicecubed");
    window.SetFullscreen(true);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);

    while (!window.ShouldClose()) {
        Update();
    }
#endif

    std::cout << "Exiting..." << std::endl;
    return 0;
}

void Update(void) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first raylib-cpp window!", 160, 200,
             20, LIGHTGRAY);

    EndDrawing();
}
