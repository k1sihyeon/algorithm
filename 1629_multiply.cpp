#include <iostream>
#include <cmath>

using namespace std;

int A, B, C;

long long pow(int b) {

    if (b == 0) {
        return 1;
    }

    else if (b == 1) {
        return A % C;
    }

    else if (b % 2 == 0) {
        long long tmp = pow(b / 2);
        return (tmp * tmp) % C;
    }

    else {
        long long tmp = pow(b / 2);
        return (((tmp * tmp) % C) * A) % C;
    }

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C;

    //b가 짝수일 때와 홀수일 때 나눠서 재귀

    cout << pow(B) << "\n";

    return 0;
}