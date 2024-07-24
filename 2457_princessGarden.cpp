#include <bits/stdc++.h>

using namespace std;

class flower {
   public:
    int _life;
    int _startDate;
    int _endDate;

   public:
    flower(int life = 0, int startDate = 0, int endDate = 0) {
        _life = life;
        _startDate = startDate;
        _endDate = endDate;
    }
};

int countDates(int month, int date);
bool cmp_bloom(flower f1, flower f2);
bool cmp_fall(flower f1, flower f2);

int N;
int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<flower> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int stm, std, enm, end;
        cin >> stm >> std >> enm >> end;

        int startD = countDates(stm, std);
        int endD = countDates(enm, end);
        int life = startD - endD;

        flower f = flower(life, startD, endD);
        v.push_back(f);
    }

    if (v.size() == 1) {
        if ((countDates(3, 1) >= v[0]._startDate) && (countDates(12, 1) <= v[0]._endDate)) {
            cout << 1 << "\n";
            return 0;
        }
    }

    //빨리 피는 순서
    sort(v.begin(), v.end(), cmp_bloom);
    if (v.front()._startDate > countDates(3, 1)) {
        cout << 0 << "\n";
        return 0;
    }

    //늦게 지는 순서
    sort(v.begin(), v.end(), cmp_fall);
    if (v.front()._endDate <= countDates(11, 30)) {
        cout << 0 << "\n";
        return 0;
    }

    int cur = countDates(3, 1);
    int ans = 0;

    while (cur < countDates(12, 1)) {
        int next = cur;

        for (int i = 0; i < N; i++) {
            if ((v[i]._startDate <= cur) && (v[i]._endDate > next))
                next = v[i]._endDate;
        }

        if (next == cur) {
            cout << 0 << "\n";
            return 0;
        }

        ans += 1;
        cur = next;
    }

    cout << ans << "\n";

    return 0;
}

int countDates(int month, int date) {
    int count = date;

    for (int i = 1; i < month; i++) {
        count += months[i];
    }

    return count;
}

bool cmp_bloom(flower f1, flower f2) {
    if (f1._startDate == f2._endDate)
        return f1._endDate < f2._endDate;

    return f1._startDate < f2._startDate;
}

bool cmp_fall(flower f1, flower f2) {
    return f1._endDate > f2._endDate;
}