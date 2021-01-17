#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll solve (ll b , ll p , ll mod ){
	if ( p == 0)return 1;
	else if (p % 2 ==0 ){
		ll ans = solve (b, p / 2 , mod);
		return (ans % mod * ans % mod)% mod;

	}
	else return (b%mod * solve (b , p-1 , mod)% mod);
}


ll powermod(ll base, ll exp, ll mod) {
	ll result = 1;
	while (exp != 0) {
		if ((exp % 2) == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}
int  main(){

	int b ,p ,m ;
	cin >> b >>p >>m;
	cout<<solve (b, p ,m )<<endl;
}

