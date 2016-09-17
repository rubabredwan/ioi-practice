/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define read(x)		freopen(x, "r", stdin)
#define write(x) 	freopen(x, "w", stdout)

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		1000005
#define pb		push_back

#define inf		(1 << 29)	
#define	eps		1e-6
#define pi 		acos(-1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int>edge[mx];
ll sum, diam, flag;
ll dep[mx];
int par[mx], sub[mx], dub[mx];

void dfs(int at, int past, ll l){
	diam = max(diam, l);
	sum += l * 2;
	sub[at] = 1;
	dep[at] = l;
	rep(i, edge[at].size()){
		int u = edge[at][i];
		if(u == past) continue;
		dfs(u, at, l+1);
		sub[at] += sub[u];
		dep[at] = max(dep[at], dep[u]);
		if(sub[u] > (n-1) / 2) flag = false;
	}
}

void init(int at, int past){
	dub[at] = 1;
	par[at] = past;
	rep(i, edge[at].size()){
		int u = edge[at][i];
		if(u !=past){
			init(u, at);
			dub[at] += dub[u];
		}
	}
}

void solve1(){
	repn(i, n){
		flag = true;
		rep(j, edge[i].size()){
			int u = edge[i][j];
			if(u == par[i]) continue;
			if(dub[u] > (n-1) / 2){
				flag = false;
				break;
			}
		}
		if(dub[1] - dub[i] > (n - 1) / 2) flag = false;
		if(!flag){
			printf("-1\n");
			continue;
		}
		sum = 0;
		diam = 0;
		dfs(i, i, 0);
		if(flag) printf("%lld\n", sum - diam);
		else printf("-1\n");
	}
}

void solve2(){
	repn(i, n){
		flag = true;
		rep(j, edge[i].size()){
			int u = edge[i][j];
			if(u == par[i]) continue;
			if(dub[u] > n / 2){
				flag = false;
				break;
			}
		}
		if(dub[1] - dub[i] > n / 2) flag = false;
		if(!flag){
			printf("-1\n");
			continue;
		}
		sum = 0;
		diam = 0;
		dfs(i, i, 0);
		flag = true;
		ll fx = 0, fy = 0;
		rep(j, edge[i].size()){
			int u = edge[i][j];
			if(sub[u] > n / 2) flag = false;
			if(sub[u] == n/2) diam = dep[u];
		}
		if(flag) printf("%lld\n", sum - diam);
		else printf("-1\n");
	}
}

int main(){
	int x, y;
	scanf("%d", &n);
	rep(i, n-1){
		scanf("%d %d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	init(1, 1);
	if(n % 2) solve1();
	else solve2();
	return 0;
}

