#include <iostream>

using namespace std;

int N;
int map[101][101];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            cin >> map[i][j];

    for (int m = 0; m < N; m++) 
        for (int s = 0; s < N; s++) 
            for (int e = 0; e < N; e++) 
                if (map[s][m] && map[m][e]) 
                    map[s][e] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cout << map[i][j] << " ";
        cout << "\n";
    }            

    return 0;
}