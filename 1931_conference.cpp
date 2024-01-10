#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    } 

    sort(v.begin(), v.end(), cmp);

    int count = 1;
    pair<int, int> cur = v[0];

    for(auto iter = v.begin() + 1; iter != v.end(); iter++) {
        pair<int, int> next = (*iter);

        if(cur.second <= next.first) {
            count++;
            cur = next;
        }
    }

    cout << count << endl;
}