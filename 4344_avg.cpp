#include <iostream>

using namespace std;

int main(void) {

    int C;
    cin >> C;

    for(int i = 0; i < C; i++) {
        int N;
        cin >> N;

        int score[N];
        int sum = 0;
        double avg = 0;
        int cnt = 0;

        for(int j = 0; j < N; j++) {
            cin >> score[j];
            sum += score[j];
        }

        avg = (double)sum / N;
        
        for(int j = 0; j < N; j++) {
            if(score[j] > avg)
                cnt += 1;
        }

        cout << fixed;
        cout.precision(3);
        cout << (double)cnt / N * 100 << "%" << endl;
    }

    return 0;
}