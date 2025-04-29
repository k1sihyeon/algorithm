#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007LL;

vector<vector<long long>> multiplyMatrix(vector<vector<long long>> &a, vector<vector<long long>> &b);

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N;
    cin >> N;

    vector<vector<long long>> res = {{1, 0}, {0, 1}};     // identity mat.
    vector<vector<long long>> a = {{1, 1}, {1, 0}};       // fibo mat.

    while (N > 0) {
        if ((N % 2) == 1)
            res = multiplyMatrix(res, a);
        
        a = multiplyMatrix(a, a);

        N /= 2;
    }

    cout << res[0][1] << "\n";

    return EXIT_SUCCESS;
}

vector<vector<long long>> multiplyMatrix(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    vector<vector<long long>> out;
    out.assign(2, vector<long long>(2));
    
    out[0][0] = ((a[0][0] * b[0][0]) + (a[0][1] * b[1][0])) % MOD;
    out[0][1] = ((a[0][0] * b[0][1]) + (a[0][1] * b[1][1])) % MOD;
    out[1][0] = ((a[1][0] * b[0][0]) + (a[1][1] * b[1][0])) % MOD;
    out[1][1] = ((a[1][0] * b[0][1]) + (a[1][1] * b[1][1])) % MOD;

    return out;
}