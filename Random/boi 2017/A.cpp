/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>pii;

const int N = 50005;

bitset<N>bit[N];
int n, m, done[N], cnt[N];
vector<int>g[N], cs;
set<pii>s;

int solve(){
	int k = cs.size() - 1;
	int ret = 0;
	for(int mask=0;mask<(1<<k);mask++){
		bool flag = true;

		for(int i=0;i<k && flag;i++){
			if(!(mask & (1 << i))) continue;

			for(int j=0;j<k;j++){
				if(!(mask & (1 << j))) continue;
				if(i == j) continue;
				if(!bit[cs[i]].test(cs[j])) flag = false;
			}

		}

		if(flag) ret = max(ret, __builtin_popcount(mask));
	}
	return ret + 1;
}

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		for(int j=0;j<x;j++){
			scanf("%d", &y);
			bit[i].set(y);
			g[i].push_back(y);
			cnt[i]++;
		}
		s.insert({cnt[i], i});
	}	
	int ret = 0;
	while(!s.empty()){
		auto it = s.begin(); s.erase(it);
		int u = (*it).second; cs.clear();
		for(auto v : g[u]){
			if(done[v]) continue;
			cs.push_back(v);
		}
		done[u] = 1;
		cs.push_back(u);
		ret = max(ret, solve());
		for(auto v : g[u]){
			if(done[v]) continue;
			s.erase({cnt[v], v});
			cnt[v]--;
			s.insert({cnt[v], v});
		}
	}
	printf("%d\n", ret);
	return 0;
}

