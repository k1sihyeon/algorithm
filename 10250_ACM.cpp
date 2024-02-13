#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int h, w, n;
        cin >> h >> w >> n;

        int floor = n % h;
        int room = n / h + 1;

        if(floor == 0) {
            floor = h;
            room -= 1;
        }

        cout << floor * 100 + room << '\n';
    }

    return 0;
}