#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = -1;
    string nums;
    bool is_palindrome;

    while(num != 0) {
        cin >> num;
        if (num == 0) 
            break;

        nums = to_string(num);
        is_palindrome = true;

        for (int i = 0; i < (int)nums.length() / 2; i++) {
            if (nums[i] != nums[nums.length() - 1 - i]) {
                is_palindrome = false;
                break;
            }
        }

        if (is_palindrome)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }

    return 0;
}