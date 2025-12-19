#pragma once

#include <string>
#include <random>

class Renderer {
private:
    int mWidth;
    std::mt19937 mGen;
    std::uniform_int_distribution<int> mSnowDist;
    int mDotSnowProb;
    int mStarSnowProb;

    int getVisibleLength(const std::string& content);
    void printPadding(int length, bool bIsSnowEnabled);

public:
    Renderer(int consoleWidth, int dotSnowProb = 5, int starSnowProb = 2);
    void DrawLine(const std::string& content, bool bIsSnowEnabled = true);
};