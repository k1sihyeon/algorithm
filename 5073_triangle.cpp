#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string result;

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> sides;
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);

        sort(sides.begin(), sides.end());

        if ((a == 0) && (b == 0) && (c == 0))
            break;

        if (sides[2] >= sides[0] + sides[1]) {
            result = "Invalid";
        }
        else if ((a == b) && (b == c) && (c == a)) {
            result = "Equilateral";
        }
        else if ((a == b) || (b == c) || (c == a)) {
            result = "Isosceles";
        }
        else {
            result = "Scalene";
        }

        cout << result << "\n";
    }

    return EXIT_SUCCESS;
}