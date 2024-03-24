#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int total, n, sum = 0;
    cin >> total;
    cin >> n;


    for (int i =0; i < n; i++) {
        int price, quantity;
        cin >> price >> quantity;
        sum += price * quantity;
    }

    if (sum == total)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';



    return 0;
}