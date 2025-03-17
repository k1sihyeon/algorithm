#include <iostream>
#include <set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int k;
        cin >> k;

        multiset<int> ms;

        for (int j = 0; j < k; j++) {
            char op;
            int num;

            cin >> op;
            cin >> num;

            if (op == 'I') {
                ms.insert(num);
            }
            else if (op == 'D') {
                if (!ms.empty()) {
                    if (num == 1) {
                        auto iter = ms.end();
                        iter--;
                        ms.erase(iter);
                    }
                    else if (num == -1) {
                        ms.erase(ms.begin());
                    }
                }
            }
            else {
                // err
            }
        }

        if (ms.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << "\n";
        }
    }

    return EXIT_SUCCESS;
}