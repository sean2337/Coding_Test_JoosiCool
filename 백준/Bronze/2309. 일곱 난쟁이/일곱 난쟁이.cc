#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll arr[10];
ll sum = 0;

void printNajang(int i , int j){
    for(int k = 0;k<9;k++){
        if(k != i && k != j){
            cout<<arr[k]<<"\n";
        }
    }
    return;
}

int main() {
    for(int i = 0; i<9;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+9);

    for(int i = 0;i<9;i++){
        for(int j = i+1;j<9;j++){
            ll check =  sum - arr[i] - arr[j];
            if(check == 100){
                printNajang(i,j);
                return 0;
            }
        }
    }
    

    return 0; 
}