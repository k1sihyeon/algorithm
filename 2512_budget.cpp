#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, thres;
    vector<int> provinces;
    long long sum = 0;

    // input
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        provinces.push_back(num);

        sum += num;
    }

    cin >> thres;

    // check
    if (sum <= thres) {
        auto maxIt = max_element(provinces.begin(), provinces.end());
        if (maxIt != provinces.end()) {
            cout << *maxIt << "\n";
        }

        return EXIT_SUCCESS;
    }

    // solve
    int low = 0;
    int high = *max_element(provinces.begin(), provinces.end());
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        long long tmpSum = 0;
        for (const auto &p : provinces)
            tmpSum += min(p, mid);
        
        if (tmpSum <= thres) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << result << "\n";

    return EXIT_SUCCESS;
}