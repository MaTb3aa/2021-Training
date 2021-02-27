//============================================================================
// Name        : ICPC.cpp
// Author      : MaTb3aa
// Quotes      : Nothing is impossible, the word itself says 'I'm possible'!.
// Copyright   : Audrey Hepburn
// Description : You Can Do It
//============================================================================
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define endl                         '\n'	
#define Ceil(x,y)             ((x+y-1)/y)
#define sz(s)               (int)s.size()
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define all(v) ((v).begin()), ((v).end())
#define vi                    vector<int>
#define pii                 pair<int,int>
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define forr(i, n) for (int i = 0; i < int(n); i++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 1e7 + 5, mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x%y); }
ll lcm(ll x, ll y) { return ((x / gcd(x, y))*y); }
void file() {
#ifndef ONLINE_JUDGE
	//replace places & interrupt 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int start[1000], finish[10000];
vector<vector<int>>g;
int n, timer;
bool cycle,forword;
// directed or undirected 
void DFS(int u) {
	
	start[u] = timer++;
	for (auto t : g[u]) {
		if (start[t] == -1)
			DFS(t);
		else {
			if (finish[t] == -1) { cycle = 1; }
			else if (start[u] < start[t]) { forword = 1; }
			//else cross
		}
	}
	finish[u] = timer++;
}
int main() {
	file();
	cin >> n;
	g.resize(n);
	mem(start, -1);
	mem(finish, -1);
	int m; cin >>  m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y; --x; --y;
		g[x].push_back(y);
		//g[y].push_back(x);
	}
	DFS(0);
	cout << cycle << endl;
	
}
/*


8 10
1 2
2 3
3 4
4 2
1 5
5 6
6 3
6 7
6 8
1 8
*/