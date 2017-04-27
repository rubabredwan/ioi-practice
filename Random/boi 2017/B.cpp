/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, long long> pii;

const int N = 500005;
const long long oo = 1e18;

struct data{
	int id, dest;
	long long cost;
	data () {}
	data (int a, int b, long long c){
		id = a, dest = b, cost = c;
	}
};

long long dis[N], ret[N];
int k, n, o, m, st[N], en[N];
vector<pii>g[N];
vector<data>block[N];

long long brute(int s, int e){
	for(int i=s;i<=e;i++) dis[i] = oo;
	dis[s] = 0;
	for(int i=s;i<=e;i++){
		for(auto u : g[i]){
			dis[u.first] = min(dis[u.first], dis[i] + u.second);
		}
	}
	return dis[e];
}

void process(int s, int e, int id){
	int nb = 1 + s / 600;
	int eb = min(n - 1, nb * 600 + k - 1);
	int sb = nb * 600;

	brute(s, eb);

	for(int i=sb;i<=eb;i++){
		if(dis[i] == oo) continue;
		block[i].push_back(data(id, e, dis[i]));
	}

}

void solve(){
	for(int i=0;i<n;i++){
		if(int(block[i].size()) == 0) continue;

		brute(i, n-1);

		for(auto u : block[i]){
			ret[u.id] = min(ret[u.id], u.cost + dis[u.dest]);
		}

	}	
	for(int i=1;i<=o;i++) if(ret[i] == oo) ret[i] = -1;
	for(int i=1;i<=o;i++) printf("%lld\n", ret[i]);
}

int main(){
	int x, y, t;
	scanf("%d %d %d %d", &k, &n, &m, &o);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d", &x, &y, &t);
		g[x].push_back({y, t});
	}
	for(int i=1;i<=o;i++){
		ret[i] = oo;
		scanf("%d %d", &st[i], &en[i]);
		if(en[i] - st[i] <= 5000) ret[i] = brute(st[i], en[i]);
		else process(st[i], en[i], i);
	}
	solve();
	return 0;
}

