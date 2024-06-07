/*
    금오공과대학교 컴퓨터공학과 20190231 김시현
    알고리즘 과제 2
    허프만 코드 압축 헤제 프로그램

    Input: encoded.txt, huffmanCodeTable.txt
    Output: decoded.txt
*/

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 허프만 코드 테이블로 디코딩
void Decode(vector<string> encoded, vector<pair<char, string>> huffmanCode, vector<string>& decoded) {
    for (int i = 0; i < (int)encoded.size(); i++) {
        string decode = "";
        string temp = "";

        for (int j = 0; j < (int)encoded[i].length(); j++) {
            temp += encoded[i][j];

            for (int k = 0; k < (int)huffmanCode.size(); k++) {
                if (temp == huffmanCode[k].second) {
                    decode += huffmanCode[k].first;
                    temp = "";
                    break;
                }
            }
        }
        decoded.push_back(decode);
    }
}

// 허프만 코드 테이블 파일 열기
int OpenHuffmanTable(string fileName, vector<pair<char, string>>& huffmanCode) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error: File not found" << endl;
        return 1;
    }

    cout << "\n== [" << fileName << "] Opened.. Printing.. ==" << endl;

    char data;
    string code;
    while (inputFile >> data >> code) {
        huffmanCode.push_back(make_pair(data, code));
        cout << data << " : " << code << endl;
    }

    inputFile.close();

    return 0;
}

// 입력 파일 열기
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

int main(void) {
    vector<pair<char, string>> huffmanCode; // 허프만 코드 테이블
    vector<string> encoded;                 // 입력 파일에서 읽을 데이터 - 인코딩된 문자열
    vector<string> decoded;                 // 디코딩된 문자열

    // 입력 파일 (인코딩된 파일) 열기
    if (OpenTxtFile("encoded.txt", encoded) == 1) {
        return 1;
    }

    // 허프만 코드 테이블 열기
    if (OpenHuffmanTable("huffmanCodeTable.txt", huffmanCode) == 1) {
        return 1;
    }

    // 디코딩
    Decode(encoded, huffmanCode, decoded);

    // 디코딩된 문자열 저장
    if (SaveTxtFile("decoded.txt", decoded) == 1) {
        return 1;
    }

    return 0;
}