/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

const int N = 5005;
const long long oo = 1e18;

int n, vis[N]; 
long long val[N];
vector<int>g[N], gg[N];

long long solve(int at){
	set(vis, 0);
	rep(i, N) gg[i].clear();
	queue<int>q;
	stack<int>s;
	q.push(at); vis[at] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		s.push(u);
		for(auto v : g[u]){
			if(vis[v]) continue;
			vis[v] = 1;
			gg[u].push_back(v);
			q.push(v);
		}
	}
	long long ret = 0;
	while(!s.empty()){
		int i = s.top(); s.pop();
		val[i] = 1;
		for(auto u : gg[i]) val[i] += val[u];
		ret += val[i];
	}
	repn(i, n) if(vis[i] == 0) return oo;
	return ret;
}

int main(){
	int x, y, k;
	scanf("%d", &n);
	repn(i, n){
		scanf("%d", &k);
		while(k--){
			scanf("%d", &x);
			g[x].pb(i);
		}
	}
	long long ret = oo;
	repn(i, n) ret = min(ret, solve(i));
	printf("%lld\n", ret);
	return 0;
}

