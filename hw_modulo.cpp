// 컴퓨터시스템보안 과제 01

#include <iostream>
using namespace std;

//덧셈 역원
pair<int, int> AdditiveInverse(int N, int M) {
    int a = M % N;
    int b = N - a;

    //자기 자신에 대한 덧셈 역원은 자기 자신 (0, 0)
    if (a == 0)
        return make_pair(0, 0);

    return make_pair(a, b);
}

//최대공약수
int GCD(int a, int b) {
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


int main(void) {

    int N, M;
    cout << "Input n, m >> ";
    cin >> N >> M;

    //입력 검사
    if (N < 2 || M < 2) {
        cout << "n, m 입력 오류" << "\n";
        return -1;
    }

    //덧셈 역원
    pair<int, int> addResult = AdditiveInverse(N, M);
    cout << "Additive Inverse : ";
    cout << "(" << addResult.first << ", " << addResult.second << ")" << "\n";

    //곱셈 역원
    //최대공약수가 1 : 곱셈 역원의 필요충분조건
    if (GCD(N, M) == 1) {
        int result = MultiplicativeInverse(N, M, 0, 1);

        //0보다 작으면 N 더하기
        if (result < 0)
            result = result + N;

        cout << "Multiplicative Inverse : ";
        cout << result << "\n";
    }
    else
        cout << "역원이 존재하지 않습니다." << "\n"; 

    return 0;
}