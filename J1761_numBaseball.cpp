#include <bits/stdc++.h>

using namespace std;

bool board[988];

int getStrike(int a, int b) {
    int strike = 0;

    string sa = to_string(a);
    string sb = to_string(b);

    for (int i = 0; i < 3; i++) {
        if (sa[i] == sb[i])
            strike += 1;
    }

    return strike;
}

//b를 정답이라고 가정
int getBall(int a, int b) {
    int ball = 0;

    string sa = to_string(a);
    string sb = to_string(b);

    if (sa[0] == sb[1] || sa[0] == sb[2])
        ball += 1;
    
    if (sa[1] == sb[0] || sa[1] == sb[2])
        ball += 1;

    if (sa[2] == sb[0] || sa[2] == sb[1])
        ball += 1;

    return ball;
}

int main(void) {
    int n;
    cin >> n;

    //init
    memset(board, true, sizeof(board));

    //123 ~ 987 사이의 정수중 0, 중복된 숫자 제거
    for (int i = 0; i < 123; i++)
        board[i] = false;
    
    for (int i = 123; i <= 987; i++) {
        string s = to_string(i);
        for (int j = 0; j < 3; j++) {
            if (s[j] == '0')
                board[i] = false;
        }

        if ((s[0] == s[1]) || (s[1] == s[2]) || (s[2] == s[0]))
            board[i] = false;
    }


    for (int i = 0; i < n; i++) {
        int num, st, bl;
        cin >> num >> st >> bl;

        for (int j = 123; j <= 987; j++) {
            if (board[j] == true) {
                if (getStrike(j, num) != st)
                    board[j] = false;
                
                if (getBall(j, num) != bl)
                    board[j] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 123; i <= 987; i++) {
        if (board[i] == true)
            ans += 1;
    }

    cout << ans << "\n";

    return 0;
}