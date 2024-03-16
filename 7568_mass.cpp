#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int weight, height;
        cin >> weight >> height;
        v.push_back(make_pair(weight, height));
    }

    for (int i = 0; i < N; i++) {
        int rank = 1;

        for (int j = 0; j < N; j++) {
            if (v[i].first < v[j].first && v[i].second < v[j].second)
                rank++;
        }

        cout << rank << " ";
    }


    return 0;
}   