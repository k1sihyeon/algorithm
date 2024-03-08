#include <iostream>

using namespace std;

int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }
    
    int layer = 1;
    for(int sum = 2; sum <= N; layer++) 
        sum += 6 * layer;

    cout << layer << "\n";

    return 0;
}