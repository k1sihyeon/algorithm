#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> croatia = {
    "c=",
    "c-",
    "dz=",
    "d-",
    "lj",
    "nj",
    "s=",
    "z="
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string input;
    int result = 0;

    cin >> input;

    int idx = 0;
    while (input[idx] != '\0') {
        bool isFind = false;

        for (const auto & alphabet : croatia) {
            if ((int)alphabet.length() > (int)input.length() - idx)
                continue;

            if (alphabet == input.substr(idx, (int)alphabet.length())) {
                result += 1;
                isFind = true;
                idx += (int)alphabet.length();
                break;
            }
        }

        if (!isFind) {
            result += 1;
            idx += 1;
        }
    }

    cout << result << "\n";

    return EXIT_SUCCESS;
}