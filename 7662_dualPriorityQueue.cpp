#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        priority_queue<int, vector<int>, greater<int>> ascQ;
        priority_queue<int, vector<int>, less<int>> desQ;
        map<int, int> count;

        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            char op;
            int num;

            cin >> op;
            cin >> num;
            
            if (op == 'I') {
                ascQ.push(num);
                desQ.push(num);
                count[num] += 1;
            }

            else if (op == 'D') {
                if (num == 1) {
                    if (!desQ.empty()) {
                        count[desQ.top()] -= 1;
                        desQ.pop();
                    }
                }

                else if (num == -1) {
                    if (!ascQ.empty()) {
                        count[ascQ.top()] -= 1;
                        ascQ.pop();
                    }
                }

                while (!desQ.empty() && count[desQ.top()] == 0)
                    desQ.pop();
                
                while (!ascQ.empty() && count[ascQ.top()] == 0)
                    ascQ.pop();
            }
            else {

            }
        }

        while (!desQ.empty() && count[desQ.top()] == 0)
            desQ.pop();

        while (!ascQ.empty() && count[ascQ.top()] == 0)
            ascQ.pop();

        if (ascQ.empty() || desQ.empty())
            cout << "EMPTY" << "\n";
        else
            cout << desQ.top() << " " << ascQ.top() << "\n";
    }

    return EXIT_SUCCESS;
}
