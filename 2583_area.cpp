#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

// 4-connectivity
void printArr(int**arr, int m, int n) {

    cout << "\n\n=== print arr ===\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    int m, n, sqNum;
    cin >> m >> n >> sqNum;
    int **points = new int *[4];


    for (int i = 0; i < sqNum; i++)
    {
        points[i] = new int[sqNum];
    }

    for (int i = 0; i < sqNum; i++)
    {
        for(int j = 0; j < 4; j++) {
            cin >> points[i][j];
        }
    }

    //print points
    printArr(points, sqNum, 4);

    for(int i = 0; i < sqNum; i++) {

        points[i][1] = abs(points[i][1] - (m-1));
        points[i][2]--;
        points[i][3] = m - points[i][3];

        swap(points[i][0], points[i][1]);
        swap(points[i][2], points[i][3]);
        
    }

    printArr(points, sqNum, 4);

    //init img
    int **Img = new int*[n];
    for(int i = 0; i < m; i++) {
        Img[i] = new int[m];
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            Img[i][j] = 0;
        }
    }

    printArr(Img, m, n);

    for(int i = 0; i < sqNum; i++) {
        for(int j = points[i][2]; j <= points[i][0]; j++) {
            for(int k = points[i][1]; k <= points[i][3]; k++) {
                Img[j][k] = 1;
            }
        }
    }

    printArr(Img, m, n);
}