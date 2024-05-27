#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, vector<char> delimiters) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    char ch;

    while (tokenStream.get(ch)) {
        if (std::find(delimiters.begin(), delimiters.end(), ch) != delimiters.end()) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(std::string(1, ch));
        }
        else {
            token += ch;
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result;
    int minusIdx = 0;
    bool isMinus = false;

    string input;
    cin >> input;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '+' || input[i] == '-')
            minusIdx += 1;

        if (input[i] == '-') {
            isMinus = true;
            break;
        }
    }

    vector<char> delimiters = {'-', '+'};
    vector<string> tokens = split(input, delimiters);
    vector<int> nums;
    for (int i = 0; i < tokens.size(); i++) {
        try {
            nums.push_back(stoi(tokens[i]));
        } catch (const std::invalid_argument& e) {
            //cout << "Invalid argument: " << e.what() << '\n';
        }
    }

    if (minusIdx == 0 || !isMinus) {
        result = accumulate(nums.begin(), nums.end(), 0);
    }
    else {
        result = accumulate(nums.begin(), nums.begin() + minusIdx, 0);
        for (int i = minusIdx; i < nums.size(); i++) {
            result -= nums[i];
        }
    }

    cout << result << '\n';

    return 0;
}