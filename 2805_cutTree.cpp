#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> trees;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tree;
        cin >> tree;
        trees.push_back(tree);
    }

    sort(trees.begin(), trees.end());
    int max = *max_element(trees.begin(), trees.end());

    int left = 0;
    int right = max;
    long long sum = 0;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        sum = 0;

        for (int i = 0; i < N; i++) {
            if (trees[i] > mid)
                sum += trees[i] - mid;
        }

        if (sum >= M) {
            result = mid;
            left = mid + 1;
        }
        // else if (sum == M)
        //     result = mid;
        else {
            right = mid - 1;
        }
    }

    cout << result << '\n';

    return 0;
}