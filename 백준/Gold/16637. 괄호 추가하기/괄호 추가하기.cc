#include<iostream>
#include<vector>
#include<climits>
using namespace std;

string input;
int inputSize;
int result = INT_MIN;


int cal(int a, int b, char oper) {
    if (oper == '+')return a + b;
    if (oper == '-')return a - b;
    return a * b;
}


void solution(int idx, int cur) {
    if (idx >= inputSize) {
        result = max(result, cur);
        return;
    }
    char oper = (idx == 0) ? '+' : input[idx - 1];

    if (idx + 2 < inputSize) {
        int bracket = cal(input[idx] - '0', input[idx + 2] - '0', input[idx + 1]);
        solution(idx + 4, cal(cur, bracket, oper));
    }

    solution(idx + 2, cal(cur, input[idx] - '0', oper));
}

int main() {

    cin >> inputSize >> input;
    solution(0, 0);

    cout << result;

    return 0;
}
