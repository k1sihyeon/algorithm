#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
//greater<int> -> 오름차순 정렬
//sort등에서도 사용가능

//greater<int> 대신 cmp 구조체를 만들어서 사용 가능
/*
    struct cmp{
    bool operator()(int a, int b) {
        return a > b;   //오름차순
        }
    };
*/

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (pq.empty())
                cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }

    }

    return 0;
}