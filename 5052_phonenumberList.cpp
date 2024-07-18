#include <bits/stdc++.h>
using namespace std;

#define ROOT 1
#define MAX 10000 * 10 + 5

int tree[MAX][10];
bool isLast[MAX];
int nodeId = ROOT + 1;

int T, N;

int ctoi(char c) {
    return c - '0';
}

bool insert(string s) {
    int cur = ROOT;

    for (int i = 0; i < (int)s.size(); i++) {
        if (tree[cur][ctoi(s[i])] == -1) {
            tree[cur][ctoi(s[i])] = nodeId;
            nodeId += 1;
        }

        cur = tree[cur][ctoi(s[i])];

        //트리에 추가된 곳이 이미 다른 단어의 마지막 일 경우
        if (isLast[cur])
            return false;
    }

    //다른 단어와 중복되어 저장되었을 경우
    if (cur != nodeId - 1)
        return false;

    isLast[cur] = true;

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++) {
        // init
        bool isValid = true;
        nodeId = ROOT + 1;
        for (int i = 0; i < MAX; i++)
            fill(tree[i], tree[i] + 10, -1);
        memset(isLast, false, sizeof(isLast));

        // input
        cin >> N;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;

            if (!insert(s))
                isValid = false;
        }

        if (isValid)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}