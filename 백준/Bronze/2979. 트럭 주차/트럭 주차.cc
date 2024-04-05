#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

ll fee[4];
ll arr[104];
ll d,e;
ll rnt;

int main() {


    cin>>fee[1]>>fee[2]>>fee[3];
    for(int i = 0;i<3;i++){
        cin>>d>>e;
        for(ll j = d;j<e;j++){
            arr[j]++;
        }
    }

    for(ll i = 0;i<103;i++){
        rnt += fee[arr[i]] * arr[i];
    }

    cout<<rnt;
    

    return 0; 
}