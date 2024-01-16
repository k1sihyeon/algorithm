#include <iostream>
#include <vector>

using namespace std;

struct node {
    char left;
    char right;
};

node v[27];

void preorder(char node) {
    if (node == '.') return;
    int idx = node - 'A';

    cout << node;
    preorder(v[idx].left);
    preorder(v[idx].right);
}

void inorder(char node) {
    if (node == '.') return;
    int idx = node - 'A';

    inorder(v[idx].left);
    cout << node;
    inorder(v[idx].right);
}  

void postorder(char node) {
    if (node == '.') return;
    int idx = node - 'A';

    postorder(v[idx].left);
    postorder(v[idx].right);
    cout << node;
}

int main(void) {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        v[a - 'A'].left = b;
        v[a - 'A'].right = c;
    }

    preorder('A');    cout << "\n";
    inorder('A');     cout << "\n";
    postorder('A');   

    return 0;
}