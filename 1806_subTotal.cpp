#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int start = 0, end = 0, sum = v[0], result = 100001;

    while (start <= end && end < N) {
        if (sum < S) {
            end += 1;
            sum += v[end];
        }
        else if (sum == S) {
            result = min(result, end - start + 1);
            
            end += 1;
            sum += v[end];
        }
        else if (sum > S) {
            result = min(result, end - start + 1);

            sum -= v[start];
            start += 1;
        }
    }

    if (result == 100001) 
        cout << 0 << '\n';
    else 
        cout << result << '\n';
    
    return 0;
}