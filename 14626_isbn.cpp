#include <iostream>
#include <vector>

using namespace std;

vector<int> isbn(13, -1);
const vector<int> check = {1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3};
int idx;

int getCheck(int x) {
    int sum = 0;
    int mod = 0;

    for (int i = 0; i < 13; i++) {
        if (isbn[i] != -1) {
            sum += isbn[i] * check[i];
        }
    }

    if ((idx % 2) == 0) {
        sum += x;
    }
    else if ((idx % 2) == 1) {
        sum += 3 * x;
    }
    else {
        cerr << "getCheck: unexpected idx mod" << "\n";
    }

    mod = sum % 10;

    if (mod == 0) {
        return 0;
    }
    
    return 10 - mod;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int result = 0;
    idx = -1;

    for (int i = 0; i < 13; i++) {
        char num;
        cin >> num;

        if ((num >= '0') && (num <= '9')) {
            isbn[i] = num - '0';
        }
        else if (num == '*') {
            idx = i;
        }
        else {
            cerr << "main: unexpected input" << "\n";
        }
    }

    // brute force
    for (int i = 0; i < 10; i++) {
        if (isbn[12] == getCheck(i)) {
            result = i;
            break;
        }
    }

    cout << result << "\n";

    return EXIT_SUCCESS;
}