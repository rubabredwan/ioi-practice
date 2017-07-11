/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

const int N = 100007;

int n, p[N], T = 0, st[N], en[N], P[N];
vector <int> t[N * 4], edge[N];

void dfs(int at, int past){
	st[at] = ++T;
	P[T] = p[at];
	for(auto u : edge[at]){
		if(u == past) continue;
		dfs(u, at);
	}
	en[at] = T;
}

void build(int b, int e, int node){
	if(b == e){
		t[node].push_back(P[b]);
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	build(b, mid, l);
	build(mid+1, e, h);
	merge(t[l].begin(), t[l].end(), t[h].begin(), t[h].end(), back_inserter(t[node]));
}

int query(int b, int e, int node, int x, int y, int val){
	if(y < b || e < x) return 0;
	if(b >= x && e <= y){
		int lo = 0, hi = t[node].size() - 1, ret = hi + 1;
		while(lo <= hi){
			int mid = (lo + hi) / 2;
			if(t[node][mid] > val){
				ret = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		return int(t[node].size()) - ret;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	return query(b, mid, l, x, y, val) + query(mid+1, e, h, x, y, val);
}

int main(){
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	int x;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	for(int i = 2; i <= n; ++i){
		scanf("%d", &x);
		edge[x].push_back(i);
		edge[i].push_back(x);
	}
	dfs(1, -1);
	build(1, n, 1);
	for(int i = 1; i <= n; ++i){
		printf("%d\n", query(1, n, 1, st[i], en[i], p[i]));
	}
	return 0;
}
