#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string apocalypse = "666";
    int count = 0;
    cin >> N;

    while (true) {
        if (to_string(count).find(apocalypse) != string::npos) //count에서 666을 찾으면 N - 1
            N -= 1;

        if (N == 0) {
            cout << count << "\n";
            break;
        }

        count += 1;
    }

    return 0;
}