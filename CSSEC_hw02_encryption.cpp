#include <iostream>
#include <string>

using namespace std;

#define ALPHABET 26                                         //알파벳 갯수

string AddtiveEncryption(string plain, int key);            //덧셈 암호 Encryption
string AdditiveDecryption(string cipher, int key);          //덧셈 암호 Decryption

string MultiplicativeEncryption(string plain, int key);     //곱셈 암호 Encryption
string MultiplicativeDecryption(string cipher, int key);    //곱셈 암호 Decryption

string AffineEncryption(string plain, int key1, int key2);  //아핀 암호 Encryption - key1: 곱셈키, key2: 덧셈키
string AffineDecryption(string cipher, int key1, int key2); //아핀 암호 Decryption - key1: 곱셈키, key2: 덧셈키

int GCD(int a, int b);                                      //최대공약수
int MultiplicativeInverse(int r1, int r2, int t1, int t2);  //곱셈 역원
int getInverseKey(int key);                                 //곱셈 암호 키 역원 구하기
string TOLOWER(string str);                                 //소문자로 변환
string TOUPPER(string str);                                 //대문자로 변환

//////////////////////////////

int main(void) {

    //plain text는 소문자만
    //cipher text는 대문자만

    string plain;

    int key1;   //곱셈 암호 키
    int key2;   //덧셈 암호 키

    //평문 및 키 입력
    cout << "Input Plain text >> "; cin >> plain;
    cout << "Input key1, key2 >> "; cin >> key1 >> key2;

    //key1 역원 검사
    if (GCD(ALPHABET, key1) != 1) {
        cout << "[ERR] KEY1 HAS NO INVERSE" << "\n";
        return -1;
    }

    //평문 소문자로 변환
    plain = TOLOWER(plain);

    //덧셈 암호
    string addCipher = AddtiveEncryption(plain, key2);
    cout << "[Additive] \t Encrypted text : " << addCipher << "\n";

    string addPlain = AdditiveDecryption(addCipher, key2);
    cout << "[Additive] \t Decrypted text : " << addPlain << "\n";

    //곱셈 암호
    string mulCipher = MultiplicativeEncryption(plain, key1);
    cout << "[Multiplicative] Encrypted text : " << mulCipher << "\n";

    string mulPlain = MultiplicativeDecryption(mulCipher, key1);
    cout << "[Multiplicative] Decrypted text : " << mulPlain << "\n";

    //아핀 암호
    string affCipher = AffineEncryption(plain, key1, key2);
    cout << "[Affine] \t Encrypted text : " << affCipher << "\n";

    string affPlain = AffineDecryption(affCipher, key1, key2);
    cout << "[Affine] \t Decrypted text : " << affPlain << "\n";

    return 0;
}

//////////////////////////////

string AddtiveEncryption(string plain, int key) {
    string cipher = "";

    for (int i = 0; i < (int)plain.size(); i++) {
        char c = plain[i] - 'a';
        c = (c + key) % ALPHABET + 'A';

        cipher += c;
    }

    return cipher;
}

string AdditiveDecryption(string cipher, int key) {
    string plain = "";

    for (int i = 0; i < (int)cipher.size(); i++) {
        char c = cipher[i] - 'A';
        c = (c - key) % ALPHABET;
        
        //모듈러 연산 결과가 음수일 경우
        if (c < 0)
            c += ALPHABET;
        
        c += 'a';

        plain += c;
    }

    return plain;
}

string MultiplicativeEncryption(string plain, int key) {
    string cipher = "";

    for (int i = 0; i < (int)plain.size(); i++) {
        char c = plain[i] - 'a';
        c = (c * key) % ALPHABET + 'A';

        cipher += c;
    }

    return cipher;
}

string MultiplicativeDecryption(string cipher, int key) {
    int inverseKey = getInverseKey(key);
    if (inverseKey == -1)
        return "[ERR] KEY HAS NO INVERSE";            //inverse key == -1이면 GCD != 1 따라서 역원 존재 X

    string plain = "";

    for (int i = 0; i < (int)cipher.size(); i++) {
        char c = cipher[i] - 'A';
        c = (c * inverseKey) % ALPHABET + 'a';
  
        plain += c;
    }

    return plain;    
}

string AffineEncryption(string plain, int key1, int key2) {
    string cipher = MultiplicativeEncryption(plain, key1);
    cipher = TOLOWER(cipher);   //Encryption은 소문자만 받을 수 있음
    cipher = AddtiveEncryption(cipher, key2);

    return cipher;
}

string AffineDecryption(string cipher, int key1, int key2) {
    string plain = AdditiveDecryption(cipher, key2);
    plain = TOUPPER(plain);     //Decryption은 대문자만 받을 수 있음
    plain = MultiplicativeDecryption(plain, key1);

    return plain;
}

//////////////////////////////

int GCD(int a, int b) {     //최대공약수
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

//곱셈 역원 : 확장 유클리드 알고리즘 이용
int MultiplicativeInverse(int r1, int r2, int t1, int t2) {
    //종료조건 : gcd = r1 = 1 이 되는 순간
    if (r1 == 1)
        return t1;
    
    int q = r1 / r2;
    int r = r1 - q * r2;
    int t = t1 - q * t2;

    //재귀호출
    return MultiplicativeInverse(r2, r, t2, t);    
}

int getInverseKey(int key) {        //곱셈 암호 키 역원 구하기
    //최대공약수 != 1 이면 역원 존재 X
    if (GCD(ALPHABET, key) != 1)
        return -1;

    int inverseKey = MultiplicativeInverse(ALPHABET, key, 0, 1);

    if (inverseKey < 0)
        inverseKey += ALPHABET;

    return inverseKey;
}

string TOLOWER(string str) {    //소문자로 변환
    string lower = "";

    for (int i = 0; i < (int)str.size(); i++)
        lower += tolower(str[i]);

    return lower;
}

string TOUPPER(string str) {    //대문자로 변환
    string upper = "";

    for (int i = 0; i < (int)str.size(); i++)
        upper += toupper(str[i]);

    return upper;
}
