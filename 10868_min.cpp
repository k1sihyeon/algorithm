#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
vector<int> arr;
//vector<int> maxTree;
vector<int> minTree;
vector<pair<int, int>> query;

void InitSegmentTree(int node, int start, int end) {
    if (start == end) {
        //maxTree[node] = arr[start];
        minTree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    InitSegmentTree(node * 2, start, mid);          //left node
    InitSegmentTree(node * 2 + 1, mid + 1, end);    //right node

    //maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);    
}

int UpdateSegmentTree(int node, int start, int end, int left, int right) {
    
    if (left > end || right < start) {
        return INT_MAX;
    }
    else if (left <= start && end <= right) {
        return minTree[node];
    }
    else {
        int mid = (start + end) / 2;
        int leftNode = UpdateSegmentTree(node * 2, start, mid, left, right);
        int rightNode = UpdateSegmentTree(node * 2 + 1, mid + 1, end, left, right);
        return min(leftNode, rightNode);
    }
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //input
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        query.push_back(make_pair(a, b));
    }

    //init tree
    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    //maxTree.resize(size);
    minTree.resize(size);

    InitSegmentTree(1, 0, N - 1);

    //query
    for (int i = 0; i < M; i++) {
        int left = query[i].first - 1;
        int right = query[i].second - 1;
        int result;
        
        result = UpdateSegmentTree(1, 0, N - 1, left, right);
        cout << result << "\n";
    }

    return 0;

}