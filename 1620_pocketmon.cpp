#include <iostream>
#include <map>
#include <cctype>

using namespace std;

int N, M;
map<string, int> pocketmonMap;
string pocketmonArr[100001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string name;
        cin >> name;
        pocketmonMap[name] = i + 1;
        pocketmonArr[i + 1] = name;
    }

    for (int i = 0; i < M; i++) {
        string query;
        cin >> query;

        if (isdigit(query[0])) {
            int idx = stoi(query);
            cout << pocketmonArr[idx] << '\n';
        }
        else {
            cout << pocketmonMap[query] << '\n';
        }
    }

    return 0;
}