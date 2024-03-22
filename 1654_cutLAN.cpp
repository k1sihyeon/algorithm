#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
vector<long long> v;

long long CUT() {
    long long max = v[K - 1];
    long long left = 1, right = max;
    long long mid, result = 0;

    while (left <= right) {
        mid = (left + right) / 2;

        long long div = 0;

        for (int i = 0; i < K; i++)
            div += v[i] / mid;

        if (div >= N) {
            left = mid + 1;
            
            if (mid > result)
                result = mid;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    
    long long result = CUT();
    cout << result << '\n';

    return 0;
}