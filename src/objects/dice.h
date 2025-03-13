#pragma once

#include "Texture.hpp"
#include "Vector3.hpp"
#include "raylib.h"
#include "rlgl.h"

class Dice {
  public:
    Dice(const raylib::Vector3 &initPosition, raylib::Texture2D &texture)
        : Position(initPosition), Texture(texture) {
        model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = Texture;
    }

    void Update() {
        DrawModelEx(
            model, Position, raylib::Vector3(1.0f, 0.0f, 0.0f),
            Lerp(currentAngle, currentAngle + ANGLE_ADD, rollTime / ROLL_SPEED),
            raylib::Vector3(1.0f, 1.0f, 1.0f), RAYWHITE);
        if (isRolling) {
            rollTime += GetFrameTime();

            if (rollTime >= ROLL_SPEED) {
                rollTime = 0.0f;
                currentAngle += ANGLE_ADD;

                rotationsLeft--;
                if (rotationsLeft <= 0) {
                    isRolling = false;
                    result = GetRandomValue(1, 6);
                }
            }
        }
        return;
    }

    bool Roll(int times) {
        if (isRolling) {

            isRolling = false;
            currentAngle = 0;
            rollTime = 0.0f;
            rotationsLeft = 0;
        }

        isRolling = true;
        rotationsLeft = times;

        return true;
    }

    void SetPosition(const raylib::Vector3 &newPosition) {
        Position = newPosition;
    }

  private:
    static constexpr float SIZE = 1.0f;
    static constexpr float ROLL_SPEED = 0.8f;
    static constexpr float ANGLE_ADD = 90.0f;

    raylib::Vector3 Position;
    raylib::Texture2D &Texture;
    int currentAngle = 0;

    Model model = LoadModelFromMesh(GenMeshCube(SIZE, SIZE, SIZE));

    bool isRolling = false;
    float rollTime = 0.0f;
    int rotationsLeft = 0;
    int result = 0;
};