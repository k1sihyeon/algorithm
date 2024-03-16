#include <iostream>
#include <vector>

using namespace std;

int T;
vector<vector<int>> apartment(15, vector<int>(15, 0));

int main(int argc, char* argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        int k, n;
        cin >> k >> n;

        for (int j = 0; j < 15; j++) {
            apartment[0][j] = j;
            apartment[j][0] = 0;
        }

        for (int j = 1; j < 15; j++) {
            for (int k = 1; k < 15; k++) {
                apartment[j][k] = apartment[j][k - 1] + apartment[j - 1][k];
            }
        }

        cout << apartment[k][n] << "\n";
    }


    return 0;
}