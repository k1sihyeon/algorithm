#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str, bomb, buffer;

    cin >> str;
    cin >> bomb;

    for (const auto &c : str) {
        buffer += c;

        if (buffer.length() < bomb.length()) 
            continue;

        bool isBomb = true;
        
        for (int i = 0; i < bomb.length(); i++) {
            if (buffer[buffer.length() - bomb.length() + i] != bomb[i]) {
                isBomb = false;
                break;
            }
        }

        if (isBomb) 
            buffer.erase(buffer.end() - bomb.length(), buffer.end());
    }

    if (buffer.empty())
        cout << "FRULA" << "\n";
    else
        cout << buffer << "\n";

    return EXIT_SUCCESS;
}