#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;

void game() {
    int size = pq.size() / 2;

    if (size < 1) {
        cout << pq.top() << '\n';
        return;
    }
    else {
        vector<int> v; //짝수일 때 중간값을 찾기 위한 벡터
        for (int i = 0; i < size; i++) {
            v.push_back(pq.top());
            pq.pop();
        }
        
        cout << pq.top() << '\n';

        for (int i = 0; i < size; i++) {
            pq.push(v[i]);
        }
    }

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
        game();
    }

    return 0;
}