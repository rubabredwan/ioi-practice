/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

typedef pair<int, int>pii;

const int N = 3005;

int n, m, X[N], Y[N], A, B;
vector<int>g[N];
int vis[N];

int dfs(int at){
	if(vis[at]) return 0;
	vis[at] = 1;
	int ret = 0;
	if(X[at] == A) ++ret;
	rep(i, g[at].size()){
		int v = g[at][i];
		ret += dfs(v);
	}
	return ret;
}

int main(){
	int x, y, k;
	scanf("%d %d %d %d", &n, &m, &A, &B);
	repn(i, n) scanf("%d %d", &X[i], &Y[i]);
	repn(i, m){
		scanf("%d %d %d", &x, &y, &k);
		g[x].pb(y);
		if(k == 2) g[y].pb(x);
	}
	vector<pii>ans;
	repn(i, n){
		if(X[i] != 0) continue;
		set(vis, 0);
		ans.pb(make_pair(Y[i], dfs(i)));
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	rep(i, ans.size()) printf("%d\n", ans[i].second);
	return 0;
}

