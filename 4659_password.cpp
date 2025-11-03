#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char ch);
bool isContainVowel(string &str);
bool isOver3InRow(string &str);
bool isDouble(string &str);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        string input;
        cin >> input;

        if (input == "end")
            break;

        if (!isContainVowel(input)) {
            goto NO_ACCEPT;
        }
        else if (isOver3InRow(input)) {
            goto NO_ACCEPT;
        }
        else if (isDouble(input)) {
            goto NO_ACCEPT;
        }
        else {
            goto ACCEPT;
        }

ACCEPT:;
        cout << "<" << input << "> is acceptable." << "\n";
        continue;

NO_ACCEPT:;
        cout << "<" << input << "> is not acceptable." << "\n";
        continue;
    }

    return EXIT_SUCCESS;
}

//

bool isVowel(char ch) {
    return find(vowel.begin(), vowel.end(), ch) != vowel.end();
}

bool isContainVowel(string &str) {
    return any_of(str.begin(), str.end(), [](char ch) {
        return isVowel(ch);
    });
}

bool isOver3InRow(string &str) {
    int vCount = 0;     // vowel
    int cCount = 0;     // consonant

    for (char ch : str) {
        if (isVowel(ch)) {
            vCount += 1;
            cCount = 0;
        }
        else {
            cCount += 1;
            vCount = 0;
        }

        if ((vCount >= 3) || (cCount >= 3))
            return true;
    }

    return false;
}

bool isDouble(string &str) {
    for (int i = 1; i < (int)str.length(); i++) {
        if (str[i - 1] == str[i]) {
            if ((str[i] == 'e') || (str[i] == 'o')) {
                return false;
            }

            return true;
        }
    }

    return false;
}