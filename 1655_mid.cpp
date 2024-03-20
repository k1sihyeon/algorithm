#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> v;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
//greater<int> : 내림차순, less<int> : 오름차순
//default는 less<int>임

void Game() {
    for (int i = 0; i < N; i++) {
        if (maxHeap.size() > minHeap.size())        //maxHeap이 더 크다면 minHeap에 push - 규칙 1
            minHeap.push(v[i]);
        else
            maxHeap.push(v[i]);
        
        if (!maxHeap.empty() && !minHeap.empty()) {
            if (maxHeap.top() > minHeap.top()) {    //maxHeap의 top이 더 크다면 swap - 규칙 2
                int maxTop = maxHeap.top();
                int minTop = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(maxTop);
            }
        }

        cout << maxHeap.top() << '\n';
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
        v.push_back(num);
    }

    Game();

    return 0;
}