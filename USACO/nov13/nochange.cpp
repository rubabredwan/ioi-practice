/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define N	100007
#define K 	2000007
#define pb	push_back
#define oo	1e9 

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k, coin[20], val[N], sum[N];
int vp[N][20];
int fp[(1 << 20)];

unordered_map<ll, int>mp;
int idx = 1;
int dp[K], vis[K];

int empty(int mask){
	if(fp[mask] != -1) return fp[mask];
	int ret = 0;
	rep(i, k) if(mask & (1 << i)) ret += coin[i];
	return fp[mask] = ret;
}

int nxt(int s, int i){
	if(vp[s][i] != -1) return vp[s][i];
	int lo = s, hi = n, ret = n + 1;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		int sm = sum[mid] - sum[s-1];
		if(sm > coin[i]){
			ret = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	return vp[s][i] = ret;
}

int recur(int s, int mask){
	if(s == n + 1) return empty(mask);
	if(mask == 0) return -1;
	ll fd = ll(s) * (1LL << 16LL) + 1LL * ll(mask);
	int id = mp[fd];
	if(id == 0) id = ++idx, mp[fd] = id;
	if(vis[id]) return dp[id];
	int ret = -1;
	rep(i, k){
		if(mask & (1 << i)){
			int nx = nxt(s, i);
			if(nx == s) continue;
			ret = max(ret, recur(nx, mask ^ (1 << i)));
		}
	}
	vis[id] = 1;
	return dp[id] = ret;
}

int main(){
	freopen("nochange.in", "r", stdin);
	freopen("nochange.out", "w", stdout);
	scanf("%d %d", &k, &n);
	rep(i, k) scanf("%d", &coin[i]);
	repn(i, n){
		scanf("%d", &val[i]);
		sum[i] += sum[i-1] + val[i];
	}
	set(vp, -1);
	set(fp, -1);
	printf("%d\n", recur(1, (1 << k)-1));
	return 0;
}

