#include <iostream>

using namespace std;

int main(void) {
    int alpha[26] = {-1, };
    string str;
    
    cin >> str;

    for(int i = 0; i < 26; i++) {
        alpha[i] = str.find('a' + i);
    }

    for(int i = 0; i < 26; i++) {
        cout << alpha[i] << ' ';
    }

    return 0;
}