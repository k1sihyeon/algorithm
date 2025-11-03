#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int P;
    cin >> P;

    for (int i = 0; i < P; i++) {
        deque<int> student;
        int TC;
        int result = 0;

        cin >> TC;

        for (int j = 0; j < 20; j++) {
            int height;
            cin >> height;

            auto iter = find_if(student.begin(), student.end(), [height](int x) { return x > height; });
            
            if (iter == student.end()) {
                student.push_back(height);
            }
            else {
                result += (student.end() - iter); 
                student.insert(iter, height);
            }
        }

        cout << TC << " " << result << "\n";
    }

    return EXIT_SUCCESS;
}