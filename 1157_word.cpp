#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int max, vector<int> &alpha) {
    int cnt = 0;

    for(int i = 0; i < alpha.size(); i++) {
        if(alpha[i] == max) {
            cnt += 1;
        }
        
        if(cnt > 1) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> alpha(26);
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        str[i] = toupper(str[i]);
    }

    for(int i = 0; i < (int)str.size(); i++) {
        alpha[str[i] - 'A'] += 1;
    }

    int max = max_element(alpha.begin(), alpha.end()) - alpha.begin();

    if(check(alpha[max], alpha)) {
        cout << (char)('A' + max) << endl;
    }
    else {
        cout << "?" << endl;
    }

    return 0;
}
