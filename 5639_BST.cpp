#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 10001;

vector<int> tree;

void post(int start, int end) {
    if (start >= end)
        return;

    int root = tree[start];
    int delim = start + 1;

    while (delim < end) {
        if (root < tree[delim])
            break;
        
        delim += 1;
    }

    post(start + 1, delim);
    post(delim, end);

    cout << root << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num = 0;
    while (cin >> num) {
        tree.push_back(num);
    }

    post(0, tree.size());

    return EXIT_SUCCESS;
}