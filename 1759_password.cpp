#include <iostream>
using namespace std;

int main(void) {
    int num, tmp, res;
    cin >> num;

    int* arr = new int[num + 1];
    for (int i = 0; i < num; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    tmp = 0;

    for (int i = 0; i < num; i++) {
        tmp += arr[i];
        res += tmp;
    }

    cout << res << endl;

    return 0;
}