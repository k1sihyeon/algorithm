#pragma once

#include "Renderer.h"

#include <random>

class ChristmasTree {
private:
    int mHeight;
    std::mt19937 mGen;
    std::uniform_int_distribution<int> mOrnamentDist;
    std::uniform_int_distribution<int> mColorDist;

    int mOrnamentProb; // LED 등장 확률 0~100

public:
    ChristmasTree(int height, int ornamentProb = 20);
    void Render(Renderer& renderer);
};