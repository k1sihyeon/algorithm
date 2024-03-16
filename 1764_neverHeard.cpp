#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<string, int> heard;
map<string, int> seen;
vector<string> result;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        heard.insert(make_pair(str, i));
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        seen.insert(make_pair(str, i));
    }

    int count = 0;

    for (auto it = heard.begin(); it != heard.end(); it++) {
        if (seen.find(it->first) != seen.end()) {
            count++;
            result.push_back(it->first);
        }
    }

    cout << count << "\n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";

    return 0;
}