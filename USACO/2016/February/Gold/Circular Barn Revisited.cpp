/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i,n)	for(ll i=0;i<n;i++)
#define repn(i,n)	for(ll i=1;i<=n;i++)
#define set(i,n)	memset(i,n,sizeof(i))

#define mx			103
#define inf			(1LL << 60LL)
#define eps			1e-9
#define	pi			acos(-1)
#define pb			push_back

using namespace std;

typedef long long 		ll;
typedef pair<ll, ll>	pii;


ll n, c[mx], dp[mx][mx][mx][10];

ll recur(ll fst, ll at, ll lst, ll lft){
	if(dp[fst][at][lst][lft] != -1) return dp[fst][at][lst][lft];
	if(lft == 0){
		ll ret = 0;
		for(ll i=at;i<=n;i++) ret += abs(i - lst) * c[i];
		for(ll i=1;i<fst;i++) ret += (abs(n - lst) + i) * c[i];
		return dp[fst][at][lst][lft] = ret;
	}	
	if(at == n + 1) return inf;
	ll ret = inf, sum = 0, fft = 0;
	for(ll i=at;i<=n;i++){
		fft += abs(i - at) * c[i];
		ret = min(ret, fft + recur(fst, i+1, at, lft-1));
	}
	return dp[fst][at][lst][lft] = ret;
}

int main(){
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);
	set(dp, -1);
	ll k;
	cin >> n >> k;
	repn(i, n) cin >> c[i];
	ll ret = inf, sum = 0, fft = 0;
	repn(i, n){
		ret = min(ret, recur(i, i, i, k));
	}
	cout << ret << endl;
	return 0;
}
