#include "scene.h"
#include "Texture.hpp"
#include "Vector3.hpp"
#include "objects/dice.h"

Scene::Scene(raylib::Camera3D &cam, raylib::Texture2D &texture)
    : Cam(cam), Texture(texture), DiceList() {
    raylib::Vector3 initPosition(0, 0, 0);

    Dice dice(initPosition, Texture);
    DiceList.push_back(dice);
}

void Scene::Update() {
    BeginMode3D(Cam);
    DrawGrid(DiceList.size() * 2, 1.0f);

    for (Dice &dice : DiceList) {
        dice.Update();
    }

    EndMode3D();
}
