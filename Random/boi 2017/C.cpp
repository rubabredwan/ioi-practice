/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100005;

int n, m, k, t; 
int in[N], out[N], ret[N];
int level[N], p[N][20], cnt[N], sub[N];
vector<pii>g[N], mns;

void dfs(int at, int past, int l){
	p[at][0] = past;
	level[at] = l;
	in[at] = ++t;
	for(int i=1;i<=18;i++) p[at][i] = p[ p[at][i-1] ][ i-1 ];
	for(auto u : g[at]){
		if(u.first != past) dfs(u.first, at, l+1);
	}
	out[at] = t;
}

int get(int x, int y){
	if(level[x] < level[y]) swap(x, y);
	for(int i=18;i>=0;i--) if(level[x] - (1 << i) >= level[y]) x = p[x][i];
	if(x == y) return x;
	for(int i=18;i>=0;i--) if(p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
	return p[x][0];	
}

void solve(int at, int past, int ix){
	sub[at] += cnt[at];
	for(auto u : g[at]){
		if(u.first == past) continue;
		solve(u.first, at, u.second);
		sub[at] += sub[u.first];
	}
	ret[ix] += sub[at];
}

void Add(int x, int y){
	if(x == y) return;
	int lc = get(x, y);
	if(x == lc) cnt[lc]--, cnt[y]++;
	else if(y == lc) cnt[lc]--, cnt[x]++;
	else{
		cnt[lc] -= 2;
		cnt[x]++;
		cnt[y]++;
	}
}

int main(){
	int x, y, d;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1;i<n;i++){
		scanf("%d %d", &x, &y);
		g[x].push_back({y, i});
		g[y].push_back({x, i});
	}
	dfs(1, 0, 1);
	for(int i=1;i<=m;i++){
		scanf("%d", &d);
		int lc = -1;
		for(int j=1;j<=d;j++){
			scanf("%d", &x);
			if(lc == -1) lc = x;
			else lc = get(lc, x);
			mns.push_back({in[x], x});
		}
		sort(mns.begin(), mns.end());
		Add(mns[0].second, lc);
		for(int j=1;j<mns.size();j++){
			Add(mns[j].second, get(mns[j-1].second, mns[j].second));
		}
		mns.clear();
	}	
	solve(1, 0, 0);
	vector<int>print;
	for(int i=1;i<=n;i++) if(ret[i] >= k) print.push_back(i);
	printf("%d\n", int(print.size()));
	for(int i=0;i<print.size();i++){
		if(i != 0) printf(" ");
		printf("%d", print[i]);
	}
	printf("\n");
	return 0;
}