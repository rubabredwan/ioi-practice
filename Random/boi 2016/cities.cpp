/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

typedef pair<int, long long> pii;

const int N = 200005;
const long long oo = 1e18;

int n, m, k, im[N], uu[N], vv[N], par[N];
vector<pii>g[N], roads;
long long dis[N][3];

void bfs(int at, int id){
	rep(i, N) dis[i][id] = oo;
	dis[at][id] = 0;
	priority_queue<pii>q;
	q.push({0, at});
	while(!q.empty()){
		pii f = q.top(); q.pop();
		int u = f.second;
		for(auto v : g[u]){
			if(dis[v.first][id] > dis[u][id] + v.second){
				dis[v.first][id] = dis[u][id] + v.second;
				q.push({-dis[v.first][id], v.first});
			}
		}
	}
}

bool Check(int mask, int bit){ return mask & (1 << bit); }

int Find(int at){
	return par[at] == at ? at : par[at] = Find(par[at]);
}

void brute(){
	repn(i, k) im[i]--;
	long long ret = oo;
	int a, b;
	sort(roads.begin(), roads.end());
	for(int mask=1;mask<(1<<n);mask++){
		bool flag = true;
		repn(i, k) if(!Check(mask, im[i])) flag = false;
		if(!flag) continue;
		long long ans = 0, comp = __builtin_popcount(mask);
		rep(i, n) par[i] = i;
		for(auto u : roads){
			a = uu[u.second] - 1, b = vv[u.second] - 1;
			if(!Check(mask, a)) continue;
			if(!Check(mask, b)) continue;
			if(Find(a) == Find(b)) continue;
			par[Find(a)] = Find(b);
			ans += u.first; comp--;
		}
		if(comp == 1) ret = min(ret, ans);
	}
	printf("%lld\n", ret);
}

int main(){
	int x, y, c;
	scanf("%d %d %d", &n, &k, &m);
	repn(i, k) scanf("%d", &im[i]);
	repn(i, m){
		scanf("%d %d %d", &uu[i], &vv[i], &c);
		g[uu[i]].pb({vv[i], c});
		g[vv[i]].pb({uu[i], c});
		roads.pb({c, i});
	}
	if(n <= 20 && m <= 40){
		brute();
		return 0;
	}
	assert(k == 3);
	bfs(im[1], 0);
	bfs(im[2], 1);
	bfs(im[3], 2);
	long long ret = oo;
	repn(i, n) ret = min(ret, dis[i][0] + dis[i][1] + dis[i][2]);
	printf("%lld\n", ret);
	return 0;
}

