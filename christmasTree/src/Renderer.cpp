#include "Renderer.h"
#include "Color.h"

#include <iostream>

Renderer::Renderer(int consoleWidth, int dotSnowProb, int starSnowProb) // prob은 0~100
    :mWidth(consoleWidth), mSnowDist(1, 100) {

    std::random_device rd;
    mGen.seed(rd());

    if ((dotSnowProb >= 0) && (dotSnowProb <= 100))
        mDotSnowProb = 100 - dotSnowProb;
    else
        mDotSnowProb = 95; // default, 5%

    if ((starSnowProb >= 0) && (starSnowProb <= 100))
        mStarSnowProb = 100 - starSnowProb;
    else
        mStarSnowProb = 98; // default, 2%
}


int Renderer::getVisibleLength(const std::string& content) {    // 
    int len = 0;
    bool bIsInEscapeSeq = false; // ANSI 이스케이프 시퀀스 내부인지 추적 

    for (char c : content) {
        if (c == '\033') bIsInEscapeSeq = true; // 033은 이스케이프 시퀀스의 시작
        if (!bIsInEscapeSeq) len++;
        if (bIsInEscapeSeq && (c == 'm')) bIsInEscapeSeq = false; // m은 이스케이프 시퀀스의 끝
    }

    if (content.find("★") != std::string::npos) len -= 1; // 별 문자는 실제로 한 글자이지만, 길이 계산에서 제외
    // content에 *이 들어가나?

    return len;
}


void Renderer::printPadding(int length, bool bIsSnowEnabled) {
    for (int i = 0; i < length; i++) {
        if (bIsSnowEnabled) {
            int chance = mSnowDist(mGen);


            if (chance > mStarSnowProb)
                std::cout << color::WHITE << "*" << color::RESET;
            else if (chance > mDotSnowProb)
                std::cout << color::WHITE << "." << color::RESET;
            else
                std::cout << " ";

        }
        else {
            std::cout << " ";
        }
    }
}


void Renderer::DrawLine(const std::string& content, bool bIsSnowEnabled) {
    int visibleLength = getVisibleLength(content);
    int totalPadding = mWidth - visibleLength;
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    printPadding(leftPadding, bIsSnowEnabled);
    std::cout << content;
    printPadding(rightPadding, bIsSnowEnabled);
    std::cout << std::endl;
}