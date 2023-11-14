#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
map<char, pair<char,char>> tree;
char a, b, c;

void preorder(char c) {
	cout << c;
	if (tree[c].first) {
		preorder(tree[c].first);
	}
	if (tree[c].second) {
		preorder(tree[c].second);
	}
}

void inorder(char c) {
	if (tree[c].first) {
		inorder(tree[c].first);
	}
	cout << c;
	if (tree[c].second) {
		inorder(tree[c].second);
	}
}


void postorder(char c) {
	if (tree[c].first) {
		postorder(tree[c].first);
	}
	if (tree[c].second) {
		postorder(tree[c].second);
	}
	cout << c;
}


int main() {
	
	cin >> N;
	for (ll i = 0; i < N; i ++) {
		cin >> a >> b >> c;
		if (b != '.') tree[a].first = b;
		if (c != '.') tree[a].second = c;
	}
	

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}