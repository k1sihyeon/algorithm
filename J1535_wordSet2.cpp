#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);

    while(getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);

    vector<string> v;
    set<string> s;

    while (true) {

        string line;
        getline(cin, line);

        if (line == "END")
            return 0;
        
        vector<string> words = split(line, ' ');

        for (const auto& w: words) {
            if (s.count(w) == 0) {
                s.insert(w);
                v.push_back(w);
            }
        }

        for (const auto& w : v)
            cout << w << " ";

        cout << "\n";
    }

    return 0;
}