#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> scores(N);
    vector<double> newScores(N);
    double sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    int maxScore = *max_element(scores.begin(), scores.end());
    
    for (int i = 0; i < N; i++) {
        newScores[i] = (double)scores[i] / maxScore * 100;
    }

    for(int i = 0; i < N; i++) {
        sum += newScores[i];
    }

    cout << sum / N << endl;

    return 0;
}
