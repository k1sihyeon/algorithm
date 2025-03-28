#include "transition.h"

// 상태 전이표 정의
State transitionTable[4][2] = {
    {A, PHI},
    {A, B},
    {F, PHI},
    {F, PHI}
};

// 입력 심볼이 숫자(0~9)인지 확인
bool isDigit(char symbol) {
    if ((symbol >= '0') && (symbol <= '9'))
        return true;
    else
        return false;
}

// 입력 심볼이 '.'인지 확인
bool isDot(char symbol) {
    if (symbol == '.')
        return true;
    else
        return false;
}

// 입력 문자를 통해 다음 심볼을 가져오는 함수
Symbol getNextSymbol(char nextSymbol) {
    Symbol symbol;

    if (isDigit(nextSymbol))    // 입력 심볼이 숫자(0~9)인 경우
        symbol = DIGIT;
    else if (isDot(nextSymbol)) // 입력 심볼이 '.'인 경우
        symbol = DOT;
    else                        // 그 외의 경우
        symbol = OTHER;

    return symbol;  // 심볼 반환
}

// 현재상태와 다음 심볼을 통해 다음 상태를 가져오는 전이함수
State deltaFunction(State currentState, Symbol nextSymbol) {
    State nextState = PHI;

    if ((currentState == PHI) || (nextSymbol == OTHER))  // 현재상태가 PHI(공집합)이거나 다음 심볼이 OTHER인 경우
        return nextState;                           // 다음 상태는 PHI(공집합)
    
    // 상태 전이표에서 현재상태와 다음 심볼에 해당하는 다음 상태를 가져옴
    nextState = transitionTable[currentState][nextSymbol];

    return nextState;   // 다음 상태 반환
}