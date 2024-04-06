#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

ll N,M, num;
ll arr[10000004];
ll l, r, cnt;

int main() {

    vector<ll>vec;
    cin>>N>>M;

    for(ll i = 0;i<N;i++){
        cin>>arr[i];
    }

    sort(arr, arr + N);

    l = 0; r = N-1;
    while(l<r){
        if(arr[l]+arr[r]==M){
            l++; r--; cnt++;
        }
        else if(arr[l]+arr[r]>M){
            r--;
        }
        else{
            l++;
        }
    }

    if(l==r && arr[l] == 9) cnt++;
    cout<<cnt;

    return 0; 
}