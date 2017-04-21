/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 300005;

int n, a, b, sub[N], dp[N];
vector<int>edge[N], son[N];
int lc, mx, par[N];
vector<int>path;

void dfs(int at, int pa, int level){
	par[at] = pa;
	for(auto u : edge[at]){
		if(u == pa) continue;
		dfs(u, at, level+1);
		sub[at] += sub[u];
	}
	if(sub[at] == 2){
		if(level > mx){
			mx = level;
			lc = at;
		}
	}
}

void crawl(int at){
	path.pb(at);
	if(at == lc) return;
	crawl(par[at]);
}

void gen_path(){
	sub[a] = 1, sub[b] = 1;
	dfs(1, -1, 1);
	crawl(a);
	vector<int>temp = path;
	path.clear();
	crawl(b);
	path.pop_back();
	reverse(path.begin(), path.end());
	for(auto u : path) temp.push_back(u);
	path = temp;
}

int recur(int at, int p1, int p2){
	for(auto u : edge[at]){
		if(u == p1 || u == p2) continue;
		son[at].push_back(recur(u, at, at));
	}
	sort(son[at].begin(), son[at].end());
	int ret = 0, add = son[at].size();
	for(auto u : son[at]){
		ret = max(ret, u + add);
		add--;
	}
	return ret;
}

int get_1(int len){
	int ret = dp[len];
	for(int i=len-1;i>=0;i--){
		vector<int>f;
		for(auto u : son[path[i]]){
			f.push_back(u);
		}
		f.push_back(ret);
		sort(f.begin(), f.end());
		int add = f.size();
		ret = 0;
		for(auto u : f){
			ret = max(ret, u + add);
			add--;
		}
	}
	return ret;
}

int get_2(int len){
	int ret = dp[len];
	for(int i=len+1;i<path.size();i++){
		vector<int>f;
		for(auto u : son[path[i]]){
			f.push_back(u);
		}
		f.push_back(ret);
		sort(f.begin(), f.end());
		int add = f.size();
		ret = 0;
		for(auto u : f){
			ret = max(ret, u + add);
			add--;
		}
	}
	return ret;
}


int solve(){
	int siz = path.size();
	rep(i, siz){
		int p1 = 0, p2 = 0;
		if(i) p1 = path[i-1];
		if(i + 1 < siz) p2 = path[i+1];
		dp[i] = recur(path[i], p1, p2);
	}
	if(path.size() == 2){
		return max(dp[0], dp[1]);
	}
	int lo = 0, hi = siz - 2, ret = int(1e9);
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		int r1 = get_1(mid);
		int r2 = get_2(mid+1);
		ret = min(ret, max(r1, r2));
		if(r1 <= r2) lo = mid + 1;
		else hi = mid - 1;
	}
	return ret;
}

int main(){
	int x, y;
	scanf("%d %d %d", &n, &a, &b);
	rep(i, n-1){
		scanf("%d %d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	gen_path();
	printf("%d\n", solve());
	return 0;
}
