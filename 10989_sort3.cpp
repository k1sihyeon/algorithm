#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(10001, 0);

int N;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v[num] += 1;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << i << "\n";
        }
    }

    return 0;
}