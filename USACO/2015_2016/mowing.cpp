/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 300005;
const int M = 40000005;

map <int, int> xm, ym;
int root[N][2], idx, xx, yy;
int t[M], lf[M], rf[M];

inline int update(int b, int e, int node, int pos, int val){
	if(!node) node = ++idx;
	if(b == e){
		t[node] += val;
		return node;
	}
	int mid = (b + e) / 2;
	if(pos <= mid) lf[node] = update(b, mid, lf[node], pos, val);
	else rf[node] = update(mid + 1, e, rf[node], pos, val);
	t[node] = t[lf[node]] + t[rf[node]];
	return node;
}

inline int query(int b, int e, int node, int x, int y){
	if(y < b || e < x || !node) return 0;
	if(b >= x && e <= y) return t[node];
	int mid = (b + e) / 2;
	return query(b, mid, lf[node], x, y) + query(mid + 1, e, rf[node], x, y);
}

void update_x(int x, int y, int val, int id){
	x = xm[x], y = ym[y];
	while(x <= xx){
		root[x][id] = update(1, yy, root[x][id], y, val);
		x += x & -x;
	}
}

int query_x(int x, int y, int id){
	int ret = 0;
	x = xm[x], y = ym[y];
	while(x){
		ret += query(1, yy, root[x][id], 1, y);
		x -= x & -x;
	}
	return ret;
}

int x[N], y[N];
int n, k;

void add(int id){
	if(x[id] == x[id-1]){
		int mn = min(y[id-1], y[id]) + 1;
		int mx = max(y[id-1], y[id]);
		update_x(x[id], mn, +1, 0);
		update_x(x[id], mx, -1, 0);
	}
	else{
		int mn = min(x[id-1], x[id]) + 1;
		int mx = max(x[id-1], x[id]);
		update_x(mn, y[id], +1, 1);
		update_x(mx, y[id], -1, 1);
	}
}

int solve(int id){
	int ret = 0;
	if(x[id] == x[id-1]){
		int mn = min(y[id-1], y[id]);
		int mx = max(y[id-1], y[id]) - 1;
		ret = query_x(x[id], mx, 1) - query_x(x[id], mn, 1);
	}
	else{
		int mn = min(x[id-1], x[id]);
		int mx = max(x[id-1], x[id]) - 1;
		ret = query_x(mx, y[id], 0) - query_x(mn, y[id], 0);
	}
	return ret;
}

int main(){
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d %d", &x[i], &y[i]);
	for(int i = 1; i <= n; ++i){
		for(int j = - 1; j <= +1; ++j){
			xm[x[i] + j];
			ym[y[i] + j];
		}
	}
	for(auto &u : xm) u.second = ++xx;
	for(auto &u : ym) u.second = ++yy;
	int ret = 0;
	for(int i = 1; i <= n; ++i){
		if(i - k - 1 > 1) add(i - k - 1);
		if(i > 1) ret += solve(i);
	}
	printf("%d\n", ret);
	return 0;
}