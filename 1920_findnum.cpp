#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001];

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        if (binary_search(arr, arr + N, num))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}