#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

bool NUMcomp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool IDXcomp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    //input - num, idx
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(make_pair(num, i));
    }

    sort(v.begin(), v.end(), NUMcomp);   //num 기준 오름차순 정렬

    //초기값 할당
    int preNum = v[0].first;
    int num = 0;
    v[0].first = 0;

    for (int i = 1; i < N; i++) {
        if (preNum == v[i].first)   //이전 값과 같으면 같은 값 할당
            v[i].first = num;

        else {                      //이전 값과 다르면 새로운 값 할당
            num += 1;
            preNum = v[i].first;
            v[i].first = num;
        }
    }

    sort(v.begin(), v.end(), IDXcomp); //idx 기준 오름차순 정렬

    for (int i = 0; i < N; i++)
        cout << v[i].first << " ";

    return 0;
}