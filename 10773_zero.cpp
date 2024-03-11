#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl '\n'

int K;
stack<int> s;

void Command(void) {
    int num;
    cin >> num;

    if (num == 0)
        s.pop();
    else
        s.push(num);
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;

    cin >> K;

    for (int i = 0; i < K; i++) {
        Command();
    }

    for (int i = 0; !s.empty(); i++) {
        result += s.top();
        s.pop();
    }

    cout << result << endl;

    return 0;
}