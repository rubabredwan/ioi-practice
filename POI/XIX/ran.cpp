/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 500005;

int n, k;
int isCyc[N];
int go[N];
int comp[N];
int cycPos[N];
int depth[N];
int siz[N];
int idx;
int par[N];
vector <int> g[N];
int vis[N];
int ass[N];
int cnt[N];
int pa[N][24];
int chain;

void dfs(int at){
	comp[at] = idx;
	vis[at] = 1;
	for(int i = 0; i < g[at].size(); ++i){
		int  u = g[at][i];
		if(!vis[u]) dfs(u);
	}
}

void chain_dfs(int at, int dp, int to){
	go[at] = to;
	depth[at] = dp;
	ass[at] = chain;
	for(int i = 1; i <= 20; ++i) pa[at][i] = pa[ pa[at][i-1] ][ i-1 ];
	for(int i = 0; i < g[at].size(); ++i){
		int u = g[at][i];
		if(cnt[u] <= 1 && ass[u] == 0){
			pa[u][0] = at;
			chain_dfs(u, dp + 1, to);
		}
	}
}

int lca(int a, int b){
	if(depth[a] < depth[b]) swap(a, b);
	for(int i = 20; i >= 0; --i) if(depth[a] - (1 << i) >= depth[b]) a = pa[a][i];
	if(a == b) return a;
	for(int i = 20; i >= 0; --i) if(pa[a][i] != pa[b][i]) a = pa[a][i], b = pa[b][i];
	return pa[a][0];
}

void init(){
	for(int i = 1; i <= n; ++i){
		if(vis[i]) continue;
		++idx;
		dfs(i);
		int cur = i, found = -1;
		while(1){
			++cnt[cur];
			cur = par[cur];
			if(cnt[cur] == 2){
				found = cur;
				break;
			}
		}
		cur = found;
		int dx = 0;
		vector <int> curCyc;
		while(1){
			cycPos[cur] = ++dx;
			++cnt[cur];
			++siz[idx];
			go[cur] = cur;
			curCyc.push_back(cur);
			cur = par[cur];
			if(cur == found) break;
		}
		for(int p = 0; p < curCyc.size(); ++p){
			int u = curCyc[p];
			for(int q = 0; q < g[u].size(); ++q){
				int v = g[u][q];
				if(cnt[v] <= 1){
					++chain;
					chain_dfs(v, 1, u);
				}
			}
		}
	}
}

int getdis(int a, int b){
	if(cycPos[a] <= cycPos[b]) return cycPos[b] - cycPos[a];
	else return siz[comp[a]] - cycPos[a] + cycPos[b];
}

pii mini(pii a, pii b){
	int m1 = max(a.first, a.second);
	int m2 = max(b.first, b.second);
	if(m1 < m2) return a;
	if(m2 < m1) return b;
	m1 = min(a.first, a.second);
	m2 = min(b.first, b.second);
	if(m1 < m2) return a;
	if(m2 < m1) return b;
	if(a.second <= b.second) return a;
	else return b;
}

pii get(int a, int b){
	if(comp[a] != comp[b]) return make_pair(-1, -1);
	if(ass[a] == ass[b] && ass[a]){
		int lc = lca(a, b);
		return make_pair(depth[a] - depth[lc], depth[b] - depth[lc]);
	}
	int r1 = depth[a], r2 = depth[b];
	int x = go[a], y = go[b];
	int g1 = getdis(x, y), g2 = getdis(y, x);
	pii ret = min(make_pair(r1 + g1, r2), make_pair(r1, g2 + r2));	
	return mini(make_pair(r1 + g1, r2), make_pair(r1, g2 + r2));
}

int main(){
	int q, x, y;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &par[i]);
		g[par[i]].push_back(i);
		g[i].push_back(par[i]);
	}
	init();
	while(q--){
		scanf("%d %d", &x, &y);
		pii ret = get(x, y);
		printf("%d %d\n", ret.first, ret.second);
	}
	return 0;
}

