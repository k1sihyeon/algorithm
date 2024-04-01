#include <iostream>
#include <string>
#include <cmath>

#define r 31
#define M 1234567891

using namespace std;

int L;
string str;

long long POW(int i) {
    long long result = 1;
    for (int j = 0; j < i; j++) {
        result *= r;
        result %= M;
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    long long result = 0;

    cin >> L >> str;

    for (int i = 0; i < L; i++) {
        long long a = str[i] - 'a' + 1;

        long long rSquare = POW(i);

        result = (result + (a * rSquare) % M) % M;
    }

    std::cout << result << '\n';

    return 0;   
}