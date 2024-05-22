#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T;
int a, b;
//bool visited[10000];
vector<bool> visited(10000, false);
string result;


int D (int n) {
    return (n * 2) % 10000;
}

int S (int n) {
    if (n == 0) 
        return 9999;
    return n - 1;
}

int L (int n) {
    return (n % 1000) * 10 + n / 1000;
}

int R (int n) {
    return (n % 10) * 1000 + n / 10;
}

void BFS(void) {
    queue<pair<int, string>> q; //숫자, 명령어 pair
    q.push({a, ""});
    visited[a] = true;

    while (!q.empty()) {
        int num = q.front().first;
        string str = q.front().second;
        q.pop();

        if (num == b) {
            result = str;
            return;
        }

        int next = D(num);
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, str + "D"});
        }

        next = S(num);
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, str + "S"});
        }

        next = L(num);
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, str + "L"});
        }

        next = R(num);
        if (!visited[next]) {
            visited[next] = true;
            q.push({next, str + "R"});
        }

    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a >> b;

        //memset(visited, false, sizeof(visited));
        fill(visited.begin(), visited.end(), false);

        BFS();

        cout << result << '\n';
    }

    return 0;
}