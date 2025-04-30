#ifndef TRANSITION_H
#define TRANSITION_H
// 헤더 가드

#include <stdbool.h>

// 상태를 enum으로 정의
enum State {
    S,
    A,
    B,
    F,
    PHI
};

// 심볼을 enum으로 정의
enum Symbol {
    DIGIT,
    DOT,
    OTHER
};

typedef enum State State;   // enum State를 State로 typedef
typedef enum Symbol Symbol; // enum Symbol을 Symbol로 typedef

extern State transitionTable[4][2];     // 상태 전이표를 2차원 배열로 선언

bool isDigit(char symbol);  // 입력 심볼이 숫자(0~9)인지 확인
bool isDot(char symbol);    // 입력 심볼이 '.'인지 확인

Symbol getNextSymbol(char nextSymbol);  // 입력 문자를 통해 다음 심볼을 가져오는 함수
State deltaFunction(State currentState, Symbol nextSymbol); // 현재상태와 다음 심볼을 통해 다음 상태를 가져오는 전이함수

#endif