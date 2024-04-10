#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> lines;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        lines.push_back({x, y});
    }

    sort(lines.begin(), lines.end());

    int start = lines[0].first;
    int end = lines[0].second;
    int sum = 0;

    for (int i = 1; i < N; i++) {
        //다음 줄의 시작이 이전 줄의 끝보다 작거나 같으면 이어짐 -> end만 갱신
        if (lines[i].first <= end)          
            end = max(end, lines[i].second);
        else { //이어지지 않으면 이전 줄의 길이를 더해주고 새로운 줄로 시작
            sum += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
    }

    sum += end - start;

    cout << sum << "\n";

    return 0;
}