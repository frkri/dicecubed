#pragma once

#include "Camera3D.hpp"
#include <vector>

#include "objects/dice.h"

class Scene {
  public:
    static constexpr float DICE_GAP = 6.5f;

    Scene(raylib::Camera3D &cam, raylib::Texture2D &texture);

    void Update();

  protected:
    raylib::Camera3D &Cam;
    raylib::Texture2D &Texture;
    std::vector<Dice> DiceList;
};