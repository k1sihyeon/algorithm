#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, string>> people;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        people.push_back(make_pair(age, name));
    }

    stable_sort(people.begin(), people.end(), compare);

    for (int i = 0; i < N; i++)
        cout << people[i].first << ' ' << people[i].second << '\n';

    return 0;
}