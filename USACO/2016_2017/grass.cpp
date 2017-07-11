/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

#define debug(x)	cerr << #x << ' ' << x << endl

using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> fii;

const int N = 200005;

int n, m, k, q;
int par[N], P[N], C[N], col[N];
vector <fii> edge;
vector <pii> g[N];
unordered_map <int, multiset <int>> mp[N];
multiset <int> active;

int Find(int at){
	return par[at] == at ? at : par[at] = Find(par[at]);
}

void dfs(int at, int par){
	P[at] = par;
	for(auto u : g[at]){
		if(u.first == par) continue;
		dfs(u.first, at);
		C[u.first] = u.second;
		mp[at][col[u.first]].insert(u.second);
	}
	for(auto u : mp[at]){
		if(u.first != col[at]){
			auto it = u.second.begin();
			active.insert(*it);
		}
	}
}

void init(){
	for(int i = 1; i <= n; ++i) par[i] = i;
	sort(edge.begin(), edge.end());
	for(auto u : edge){
		int x = u.second.first;
		int y = u.second.second;
		if(Find(x) != Find(y)){
			par[Find(x)] = Find(y);
			g[x].push_back({y, u.first});
			g[y].push_back({x, u.first});
		}
	}
	dfs(1, 0);
}

void REMOVE(int a, int b){
	if(mp[a].count(b) == 0) return;
	if(mp[a][b].empty()) return;
	auto it = mp[a][b].begin();
	active.erase(active.find(*it));
}

void ADD(int a, int b){
	if(mp[a].count(b) == 0) return;
	if(mp[a][b].empty()) return;
	auto it = mp[a][b].begin();
	active.insert(*(it));
}

void solve(int x, int y){
	int p = P[x];
	int c = col[x];
	if(p){
		if(c != col[p]) REMOVE(p, c);
		mp[p][c].erase(mp[p][c].find(C[x]));
		if(c != col[p]) ADD(p, c);
	}
	{
		ADD(x, c);
	}
	col[x] = y;
	c = col[x];
	if(p){
		if(c != col[p]) REMOVE(p, c);
		mp[p][c].insert(C[x]);
		if(c != col[p]) ADD(p, c);
	}
	{
		REMOVE(x, c);
	}
	auto it = active.begin();
	printf("%d\n", *it);
}

int main(){
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	int x, y, c;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d %d", &x, &y, &c);
		edge.push_back({c, {x, y}});
	}
	for(int i = 1; i <= n; ++i) scanf("%d", &col[i]);
	init();
	for(int i = 1; i <= q; ++i){
		scanf("%d %d", &x, &y);
		if(col[x] == y){
			auto it = active.begin();
			printf("%d\n", *it);
			continue;
		}
		solve(x, y);
	}
	return 0;
}