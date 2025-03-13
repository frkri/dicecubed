#pragma once

#include "Camera3D.hpp"
#include <vector>

#include "Texture.hpp"
#include "objects/dice.h"
#include "raylib.h"

class Scene {
  public:
    static constexpr float DICE_GAP = 6.5f;
    static constexpr float KEY_SCALE = 0.4f;

    Scene(raylib::Camera3D &cam, raylib::Texture2D &texture);

    void Update();
    void RollDice(int times);

  protected:
    raylib::Camera3D &Cam;
    raylib::Texture2D &Texture;
    std::vector<Dice> DiceList;

  private:
    static inline raylib::Texture2D LoadScaledTexture(const char *filename,
                                                      float scale) {
        Image img = LoadImage(filename);
        int newWidth = static_cast<int>(img.width * scale);
        int newHeight = static_cast<int>(img.height * scale);
        ImageResize(&img, newWidth, newHeight);
        raylib::Texture2D tex = LoadTextureFromImage(img);
        UnloadImage(img);
        return tex;
    }

    raylib::Texture2D EKey =
        LoadScaledTexture("../resources/E_Key.png", KEY_SCALE);
    raylib::Texture2D QKey =
        LoadScaledTexture("../resources/Q_Key.png", KEY_SCALE);
    raylib::Texture2D SpaceKey =
        LoadScaledTexture("../resources/Space_Key.png", KEY_SCALE);
    raylib::Texture2D FKey =
        LoadScaledTexture("../resources/F_Key.png", KEY_SCALE);

    void DrawGUI();
};
