/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define read(x)		freopen(x, "r", stdin)
#define write(x) 	freopen(x, "w", stdout)

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mxx			10005
#define pb			push_back

#define inf			(1 << 29)	
#define	eps			1e-6
#define pi 			acos(-1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, w;
int dp[1 << 16];
vector<pii>v;

int recur(int mask){
	if(mask == 0) return 0;
	if(dp[mask] != -1) return dp[mask];
	int ret = inf, lst;
	rep(i, n) if(mask & (1 << i)) lst = i;
	int msk = mask ^ (1 << lst);
	int sm = v[lst].second;
	int fx = v[lst].first;
	if(sm <= w) ret = min(ret, fx + recur(msk));
	for(int i=msk;i>0;i=(i-1)&msk){
		int sum = sm;
		rep(j, n){
			if(i & (1 << j)) sum += v[j].second;
		}
		if(sum <= w) ret = min(ret, recur(i^msk) + fx);
	}
	return dp[mask] = ret;
}

int main(){
	int x, y;
	set(dp, -1);
	scanf("%d %d", &w, &n);
	rep(i, n){
		scanf("%d %d", &x, &y);
		v.push_back(pii(x, y));
	}
	sort(v.begin(), v.end());
	int ret = recur((1 << n) - 1);
	cout << ret << endl;
	return 0;
}
