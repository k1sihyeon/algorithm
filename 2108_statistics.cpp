#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
vector<int> plusv(4001, 0);
vector<int> minusv(4001, 0);

int mode() {

    if (v.size() == 1)
        return v[0];

    int plusMax, minusMax, mode;    
    plusMax = *max_element(plusv.begin(), plusv.end());
    minusMax = *max_element(minusv.begin(), minusv.end());
    mode = max(plusMax, minusMax);

    vector<int> modev;

    for (int i = 0; i < 4001; i++) {
        if (plusv[i] == mode)
            modev.push_back(i);

        if (minusv[i] == mode) 
            modev.push_back(-i);
    }

    sort(modev.begin(), modev.end());

    if (modev.size() == 1)
        return modev[0];
    else
        return modev[1];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);

        sum += num;

        if (num < 0)
            minusv[-num] += 1;
        else
            plusv[num] += 1;
    }

    sort(v.begin(), v.end());

    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());

    cout << floor((double)sum / N + 0.5) << '\n';
    cout << v[N / 2] << '\n';
    cout << mode() << '\n';
    cout << max - min << '\n';

    return 0;
}