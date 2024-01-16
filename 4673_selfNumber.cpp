#include <iostream>

using namespace std;

int selfNumber(int n) {
    int sum = n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void) {
    bool arr[10001] = { false, };
    
    for (int i = 1; i <= 10000; i++) {
        int idx = selfNumber(i);
        if (idx <= 10000) {
            arr[idx] = true;
        }
    }

    for (int i = 1; i <= 10000; i++) {
        if (!arr[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}