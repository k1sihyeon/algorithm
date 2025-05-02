#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (pq.size() > 1) {
        int n1, n2;

        n1 = pq.top();  pq.pop();
        n2 = pq.top();  pq.pop();

        result += (n1 + n2);
        pq.push(n1 + n2);
    }

    cout << result << "\n";

    return EXIT_SUCCESS;
}