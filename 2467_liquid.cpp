#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> bottle;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        bottle.push_back(num);
    }

    int left = 0;
    int right = N - 1;
    int value = INT32_MAX;

    int resultL = bottle[left];
    int resultR = bottle[right];

    while (left < right) {
        int sum = bottle[left] + bottle[right];

        if (value > abs(sum)) {
            value = abs(sum);

            resultL = bottle[left];
            resultR = bottle[right];
        }

        if (sum < 0)
            left += 1;
        else if (sum > 0)
            right -= 1;
        else    // sum == 0
            break;
    }

    cout << resultL << " " << resultR << "\n";

    return EXIT_SUCCESS;
}