#include <iostream>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;

    //init fibonacci
    pair<int, int> fibonacci[41];

    fibonacci[0] = make_pair(1, 0);
    fibonacci[1] = make_pair(0, 1);

    for(int i = 2; i < 41; i++) {
        int first = fibonacci[i - 1].first + fibonacci[i - 2].first;
        int second = fibonacci[i - 1].second + fibonacci[i - 2].second;
        
        fibonacci[i] = make_pair(first, second);
    }


    //input
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> N;

        cout << fibonacci[N].first << " " << fibonacci[N].second << '\n';
    }

    return 0;
}