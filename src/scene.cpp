#include "scene.h"
#include "Texture.hpp"
#include "Vector3.hpp"
#include "objects/dice.h"
#include "raylib.h"
#include <string>

Scene::Scene(raylib::Camera3D &cam, raylib::Texture2D &texture)
    : Cam(cam), Texture(texture), DiceList() {
    raylib::Vector3 initPosition(0, 0, 0);

    Dice dice(initPosition, Texture);
    DiceList.push_back(dice);
}

void Scene::Update() {
    BeginMode3D(Cam);
    DrawGrid(DiceList.size() * 2, 1.0f);

    for (Dice &dice : DiceList)
        dice.Update();

    EndMode3D();

    DrawGUI();
}

void Scene::AddDice() {
    raylib::Vector3 initPosition(DiceList.size() * DICE_GAP, 0, 0);
    Dice dice(initPosition, Texture);
    DiceList.push_back(dice);

    int total = DiceList.size();
    for (size_t i = 0; i < DiceList.size(); i++) {
        float x = (i - (total - 1) / 2.0f) * DICE_GAP;
        DiceList[i].SetPosition(raylib::Vector3(x, 0, 0));
    }
}

void Scene::RemoveDice() {
    if (DiceList.size() > 1)
        DiceList.pop_back();

    int total = DiceList.size();
    for (size_t i = 0; i < DiceList.size(); i++) {
        float x = (i - (total - 1) / 2.0f) * DICE_GAP;
        DiceList[i].SetPosition(raylib::Vector3(x, 0, 0));
    }
}

void Scene::RollDice(int times) {
    for (Dice &dice : DiceList)
        dice.Roll(times);
}

void Scene::SetRollCount(int count) { RollCount = count; }

void Scene::DrawGUI() {
    DrawText("Rollen", GetScreenWidth() / 2 - 30, GetScreenHeight() - 80, 20,
             RAYWHITE);
    DrawTexture(SpaceKey, GetScreenWidth() / 2 - SpaceKey.GetWidth() / 2,
                GetScreenHeight() - SpaceKey.GetHeight() - 20, RAYWHITE);

    DrawText("Drehen", GetScreenWidth() - 100, GetScreenHeight() - 80, 20,
             RAYWHITE);
    DrawTexture(EKey, GetScreenWidth() - EKey.GetWidth() - 20,
                GetScreenHeight() - EKey.GetHeight() - 20, RAYWHITE);
    DrawTexture(QKey, GetScreenWidth() - QKey.GetWidth() - 70,
                GetScreenHeight() - QKey.GetHeight() - 20, RAYWHITE);

    DrawText("Kamera wechseln", 20, GetScreenHeight() - 80, 20, RAYWHITE);
    DrawTexture(FKey, 20, GetScreenHeight() - FKey.GetHeight() - 20, RAYWHITE);

    DrawText(("Würfeln: " + std::to_string(DiceList.size())).c_str(), 240,
             GetScreenHeight() - 80, 20, RAYWHITE);
    DrawTexture(UpKey, 240, GetScreenHeight() - UpKey.GetHeight() - 20,
                RAYWHITE);
    DrawTexture(DownKey, 280, GetScreenHeight() - DownKey.GetHeight() - 20,
                RAYWHITE);

    DrawText(("Rollen Anzahl: " + std::to_string(RollCount)).c_str(),
             GetScreenWidth() - 340, GetScreenHeight() - 80, 20, RAYWHITE);
    DrawTexture(RightKey, GetScreenWidth() - 300,
                GetScreenHeight() - RightKey.GetHeight() - 20, RAYWHITE);
    DrawTexture(LeftKey, GetScreenWidth() - 340,
                GetScreenHeight() - LeftKey.GetHeight() - 20, RAYWHITE);

    int result = 0;
    for (size_t i = 0; i < DiceList.size(); i++) {
        if (DiceList[i].GetResult() == -1)
            break;

        result += DiceList[i].GetResult();
    }

    DrawText(("Ergebnis: " + std::to_string(result)).c_str(),
             GetScreenWidth() / 2 - 50, 20, 20, RAYWHITE);
}
