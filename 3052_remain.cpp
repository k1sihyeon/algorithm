#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int n;
    set <int> s;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 10; i++) {
        cin >> n;
        s.insert(n % 42);
    }

    cout << s.size() << '\n';
    
    return 0;
}