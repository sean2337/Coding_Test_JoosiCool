#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, N, M, num;

int getIndex(int value, vector<int>vec) {
    auto pos = lower_bound(vec.begin(), vec.end(), value);
    return (int)(pos - vec.begin());
}


int main() {

    cin >> T;
    while (T--) {
        vector<int>vec1, vec2;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> num;
            vec1.push_back(num);
        }
        for (int i = 0; i < M; i++) {
            cin >> num;
            vec2.push_back(num);
        }
        //정렬 진행
        sort(vec2.begin(), vec2.end());
        int rnt = 0;
        for (int value : vec1) {
            rnt += getIndex(value, vec2);
        }
        cout << rnt <<'\n';
    }

    return 0;
}
