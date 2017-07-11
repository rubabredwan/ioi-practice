/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 100005;

int n, k;
vector < vector <int> > cost;
long long ans = 0;

struct data{
	vector <pii> pos;
	bool operator < (const data &p) const{
		long long r1 = 0;
		long long r2 = 0;
		for(auto u : pos) r1 += cost[u.first][u.second];
		for(auto u : p.pos) r2 += cost[u.first][u.second];
		return r1 > r2;
	}

};

void solve(){
	map < vector <pii>, bool > vis;
	priority_queue <data> q;
	data v;
	n = cost.size();
	for(int i = 0; i < min(16, n); ++i){
		v.pos.push_back({i, 1});
		q.push(v);
	}
	while(k){

		auto cur = q.top(); q.pop();

		if(vis[cur.pos]) continue;

		vis[cur.pos] = 1;

		for(auto u : cur.pos) ans += cost[u.first][u.second];
		--k;

		for(int i = 0; i < cur.pos.size(); ++i){
			pii &u = cur.pos[i];
			if(u.second + 1 < cost[u.first].size()){
				++u.second;
				q.push(cur);
				--u.second;
			}
			if(i + 1 < cur.pos.size() && u.first + 1 < cur.pos[i+1].first){
				++u.first;
				q.push(cur);
				--u.first;
			}
			if(i + 1 == cur.pos.size() && u.first + 1 < n){
				++u.first;
				q.push(cur);
				--u.first;
			}
		}
	}
}

bool comp(const vector <int> a, const vector <int> b){
	return a[1] < b[1];
}

int main(){
	freopen("roboherd.in", "r", stdin);
	freopen("roboherd.out", "w", stdout);
	int m, x;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%d", &m);
		vector <int> tmp, bar;
		for(int j = 0; j < m; ++j){ 
			scanf("%d", &x);
			tmp.push_back(x);
		}
		sort(tmp.begin(), tmp.end());
		for(int j = 1; j < m; ++j) tmp[j] -= tmp[0];
		ans += tmp[0] * 1LL * k;
		if(tmp.size() > 1) cost.push_back(tmp);
	}
	sort(cost.begin(), cost.end(), comp);
	--k;
	solve();
	printf("%lld\n", ans);
	return 0;
}
