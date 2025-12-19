#include "ConsoleHelper.h"
#include "Renderer.h"
#include "ChristmasTree.h"
#include "Color.h"

#include <thread>
#include <chrono>
#include <string>

/*
.
├─ Makefile
├─ bin/
├─ include/
    ├─Color.h
    ├─ChristmasTree.h
    ├─ConsoleHelper.h
    └─Renderer.h
├─ obj/
├─ output/
└─ src/
    ├─ChristmasTree.cpp
    ├─ConsoleHelper.cpp
    ├─main.cpp
    └─Renderer.cpp
*/

int main() {

    constexpr int TREE_HEIGHT       = 13;
    constexpr int RENDER_WIDTH      = 60;
    constexpr int RENDER_INTERVAL   = 800;

    constexpr int ORNAMENT_PROB     = 20;   // %
    constexpr int DOT_SNOW_PROB     = 5;    // %
    constexpr int STAR_SNOW_PROB    = 2;    // %

    ConsoleHelper::Init();
    
    Renderer renderer(RENDER_WIDTH, DOT_SNOW_PROB, STAR_SNOW_PROB);
    ChristmasTree tree(TREE_HEIGHT, ORNAMENT_PROB);

    while (true) {
        ConsoleHelper::Clear();

        tree.Render(renderer);

        std::string msg = color::RED + "MERRY CHRISTMAS!" + color::RESET;
        renderer.DrawLine(msg, false);

        std::this_thread::sleep_for(std::chrono::milliseconds(RENDER_INTERVAL));
    }

    return 0;
}

// const : runtime || compile time 에 결정 -> runtime constant 및 compile time constant 둘다 가능
// constexpr : compile time에 값으로 치환됨 -> compile time constant 만 사용

// 즉, const a = 10; constexpr b = a; 불가
// constexpr a = 10; const b = a; 가능

// string, const char*의 경우
    // 1. constexpr std::string_view
    // 2. constexpr const char* || const char* const -> 배열(포인터)의 주소와 값을 모두 const로
        // cf) const char* == (const char)* : char 값이 const함
        // cf) char* const : 포인터 자체가 const, 즉 주소가 const