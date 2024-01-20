#include <iostream>
#include <string>

using namespace std;

//bool remote[10] = { true, };
//초기화시 모두 true로 초기화 해주지 않음.. !!
int remote[10] = { 0, };

bool isDirect(int num) {
    string strNum = to_string(num);

    for(int i = 0; i < strNum.length(); i++) {
        if(remote[strNum[i] - '0'] == 1) {
            return false;
        }
    }

    return true;
}


int main(void) {
    int N, M, count;
    int now = 100;

    cin >> N;
    cin >> M;

    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        remote[num] = 1;
    }

    if(N == now) {
        cout << 0 << '\n';
        return 0;
    }

    count = abs(now - N);

    for(int i = 0; i <= 1000000; i++) {

        if(isDirect(i) == true) {
            int tmp = abs(N - i) + to_string(i).length();
            count = min(count, tmp);
        }
    }

    cout << count << '\n';

    return 0;
}