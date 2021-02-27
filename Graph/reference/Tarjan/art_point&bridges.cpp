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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<vector<int>>g;
vector<int>idx, low,vis;
vector<pair<int, int>>bridges;
bool cut[1000];
int T,chiled;
void DFS(int u, int p) {
	idx[u] = low[u] = ++T;
	for (auto t : g[u]) {
		if (!idx[t]) {
			if (p == -1)chiled++;
			DFS(t, u);
			low[u] = min(low[u], low[t]);
			if (low[t] > idx[u])bridges.push_back({ t,u });
			if (low[t] >= idx[u])cut[u] = 1;
		}
		else if (t != p) {
			low[u] = min(low[u], idx[t]);
		}
	}
}
int main() {
	file();
	int n, m; cin >> n >> m;
	g.resize(n); vis.resize(n);
	idx.resize(n); low.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(0,-1);
	for (auto t : bridges)cout << t.first << " " << t.second << endl;
	cut[0] = (chiled > 1);
	for(int i=0;i<n;i++)if(cut[i])cout << i+1 << endl;
} 

