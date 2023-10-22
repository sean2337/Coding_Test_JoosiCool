#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10003;
vector<int> arr[MAXN];

bool visit[MAXN];

int graphMove(int index) {
    visit[index] = true;
    int indexCount = 1;
    for (int i = 0; i < arr[index].size(); i++) {
        if (visit[arr[index][i]]) continue;
        indexCount += graphMove(arr[index][i]);
    }
    return indexCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vecSize, count;
    cin >> vecSize >> count;

    int a, b;

    while (count--) {
        cin >> a >> b;
        arr[b].push_back(a);
    }

    vector<int> answer;
    int maxCount = 0;

    for (int i = 1; i <= vecSize; i++) {
        memset(visit, false, sizeof(visit));
        int indexCount = graphMove(i);
        if (indexCount > maxCount) {
            maxCount = indexCount;
            answer.clear();
            answer.push_back(i);
        }
        else if (indexCount == maxCount) {
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());

    for (int value : answer) {
        cout << value << " ";
    }

    return 0;
}