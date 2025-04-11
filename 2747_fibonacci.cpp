#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> fibonacci(46, 0);
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= 45; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    int N;
    cin >> N;

    cout << fibonacci[N] << "\n";

    return EXIT_SUCCESS;
}