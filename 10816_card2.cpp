#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> hand;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        hand.push_back(num);
    }

    sort(hand.begin(), hand.end());

    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        int cnt = upper_bound(hand.begin(), hand.end(), num) - lower_bound(hand.begin(), hand.end(), num); 
        cout << cnt << " ";
    }

    return 0;
}