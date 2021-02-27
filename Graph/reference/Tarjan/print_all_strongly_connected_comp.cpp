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
//tushar roy     
vector<vector<int>>g;
vector<int>S,vis,cur;
vector<vector<int>>comp;
int idx[N], low[N];
int T,ID;
void DFS(int u) {
	idx[u] = low[u] = ++T;
	vis[u] = 1;
	S.push_back(u);
	for (auto t : g[u]) {
		if (!idx[t])DFS(t);
		if(vis[t])
			low[u] = min(low[u], low[t]);
	}
	if (idx[u] == low[u]) {
		while (true){
			int v = S.back();
			cur.push_back(v+1);
			vis[v] = 0; // why ??????
			S.pop_back();
			if (v == u)break;
		}
		ID++;
		comp.push_back(cur); cur.clear();
	}
}
int main() {
	file();
	int n, m;
	cin >> n >> m;
	g.resize(n);
	vis.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
	}
	for(int i=0;i<n;i++)
		if(!idx[i])DFS(i);
	for (auto t : comp) {
		for (auto tt : t)cout << tt << " ";
		cout << endl;
	}


}
