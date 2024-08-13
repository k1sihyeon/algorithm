#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, bool> a, pair<int, bool> b) {
        if (a.first == b.first) {
            int tmpA = a.first;
            int tmpB = b.first;

            if (!a.second)
                tmpA *= -1;
            if (!b.second)
                tmpB *= -1;
            
            return tmpA > tmpB;
        }
        else
            return a.first > b.first;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<pair<int, bool>, vector<pair<int, bool>>, cmp> pq;
    //priority_queue<pair<int, bool>> pq;    
    //true -> +
    //false -> -

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
                continue;
            }

            if (pq.top().second)
                cout << pq.top().first << "\n";
            else
                cout << pq.top().first * (-1) << "\n";
            
            pq.pop();
            continue;
        }

        if (num < 0)
            pq.push({abs(num), false});
        else
            pq.push({abs(num), true});
    }

    return 0;
} 