#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> table;
int result = 0;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        table.push_back(num);
    }

    for(int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = table[i] + table[j] + table[k];

                if (sum == M) {
                        cout << sum << '\n';
                        return 0;
                }

                if (sum < M) {
                    if (M - sum < M - result)
                        result = sum;
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}