#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    vector<string> words;
    string str, word;
    getline(cin, str);

    stringstream ss(str);
    while (ss >> word) {
        words.push_back(word);
    }

    cout  << words.size() << endl;

    return 0;
}
