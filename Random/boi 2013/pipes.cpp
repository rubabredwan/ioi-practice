/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back
#define f 	first
#define s 	second

using namespace std;

typedef pair<int, int> pii;

const int N = 500005;

int n, m, c[N], in[N];
vector<pii>g[N];
int bic, col[N], vis[N]; 
int ret[N], done[N];

void bicolor(int at){
	vis[at] = 1;
	for(auto u : g[at]){
		if(!vis[u.f]){
			col[u.f] = col[at] ^ 1;
			bicolor(u.f);
		}
		else if(col[at] == col[u.f]) bic = 1;
	}
}

void fix(){
	queue<int>q;
	repn(i, n) if(in[i] == 1) q.push(i);
	while(!q.empty()){
		int u = q.front(), cnt = 0; 
		in[u] = -1; q.pop();
		for(auto v : g[u]){
			if(done[v.f]) continue;
			cnt++;
		}
		if(cnt != 1) continue;
		for(auto v : g[u]){
			if(done[v.f]) continue;
			ret[v.s] = c[u]; 
			c[v.f] -= c[u];
			in[v.f] -= 1;
			if(in[v.f] == 1) q.push(v.f);
		}
		done[u] = 1, c[u] = 0;
	}
}

vector<int>edg, alt;
int from[N];

void dfs(int at, int sum){
	for(auto u : g[at]){
		if(done[u.f] || vis[u.f] || from[at] == u.f) continue;
		from[u.f] = at, vis[u.f] = 1;
		alt.pb(sum); edg.pb(u.s);
		dfs(u.f, c[u.f] - sum);
	}
}

void color(){
	set(vis, 0);
	int fs = 0;
	repn(i, n){
		if(!done[i]){
			dfs(i, 0); fs = i;
			break;
		}
	}
	if(edg.empty()) return;
	int f = edg.back();
	int a = (c[fs] - alt.back()) / 2;
	rep(i, edg.size()){
		alt[i] += a;
		ret[edg[i]] = alt[i];
		a *= -1;
	}
}

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	repn(i, n) scanf("%d", &c[i]);
	repn(i, m){
		scanf("%d %d", &x, &y);
		g[x].pb({y, i});
		g[y].pb({x, i});
		in[x]++;
		in[y]++;
	}
	bicolor(1);
	if(m > n){
		printf("0\n");
		return 0;
	}
	if(!bic && m >= n){
		printf("0\n");
		return 0;
	}
	fix();
	color();
	repn(i, m) printf("%d\n", 2*ret[i]);
	return 0;
}

