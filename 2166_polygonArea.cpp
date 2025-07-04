#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> polygon;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        polygon.push_back({x, y});        
    }

    // ShoeLace Formula
    long double result = 0.0;
    for (int i = 1; i < N-1; i++) {
        long double x1 = polygon[0].first;      long double y1 = polygon[0].second;
        long double x2 = polygon[i].first;      long double y2 = polygon[i].second;
        long double x3 = polygon[i+1].first;    long double y3 = polygon[i+1].second;

        result += static_cast<long double>((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)); 
    }

    result = abs(result);
    result /= static_cast<long double>(2.0);

    cout << fixed;
    cout.precision(1);
    cout << result << "\n";

    return EXIT_SUCCESS;
}