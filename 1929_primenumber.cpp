#include <iostream>
using namespace std;
int N, M;

bool isPrime(int n) {
    if (n < 2) 
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) 
            return false;

    return true;

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = N; i <= M; i++)
        if (isPrime(i))
            cout << i << '\n';
            
    return 0;
}