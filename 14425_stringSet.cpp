//TRIE

#include <bits/stdc++.h>
using namespace std;

#define ROOT 1
#define MAX 10000 * 500 + 5

int nodeId = 2;
//1은 root

bool check[MAX];
//nodeId가 단어의 마지막이면 true

int tree[MAX][26]; 
//tree[cur][ascii]: cur 다음으로 연결된 알파벳(ascii)위치에 노드번호 삽입

int N, M;

int ctoi(char c) {
    return c - 'A';
}

void insert(string s) {
    int cur = ROOT;

    for (int i = 0; i < (int)s.size(); i++) {
        if (tree[cur][ctoi(s[i])] == -1) {
            tree[cur][ctoi(s[i])] = nodeId;
            nodeId += 1;
        }

        cur = tree[cur][ctoi(s[i])];
    }

    check[cur] = true;
}

bool find(string s) {
    int cur = ROOT;

    for (int i = 0; i < (int)s.size(); i++) {
        if (tree[cur][ctoi(s[i])] == -1)
            return false;
        
        cur = tree[cur][ctoi(s[i])];
    }

    return check[cur];
}

void erase(string s) {
    int cur = ROOT;

    for (int i = 0; i < (int)s.size(); i++) {
        if (tree[cur][ctoi(s[i])] == -1)
            return;
        
        cur = tree[cur][ctoi(s[i])];
    }

    check[cur] = false;
    //이미 노드들의 id가 순차적으로 할당되어 있으므로
    //직접 삭제 어려움
    //따라서 check 만 변경
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //init
    int ans = 0;
    memset(check, false, sizeof(check));
    for (int i = 0; i < MAX; i++)
        fill(tree[i], tree[i]+26, -1);

    //input
    cin >> N >> M;

    //solve
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        
        if (find(s) == true)
            ans += 1;
    }

    cout << ans << "\n";

    return 0;
}