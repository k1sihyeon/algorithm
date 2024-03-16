#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<int> v;
queue<int> q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        q.push(i);
    
    while (!q.empty()) {

        //K번째 앞까지의 숫자들을 뒤로 보내기        
        for (int i = 1; i < K; i++) {
            q.push(q.front());
            q.pop();
        }

        //K번째 숫자를 빼서 저장
        v.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i == (int)v.size() - 1)
            break;
        cout << ", ";
    }
    cout << ">" << "\n";

    return 0;
}