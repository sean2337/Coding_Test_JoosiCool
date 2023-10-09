#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int arr[40003];
int ls[40003];
int BinarySearch(int left, int right, int target) {


    int mid;

    while (left < right) {
        mid = (left + right) / 2;
       
        if (ls[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}




int main() {

    int count;
    cin >> count;


    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }

    int j = 0;
    ls[0] = arr[0];
    int i = 1;

    while (i < count) {
        if (ls[j] < arr[i]) {
            ls[j+1] = arr[i];
            j++;
        }
        else {
            int idx = BinarySearch(0, j, arr[i]);
            ls[idx] = arr[i];
        }
        i++;
    }

    cout << j+1;

    
    return 0;
}
