/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		1000007
#define pb		push_back
#define inf 	(1 << 30)

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, magic[mx];
vector<int>edge[mx];
int vis[mx];
int ds = -1, nd = 1;
int sub[mx], lev[mx];

void dfs(int at, int past, int level){
	vis[at] = 1;
	if(level > ds) ds = level, nd = at;
	for(auto u : edge[at]){
		if(u == past || magic[u] != 1) continue;
		dfs(u, at, level+1);
	}
}

int only_one(){
	int ret = 0;
	repn(i, n){
		if(vis[i] || magic[i] != 1) continue;
		ds = -1, nd = 0;
		dfs(i, -1, 1);
		dfs(nd, -1, 1);
		ret = max(ret, ds);
	}
	return ret;
}

void normal(int at, int past, int level){
	lev[at] = level;
	if(magic[at] == 1) sub[at] = level;
	else sub[at] = 0;
	for(auto u : edge[at]){
		if(u == past) continue;
		normal(u, at, sub[at] + (magic[u] == 1));
	}
	if(magic[at] != 1) return;
	for(auto u : edge[at]){
		if(u == past) continue;
		sub[at] = max(sub[at], sub[u]);
	}
}

int solve(int at, int past, int carry){
	int ret = 0;
	int mx1 = 0, mx2 = 0, id = 0;
	for(auto u : edge[at]){
		if(u == past) continue;
		if(sub[u] > mx1) mx2 = mx1,	mx1 = sub[u], id = u;
		else if(sub[u] > mx2) mx2 = sub[u];
	}
	if(magic[at] == 2){
		ret = max(ret, carry + mx1 + 1);	
		ret = max(ret, mx1 + mx2 + 1);
	}
	int nx1 = max(carry + 1, mx1 + 1);
	int nx2 = max(carry + 1, mx2 + 1);
	if(magic[at] != 1) nx1 = 0, nx2 = 0;
	for(auto u : edge[at]){
		if(u == past) continue;
		if(id == u) ret = max(ret, solve(u, at, nx2));
		else ret = max(ret, solve(u, at, nx1));
	}
	return ret;
}

int one_two(){
	normal(1, -1, magic[1] == 1);
	repn(i, n) if(sub[i]) sub[i] -= lev[i] - 1;
	int ret = solve(1, -1, 0);
	return ret;
}

int main(){
	int x, y;
	scanf("%d", &n);
	rep(i, n-1){
		scanf("%d %d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	int one = 0, two = 0;
	int ret = 1e9;
	repn(i, n) scanf("%d", &magic[i]);
	repn(i, n) one += magic[i] == 1, two += magic[i] == 2;
	repn(i, n) ret = min(ret, magic[i]);
	int a = only_one();
	int b = one_two();
//	cout << "# " << a << ' ' << b << endl;
	if(b > 2 * a) printf("2/%d\n", b);
	else if(a >= 2) printf("1/%d\n", a);
	else printf("%d/1\n", ret);
	return 0;
}

