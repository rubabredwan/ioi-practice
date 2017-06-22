/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

int n, k;
vector <int> g[N];
int p[N][20], dep[N];
int sum[N];

void dfs(int at, int par){
	for(int i = 1; i <= 18; ++i) p[at][i] = p[ p[at][i-1] ][ i-1 ];
	for(auto u : g[at]){
		if(u != par){
			dep[u] = dep[at] + 1;
			p[u][0] = at;
			dfs(u, at);
		}
	}
}

int get(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 18; i >= 0; --i) if(dep[a] - (1 << i) >= dep[b]) a = p[a][i];
	if(a == b) return a;
	for(int i = 18; i >= 0; --i) if(p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
	return p[a][0];
}

void solve(int at, int par){
	for(auto u : g[at]){
		if(u != par){
			solve(u, at);
			sum[at] += sum[u];
		}
	}
}

int main(){
	freopen("maxflow.in", "r", stdin);
	freopen("maxflow.out", "w", stdout);
	int x, y;
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i){
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	for(int i = 1; i <= k; ++i){
		scanf("%d %d", &x, &y);
		int lc = get(x, y);
		if(lc == x) sum[y] += 1, sum[p[lc][0]] -= 1;
		else if(lc == y) sum[x] += 1, sum[p[lc][0]] -= 1;
		else{
			sum[p[lc][0]] -= 1;
			sum[lc] -= 1;
			sum[x] += 1;
			sum[y] += 1;
		}
	}
	solve(1, 0);
	int ret = 0;
	for(int i = 1; i <= n; ++i) ret = max(ret, sum[i]);
	printf("%d\n", ret);
	return 0;
}

