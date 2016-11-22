/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		507
#define pb		push_back
#define inf 	(1 << 30)

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int s, c;
int a[mx], b[mx];
int p[mx], q[mx];
vector<int>edge[mx];
int vis[mx], match[mx], t;

void reset(){
	rep(i, mx) edge[i].clear();
	t = 0;
	set(match, -1);
	set(vis, 0);
}

bool dfs(int at){
	if(vis[at] == t) return false;
	vis[at] = t;
	for(auto u : edge[at]){
		if(match[u] == -1){
			match[u] = at;
			return true;
		}
		if(dfs(match[u])){
			match[u] = at;
			return true;
		}
	}
	return false;
}

int solve(){
	repn(i, m){
		repn(j, n){
			int dis = (abs(a[j] - p[i]) + abs(b[j] - q[i])) * 200;
			int tim = dis / s + ((dis % s) != 0);
			if(tim > c) continue;
			edge[i].pb(j);
		}
	}
	int ret = 0;
	repn(i, m){
		++t;
		if(dfs(i)) ret++;
	}
	return ret;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		reset();
		scanf("%d %d %d %d", &n, &m, &s, &c);
		repn(i, n) scanf("%d %d", &a[i], &b[i]);
		repn(i, m) scanf("%d %d", &p[i], &q[i]);
		int ret = solve();
		printf("%d\n", ret);
	}
	return 0;
}
