/*
    금오공과대학교 컴퓨터공학과 20190231 김시현
    알고리즘 과제 2
    허프만 코드 압축 프로그램

    Input: input.txt
    Output: encoded.txt, huffmanCodeTable.txt
*/

#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define RESERVED 126    // 새 부모 노드 N의 예약된 data 값

// 허프만 트리 노드 구조체
typedef struct node {
    char data;
    int freq;
    struct node* left;
    struct node* right;
} node;

// 허프만 트리 노드 포인터
typedef struct node* nodePtr;

// 노드 생성자
nodePtr createNode(char data, int freq, nodePtr left, nodePtr right) {
    nodePtr n = new node;
    n->data = data;
    n->freq = freq;
    n->left = left;
    n->right = right;

    return n;
}

// 우선순위 큐 비교자
struct compare {
    bool operator()(nodePtr a, nodePtr b) {
        return a->freq > b->freq;
    }
};

// 중위 순회로 출력
nodePtr inorder(nodePtr root) {
    if (root != NULL) {
        inorder(root->left);

        if (root->data != RESERVED)
            cout << root->data << " : " << root->freq << endl;

        inorder(root->right);
    }
    return root;
}

// 허프만 코드 테이블 생성
void Huffman(nodePtr root, string code, vector<pair<char, string>>& huffmanCode) {
    if (root->data != RESERVED) {
        huffmanCode.push_back(make_pair(root->data, code));
    }

    else if (root != NULL) {
        Huffman(root->left, code + "0", huffmanCode);
        Huffman(root->right, code + "1", huffmanCode);
    }
}

// 허프만 코드로 압축
void Encode(vector<string> input, vector<pair<char, string>> huffmanCode, vector<string>& output) {
    for (int i = 0; i < (int)input.size(); i++) {
        string encode = "";

        for (int j = 0; j < (int)input[i].length(); j++) {
            for (int k = 0; k < (int)huffmanCode.size(); k++) {

                if (input[i][j] == huffmanCode[k].first) {
                    encode += huffmanCode[k].second;
                    break;
                }
            }
        }
        output.push_back(encode);
    }
}

// 허프만 코드 테이블 파일 저장
int SaveHuffmanTable(string fileName, vector<pair<char, string>> huffmanCode) {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    cout << "\n== [" << fileName << "] Saving.. ==" << endl;
    for (int i = 0; i < (int)huffmanCode.size(); i++) {
        outputFile << huffmanCode[i].first << " " << huffmanCode[i].second << endl;
        cout << huffmanCode[i].first << " " << huffmanCode[i].second << endl;
    }

    outputFile.close();

    if (outputFile.fail()) {
        cerr << "Error occurred while closing the file." << endl;
        return 1;
    }

    cout << "File written successfully." << endl;
    return 0;
}

// 입력 파일 읽기
int OpenTxtFile(string fileName, vector<string>& data) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error: File not found" << endl;
        return 1;
    }

    cout << "\n== [" << fileName << "] Opened.. Printing.. ==" << endl;

    string line;
    while (getline(inputFile, line)) {
        data.push_back(line);
        cout << line << endl;
    }

    inputFile.close();

    return 0;
}

// 출력 파일 저장
int SaveTxtFile(string fileName, vector<string> data) {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    cout << "\n== [" << fileName << "] Saving.. ==" << endl;
    for (int i = 0; i < (int)data.size(); i++) {
        outputFile << data[i] << endl;
        cout << data[i] << endl;
    }

    outputFile.close();

    if (outputFile.fail()) {
        cerr << "Error occurred while closing the file." << endl;
        return 1;
    }

    cout << "File written successfully." << endl;
    return 0;
}

// 메인 함수
int main(void) {
    priority_queue<nodePtr, vector<nodePtr>, compare> pq;   // 우선순위 큐
    vector<pair<char, string>> huffmanCode;                 // 허프만 코드 테이블
    vector<string> input;                                // 입력 파일에서 읽은 데이터
    vector<string> encoded;                             // 압축된 출력 파일에 저장할 데이터

    // 아스키 코드 빈도수 저장하는 배열
    int ascii[256] = {0, };
    memset(ascii, 0, sizeof(ascii));

    // 파일 읽어서 input에 저장
    if (OpenTxtFile("input.txt", input) == 1)
        return 1;

    // 아스키 코드 빈도수 계산
    for (int i = 0; i < (int)input.size(); i++) {
        for (int j = 0; j < (int)input[i].length(); j++) {
            ascii[input[i][j]] += 1;
        }
    }

    // 각 문자별 단말 노드 생성
    for (int i = 0; i < 256; i++) {
        if (ascii[i] > 0) {
            nodePtr n = createNode(i, ascii[i], NULL, NULL);
            pq.push(n);
        }
    }

    while (pq.size() > 1) {
        // 빈도수가 가장 작은 두 노드 제거
        nodePtr a = pq.top();
        pq.pop();

        nodePtr b = pq.top();
        pq.pop();

        // 두 노드를 자식 노드로 하는 새로운 노드 생성 및 삽입
        nodePtr n = createNode(RESERVED, a->freq + b->freq, a, b);
        pq.push(n);
    }

    // 중위 순회로 출력
    inorder(pq.top());

    // 허프만 코드 압축하여 huffmanCode에 저장
    Huffman(pq.top(), "", huffmanCode);

    // huffmanCode를 huffmanTable.txt에 저장
    if (SaveHuffmanTable("huffmanCodeTable.txt", huffmanCode) == 1)
        return 1;

    // huffmanCode 통해 input을 압축하여 encoded에 저장
    Encode(input, huffmanCode, encoded);

    // encoeed를 encoded.txt에 저장
    if (SaveTxtFile("encoded.txt", encoded) == 1)
        return 1;
    
    return 0;
}