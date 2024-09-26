#include <iostream>
#include <string>
#include <vector>
using namespace std;

string N;

int main() {
    cin >> N;

    if (N == "0") {
        cout << 0;
        return 0;
    }

    vector<char> plus;  // 벡터를 사용해 문자들을 저장
    bool flag = false;  // 앞의 '0'을 제거하기 위한 플래그

    for (int i = 0; i < N.length(); i++) {
        int num = N[i] - '0';

        for (int divNum = 4; divNum > 0; divNum /= 2) {
            if (num >= divNum) {
                num -= divNum;
                plus.push_back('1');
                flag = true;
            } else {
                if (flag) plus.push_back('0');
            }
        }
    }

    // 벡터에 저장된 결과를 출력
    for (char c : plus) {
        cout << c;
    }

    return 0;
}