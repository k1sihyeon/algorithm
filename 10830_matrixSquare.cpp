#include <iostream>

using namespace std;

long long N, B;
long long matrix[5][5];
long long result[5][5];

void multiplyMatrix(long long a[5][5], long long b[5][5]) {
    long long temp[5][5] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            temp[i][j] = 0;

            for (int k = 0; k < N; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }

            temp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = temp[i][j];
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //input
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cin >> matrix[i][j];
        
        result[i][i] = 1;
    }

    //calculate
    while (B > 0) {
        if (B % 2 == 1) 
            multiplyMatrix(result, matrix);

        multiplyMatrix(matrix, matrix);
        B /= 2;
    }

    //print
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cout << result[i][j] << ' ';
        
        cout << '\n';
    }


    return 0;
}