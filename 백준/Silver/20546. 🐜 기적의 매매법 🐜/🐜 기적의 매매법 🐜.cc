#include <iostream>
#include <cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>vec;
int cash, num;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> cash;
    for (int i = 0; i < 14; i++) {
        cin >> num;
        vec.push_back(num);
    }
    
    // 준현이 방식
    int p1_cash = cash;
    int p1_cnt = 0;
    int p1_profit = 0;
    for (int i = 0; i < 14; i++) {
        if (p1_cash / vec[i] > 0) {
            p1_cnt += p1_cash / vec[i];
            p1_cash -= ((p1_cash / vec[i]) * vec[i]);
        }
    }
    p1_profit = p1_cnt * vec[13] + p1_cash;

    // 성민이 방식
    int p2_cash = cash;
    bool isUp = true;
    int cnt = 1;
    int p2_cnt = 0;
    int p2_profit = 0;
    int before = vec[0];
    for (int i = 1; i < 14; i++) {
        int current = vec[i];
        // 상승 중일때
        if (current > before) {
            if (isUp) cnt++;
            else {
                isUp = true;
                cnt = 1;
            }
            // 3개올라갔다며 다 팔아.
            if (cnt >= 3 && p2_cnt > 0) {
                p2_cash += current * p2_cnt;
                p2_cnt = 0;
            }
        }
        else if(current < before) {
            if (!isUp) cnt++;
            else {
                isUp = false;
                cnt = 1;
            }
            // 3개올라갔다며 다 사.
            if (cnt >= 3 && p2_cash >= vec[i]) {
                p2_cnt += p2_cash / current;
                p2_cash -= ((p2_cash / current) * current);
            }
        }
        else {
            cnt = 0;
        }
        before = current;
    }
    p2_profit = p2_cnt * vec[13] + p2_cash;

    if (p1_profit > p2_profit) {
        cout << "BNP";
    }
    else if (p1_profit < p2_profit) {
        cout << "TIMING";
    }
    else {
        cout << "SAMESAME";
    }

    return 0;
}