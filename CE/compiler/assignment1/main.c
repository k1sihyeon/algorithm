#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "transition.h"

int main(void) {

    State currentState = S;     // 현재상태 변수를 초기상태로 설정

    char buf[BUFSIZ];           // 입력받을 문자열 버퍼(최대 크기: BUFSIZ = 512)

    if (fgets(buf, BUFSIZ, stdin) == NULL) {    // 문자열 입력
        perror("[main.c] Error: string input");
        return EXIT_FAILURE;
    }

    int i = 0;      // 문자열 인덱스 변수
    while ((buf[i] != '\0') && (buf[i] != '\n') && (currentState != PHI)) {     // 문자열의 끝이 아니고 현재상태가 PHI(공집합)가 아닐 때까지 반복
        Symbol nextSymbol = getNextSymbol(buf[i]);              // 다음 문자의 심볼을 가져옴
        
        currentState = deltaFunction(currentState, nextSymbol); // 델타 함수를 통해 다음 상태를 가져옴

        i += 1;     // 다음 문자로 이동
    }

    if (currentState == F)      // 현재 상태가 F이면 유효한 문자열
        printf("Valid String\n");
    else
        printf("Invalid String\n");


    return EXIT_SUCCESS;
}

// build 방법 (택일):
// $ make clean && make run
// $ gcc -I. -Wall -Wextra -std=c11 -o assignement.exe main.c transition.c