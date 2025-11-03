#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> switches;

enum Gender {
    MALE = 1,
    FEMALE = 2,
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    switches.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        switches[i] = num;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int gen, num;
        cin >> gen >> num;

        if (gen == Gender::MALE) {
            for (int j = 1; j <= N/num; j++) {
                switches[j * num] = !switches[j * num]; 
            }
        }

        else if (gen == Gender::FEMALE) {

            switches[num] = !switches[num];
            
            int j = num - 1;
            int k = num + 1;

            while ((j >= 1) && (k <= N)) {
                if (switches[j] == switches[k]) {
                    switches[j] = !switches[j];
                    switches[k] = !switches[k];

                    j -= 1;
                    k += 1;
                }
                else {
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << switches[i] << " ";

        if ((i % 20) == 0)
            cout << "\n";
    }
    cout << "\n";

    return EXIT_SUCCESS;
}