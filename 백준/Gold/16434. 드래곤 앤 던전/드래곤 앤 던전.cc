#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, firstATK;
ll a, b, c;
struct A {
    ll kind, atk, blood;
};
vector<A>stageVec;

bool check(ll mid) {
    ll atk = firstATK, maxHP = mid, curHP = mid;
    for (A stage : stageVec) {
        ll stageHP = stage.blood, stageAtk = stage.atk;
        //몬스터와 싸울경우
        if (stage.kind == 1) {
            ll atackHuman = stageHP / atk;
            if (stageHP % atk) atackHuman++;
            ll atackDrangon = curHP / stageAtk;
            if (curHP % stageAtk) atackDrangon++;

            if (atackHuman > atackDrangon) return false;
            curHP -= ((atackHuman - 1) * stageAtk);
        }
        //포션일 경우
        else {
            curHP = min(curHP + stageHP, maxHP);
            atk += stageAtk;
        }
    }
    return true;
}



int main() {

    cin >> N >> firstATK;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        stageVec.push_back({ a,b,c });
    }

    ll l = 1, r = numeric_limits<ll>::max() - 3, mid;
    ll rnt = numeric_limits<ll>::max() -3;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            rnt = min(rnt, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << rnt;

    return 0;
}
