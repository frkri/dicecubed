#pragma once

#include "Rectangle.hpp"
#include "Texture.hpp"
#include "Vector3.hpp"
#include "rlgl.h"

class Dice {
  public:
    static constexpr float SIZE = 1.0f;

    Dice(const raylib::Vector3 &initPosition, raylib::Texture2D &texture)
        : Position(initPosition), Texture(texture) {}

    void Update() {
        auto x = Position.x;
        auto y = Position.y;
        auto z = Position.z;

        float width = SIZE;
        float height = SIZE;
        float length = SIZE;

        float texWidth = Texture.width;
        float texHeight = Texture.height;

        raylib::Rectangle source(0.0f, Texture.height / SIZE,
                                 Texture.width / SIZE, Texture.height / SIZE);

        rlSetTexture(Texture.id);

        rlBegin(RL_QUADS);
        rlColor4ub(255, 255, 255, 255);

        // Front Face
        rlNormal3f(0.0f, 0.0f, 1.0f); // Normal Pointing Towards Viewer
        rlTexCoord2f(0.0f, 0.0f);
        rlVertex3f(x - width / 2, y - height / 2,
                   z + length / 2); // Bottom Left Of The Texture and Quad
        rlTexCoord2f(1.0f, 0.0f);
        rlVertex3f(x + width / 2, y - height / 2,
                   z + length / 2); // Bottom Right Of The Texture and Quad
        rlTexCoord2f(1.0f, 1.0f);
        rlVertex3f(x + width / 2, y + height / 2,
                   z + length / 2); // Top Right Of The Texture and Quad
        rlTexCoord2f(0.0f, 1.0f);
        rlVertex3f(x - width / 2, y + height / 2,
                   z + length / 2); // Top Left Of The Texture and Quad
        // Back Face
        rlNormal3f(0.0f, 0.0f, -1.0f); // Normal Pointing Away From Viewer
        rlTexCoord2f(1.0f, 0.0f);
        rlVertex3f(x - width / 2, y - height / 2,
                   z - length / 2); // Bottom Right Of The Texture and Quad
        rlTexCoord2f(1.0f, 1.0f);
        rlVertex3f(x - width / 2, y + height / 2,
                   z - length / 2); // Top Right Of The Texture and Quad
        rlTexCoord2f(0.0f, 1.0f);
        rlVertex3f(x + width / 2, y + height / 2,
                   z - length / 2); // Top Left Of The Texture and Quad
        rlTexCoord2f(0.0f, 0.0f);
        rlVertex3f(x + width / 2, y - height / 2,
                   z - length / 2); // Bottom Left Of The Texture and Quad
        // Top Face
        rlNormal3f(0.0f, 1.0f, 0.0f); // Normal pointing up
        // Using only the upper-left block of a 2x2 grid (each block is 0.5 in
        // UV coordinates)
        rlTexCoord2f(0.0f, 0.0f);
        rlVertex3f(x - width / 2, y + height / 2, z - length / 2); // Top Left
        rlTexCoord2f(0.0f, 0.5f);
        rlVertex3f(x - width / 2, y + height / 2,
                   z + length / 2); // Bottom Left
        rlTexCoord2f(0.5f, 0.5f);
        rlVertex3f(x + width / 2, y + height / 2,
                   z + length / 2); // Bottom Right
        rlTexCoord2f(0.5f, 0.0f);
        rlVertex3f(x + width / 2, y + height / 2, z - length / 2); // Top Right
        // Bottom Face
        rlNormal3f(0.0f, -1.0f, 0.0f); // Normal Pointing Down
        rlTexCoord2f(1.0f, 1.0f);
        rlVertex3f(x - width / 2, y - height / 2,
                   z - length / 2); // Top Right Of The Texture and Quad
        rlTexCoord2f(0.0f, 1.0f);
        rlVertex3f(x + width / 2, y - height / 2,
                   z - length / 2); // Top Left Of The Texture and Quad
        rlTexCoord2f(0.0f, 0.0f);
        rlVertex3f(x + width / 2, y - height / 2,
                   z + length / 2); // Bottom Left Of The Texture and Quad
        rlTexCoord2f(1.0f, 0.0f);
        rlVertex3f(x - width / 2, y - height / 2,
                   z + length / 2); // Bottom Right Of The Texture and Quad
        // Right face
        rlNormal3f(1.0f, 0.0f, 0.0f); // Normal Pointing Right
        rlTexCoord2f(1.0f, 0.0f);
        rlVertex3f(x + width / 2, y - height / 2,
                   z - length / 2); // Bottom Right Of The Texture and Quad
        rlTexCoord2f(1.0f, 1.0f);
        rlVertex3f(x + width / 2, y + height / 2,
                   z - length / 2); // Top Right Of The Texture and Quad
        rlTexCoord2f(0.0f, 1.0f);
        rlVertex3f(x + width / 2, y + height / 2,
                   z + length / 2); // Top Left Of The Texture and Quad
        rlTexCoord2f(0.0f, 0.0f);
        rlVertex3f(x + width / 2, y - height / 2,
                   z + length / 2); // Bottom Left Of The Texture and Quad
        // Left Face
        rlNormal3f(-1.0f, 0.0f, 0.0f); // Normal Pointing Left
        rlTexCoord2f(0.0f, 0.0f);
        rlVertex3f(x - width / 2, y - height / 2,
                   z - length / 2); // Bottom Left Of The Texture and Quad
        rlTexCoord2f(1.0f, 0.0f);
        rlVertex3f(x - width / 2, y - height / 2,
                   z + length / 2); // Bottom Right Of The Texture and Quad
        rlTexCoord2f(1.0f, 1.0f);
        rlVertex3f(x - width / 2, y + height / 2,
                   z + length / 2); // Top Right Of The Texture and Quad
        rlTexCoord2f(0.0f, 1.0f);
        rlVertex3f(x - width / 2, y + height / 2, z - length / 2);

        rlEnd();

        rlSetTexture(0);
    }

  private:
    raylib::Vector3 Position;
    raylib::Texture2D &Texture;
};