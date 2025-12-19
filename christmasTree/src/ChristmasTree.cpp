#include "ChristmasTree.h"
#include "Color.h"

#include <sstream>

ChristmasTree::ChristmasTree(int height, int ornamentProb)
    : mHeight(height), mOrnamentDist(1, 100), mColorDist(0, color::LEDS.size() - 1), mOrnamentProb(20) {
    
    std::random_device rd;
    mGen.seed(rd());

    if (ornamentProb >= 0 && ornamentProb <= 100)
        mOrnamentProb = ornamentProb;
    else
        mOrnamentProb = 20; // default 20%
}

void ChristmasTree::Render(Renderer& renderer) {
    std::stringstream ss;

    // Star
    ss << color::YELLOW << "★" << color::RESET;
    renderer.DrawLine(ss.str(), true);
    ss.str("");

    // Tree with Ornaments
    for (int i = 0; i < mHeight; i++) {
        for (int j = 0; j < ((2 * i) + 1); j++) {
            if (mOrnamentDist(mGen) <= mOrnamentProb)
                ss << color::LEDS[mColorDist(mGen)] << "o" << color::RESET;
            else
                ss << color::GREEN << "*" << color::RESET;
        }

        renderer.DrawLine(ss.str(), true);
        ss.str("");
    }

    // Trunk
    for (int i = 0; i < 2; i++) {
        ss << color::BROWN << "|||" << color::RESET;
        renderer.DrawLine(ss.str(), true);
        ss.str("");
    }

    // Empty line with snow
    renderer.DrawLine("", true);
}