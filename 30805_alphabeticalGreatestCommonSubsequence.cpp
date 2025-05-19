#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int idxA = 0;
    int idxB = 0;

    vector<int> A;
    vector<int> B;
    vector<int> result;

    cin >> N;
    A.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> M;
    B.assign(M, 0);

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    //

    while ((idxA < N) && (idxB < M)) {
        int ax = idxA;
        int bx = idxB;
        int maxN = 0;

        for (int i = idxA; i < N; i++) {
            for (int j = idxB; j < M; j++) {
                if ((A[i] == B[j]) && (A[i] > maxN)) {
                    maxN = A[i];
                    ax = i;
                    bx = j;
                }
            }
        }

        if (maxN == 0)
            break;
        
        result.push_back(maxN);
        idxA = ax + 1;
        idxB = bx + 1;
    }

    cout << result.size() << "\n";
    for (const auto & r : result)
        cout << r << " ";

    return EXIT_SUCCESS;
}