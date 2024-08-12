#include <bits/stdc++.h>

using namespace std;

vector<int> dist;
vector<int> price;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int num;
        cin >> num;

        dist.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        price.push_back(num);
    }
    
    long long minPrice = price[0];
    unsigned long long ans = minPrice * dist[0];

    for (int i = 1; i < N-1; i++) {
        if (price[i] < minPrice) {
            minPrice = price[i];
            ans += minPrice * dist[i];
        }
        else 
            ans += minPrice * dist[i];
    }

    cout << ans << "\n";

    return 0;
}