#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;

int binarySearch(int num) {
    int low = 0;
    int high = ans.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (ans[mid] >= num) 
            high = mid;
        else
            low = mid + 1;
    }

    return high;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int result = 0;

    vector<int> v;
    
    cin >> N;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    ans.push_back(v.front()); 

    for (int i = 0; i < N; i++) {
        if (v[i] > ans.back()) {
            ans.push_back(v[i]);
        }
        else {
            int idx = binarySearch(v[i]);
            ans[idx] = v[i];
        }
    }

    cout << ans.size() << "\n";

    return EXIT_SUCCESS;
}