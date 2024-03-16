#include <iostream>

using namespace std;

int A, B, V, result;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> V;

    result = (V - A) / (A - B);
    if ((V - A) % (A - B) != 0)
        result++;
    
    cout << result + 1;

    // time out

    // while (true) {
    //     result++;
    //     V -= A;
    //     if (V <= 0) {
    //         cout << result;
    //         break;
    //     }
    //     V += B;
    // }

    return 0;
}