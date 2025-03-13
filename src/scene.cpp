#include "scene.h"
#include "Texture.hpp"
#include "Vector3.hpp"
#include "objects/dice.h"
#include "raylib.h"

Scene::Scene(raylib::Camera3D &cam, raylib::Texture2D &texture)
    : Cam(cam), Texture(texture), DiceList() {
    raylib::Vector3 initPosition(0, 0, 0);

    Dice dice(initPosition, Texture);
    DiceList.push_back(dice);
}

void Scene::Update() {
    DrawGUI();

    BeginMode3D(Cam);
    DrawGrid(DiceList.size() * 2, 1.0f);

    for (Dice &dice : DiceList) {
        dice.Update();
    }

    EndMode3D();
}

void Scene::DrawGUI() {
    DrawTexture(EKey, GetScreenWidth() + EKey.GetWidth() - 20,
                GetScreenHeight() - 10, RAYWHITE);
    DrawTexture(QKey, GetScreenWidth() - 20, GetScreenHeight() - 10, RAYWHITE);
}

void Scene::RollDice(int times) {
    for (Dice &dice : DiceList) {
        dice.Roll(times);
    }
}
