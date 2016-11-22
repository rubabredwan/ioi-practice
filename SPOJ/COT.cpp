/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx	100007
#define pb	push_back
#define oo	1e9 

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, p[mx][20], l[mx], w[mx], idx = 0;
int t[mx*50], ln[mx*50], rn[mx*50], root[mx];
int free_idx = 1;
vector<int>edge[mx];
map<int, int>mp, id;

void build(int b, int e, int node){
	if(b == e) return;
	int mid = (b + e) / 2;
	ln[node] = ++free_idx;
	rn[node] = ++free_idx;
	build(b,   mid, ln[node]);
	build(mid+1, e, rn[node]);
}

int insert(int node, int b, int e, int val){
	int nn = ++free_idx;
	t[nn] = t[node] + 1;
	if(b == e) return nn;
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	ln[nn] = ln[node], rn[nn] = rn[node];
	if(val <= mid) ln[nn] = insert(ln[node], b, mid, val);
	else rn[nn] = insert(rn[node], mid+1, e, val);
	return nn;
}

int query(int n1, int n2, int n3, int n4, int b, int e, int need){
	if(b == e) return id[b];
	int tot = t[ ln[n1] ] + t[ ln[n2] ] - t[ ln[n3] ] - t[ ln[n4] ];
	int mid = (b + e) / 2;
	if(tot >= need) return query(ln[n1], ln[n2], ln[n3], ln[n4], b, mid, need);
	else return query(rn[n1], rn[n2], rn[n3], rn[n4], mid+1, e, need - tot);
}

void init(){
	repn(i, n) mp[w[i]] = 1;
	map<int, int>::iterator u;
	for(u=mp.begin();u!=mp.end();u++) mp[u->first] = ++idx, id[idx] = u->first;
	build(1, idx, 1);
	root[0] = 1;
}

void dfs(int at, int par, int level){
	root[at] = insert(root[par], 1, idx, mp[ w[at] ]);
	l[at] = level, p[at][0] = par;
	for(int i=1;i<=18;i++) p[at][i] = p[ p[at][i-1] ][i-1];
	rep(i, edge[at].size()){
		int u = edge[at][i];
		if(u != par) dfs(u, at, level+1);
	}
}

int lca(int x, int y){
	if(l[x] < l[y]) swap(x, y);
	for(int i=18;i>=0;i--) if(l[x] - (1 << i) >= l[y]) x = p[x][i];
	if(x == y) return x;
	for(int i=18;i>=0;i--) if(p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
	return p[x][0];
}

int main(){
	int t, x, y;
	scanf("%d %d", &n, &m);
	repn(i, n) scanf("%d", &w[i]);
	repn(i, n-1){
		scanf("%d %d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	init();
	dfs(1, 0, 0);
	while(m--){
		scanf("%d %d %d", &x, &y, &t);
		int lc = lca(x, y);
		int pr = p[lc][0];
		printf("%d\n", query(root[x], root[y], root[lc], root[pr], 1, idx, t));
	}
	return 0;
}
