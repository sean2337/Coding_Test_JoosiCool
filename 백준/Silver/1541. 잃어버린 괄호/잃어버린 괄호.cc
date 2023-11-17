#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pairll;
using namespace std;
ll N, M, K, a, b, c, d, rnt, cnt;
vector<ll>vec;
ll dis[100005];
ll arr[100005];

vector<ll> split(string input, vector<string> delimiters) {
    vector<ll> result;
    size_t pos = 0;

    while (true) {
        size_t minPos = string::npos;
        string selectedDelimiter = "";

        for (const string& delimiter : delimiters) {
            size_t foundPos = input.find(delimiter, pos);
            if (foundPos != string::npos && foundPos < minPos) {
                minPos = foundPos;
                selectedDelimiter = delimiter;
            }
        }

        if (minPos == string::npos) {
            result.push_back(stoi(input.substr(pos)));
            break;
        }

        result.push_back(stoi(input.substr(pos, minPos - pos)));
        pos = minPos + selectedDelimiter.length();
    }

    return result;
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;

	cin >> s;
    for (char c : s) {
        if (c == '+' || c == '-')vec.push_back(c);
    }

    vector<ll> nVec = split(s, { "+","-" });
    bool flag = true;
    rnt = nVec[0];
    for (ll i = 0; i < vec.size(); i++) {
        if (vec[i] == '-') flag = false;
        if (flag) rnt += nVec[i+1];
        else rnt -= nVec[i+1];
    }
    cout << rnt;

	return 0;
}