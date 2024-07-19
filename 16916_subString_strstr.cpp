#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    if ((strstr(a.c_str(), b.c_str()) != NULL))
        cout << "1" << "\n";
    else
        cout << "0" << "\n";

    return 0;
}