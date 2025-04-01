#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int A, B;

int op1(int n) {
    return n / 2;
}

int op2 (int n) {
    return n / 10;
}

int BFS() {
    queue<pair<int, int>> q;
    q.push({B, 1});

    int result = -1;

    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // cout << num << " | " << cnt << "\n";

        if (num == A) {
            result = cnt;
            return result;
        }

        if (num > A) {
            if (num % 2 == 0) {
                q.push({op1(num), cnt+1});
            }

            else if (num % 10 == 1) {
                q.push({op2(num), cnt+1});
            }
        }
    }

    return result;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B;

    cout << BFS() << "\n";
    
    return EXIT_SUCCESS;
}