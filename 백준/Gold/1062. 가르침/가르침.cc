#include <bits/stdc++.h>
using namespace std;

const int maxK = 26;

int rnt, N, M;
string s;
bool useAlphabet[maxK];
vector<string> vec;


void solution(int idx, int cnt) {

    // 다 셋을때
    if (cnt <= 0) {
        int possibleCnt = 0;
        for (string s : vec) {
            bool flag = true;
            for (char c : s) {
                int cIdx = c - 'a';
                if (!useAlphabet[cIdx]) {
                    flag = false;
                    break;
                }
            }
            if (flag) possibleCnt++;
        }

        rnt = max(rnt, possibleCnt);
        return;
    }
    // cnt를 다 쓰지 못하고 넘어갈 경우 제외
    if (idx >= maxK)return;

    // 이미 있는것들이라면 다음 꺼로 넘어감
    if (useAlphabet[idx]) {
        solution(idx + 1, cnt);
        return;
    }
    solution(idx + 1, cnt);
    useAlphabet[idx] = true;
    solution(idx + 1, cnt - 1);
    useAlphabet[idx] = false;
}







int main() {

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s;
        vec.push_back(s);
    }

    if (M < 5) {
        cout << 0;
        return 0;
    }

    vector<char> basicCharVec = { 'a','t','n','c','i' };
    for (char c : basicCharVec) {
        int cIdx = c - 'a';
        useAlphabet[cIdx] = true;
    }

    solution(0, M - 5);
    cout << rnt;

    return 0;
};