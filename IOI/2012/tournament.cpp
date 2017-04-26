/* Bismillahir Rahmanir Rahim */

#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 100005;
const int oo = 1e9;

struct segtree{
	int t[N*4], p[N*4];
	void build(int b, int e, int node){
		p[node] = 0;
		if(b == e){
			t[node] = 1;
			return;
		}
		int mid = (b + e) / 2, l = 2 * node, h = l + 1;
		build(b, mid, l);
		build(mid+1, e, h);
		t[node] = t[l] + t[h];
	}
	void update(int b, int e, int node, int x, int y){
		if(y < b || e < x || x > y) return;
		if(b >= x && e <= y){
			t[node] = 0, p[node] = 1;
			return;
		}
		int mid = (b + e) / 2, l = 2 * node, h = l + 1;
		if(p[node]) t[l] = t[h] = 0, p[l] = p[h] = 1, p[node] = 0;
		update(b, mid, l, x, y);
		update(mid+1, e, h, x, y);
		t[node] = t[l] + t[h];
	}
	int get_k(int b, int e, int node, int need){
		if(b == e) return b;
		int mid = (b + e) / 2, l = 2 * node, h = l + 1;
		if(p[node]) t[l] = t[h] = 0, p[l] = p[h] = 1, p[node] = 0;
		if(t[l] >= need) return get_k(b, mid, l, need);
		else return get_k(mid+1, e, h, need - t[l]);
	}
};

struct persistent{
	int t[N*40], idx;
	int lf[N*40], rf[N*20];
	void build(int b, int e, int node){
		t[node] = oo;
		if(b==e) return;
		lf[node] = ++idx, rf[node] = ++idx;
		int mid = (b + e) / 2;
		build(b, mid, lf[node]);
		build(mid+1, e, rf[node]);
	}
	int insert(int b, int e, int node, int pos, int val){
		int id = ++idx;
		t[id] = min(t[node], val), lf[id] = lf[node], rf[id] = rf[node];
		if(b == e) return id;
		int mid = (b + e) / 2;
		if(pos <= mid) lf[id] = insert(b, mid, lf[node], pos, val);
		else rf[id] = insert(mid+1, e, rf[node], pos, val);
		t[id] = min(t[ lf[id] ], t[ rf[id] ]);
		return id;
	}
	int get_min(int b, int e, int node, int x, int y){
		if(y < b || e < x) return oo;
		if(b >= x && e <= y) return t[node];
		int mid = (b + e) / 2;
		return min(get_min(b, mid, lf[node], x, y), get_min(mid+1, e, rf[node], x, y));
	}
};


struct perSiStent{
	int t[N*40], idx;
	int lf[N*40], rf[N*20];
	void build(int b, int e, int node){
		t[node] = 0;
		if(b==e) return;
		lf[node] = ++idx, rf[node] = ++idx;
		int mid = (b + e) / 2;
		build(b, mid, lf[node]);
		build(mid+1, e, rf[node]);
	}
	int insert(int b, int e, int node, int pos, int val){
		int id = ++idx;
		t[id] = t[node] + val, lf[id] = lf[node], rf[id] = rf[node];
		if(b == e) return id;
		int mid = (b + e) / 2;
		if(pos <= mid) lf[id] = insert(b, mid, lf[node], pos, val);
		else rf[id] = insert(mid+1, e, rf[node], pos, val);
		return id;
	}
	int get_sum(int b, int e, int node, int x, int y){
		if(y < b || e < x) return 0;
		if(b >= x && e <= y) return t[node];
		int mid = (b + e) / 2;
		return get_sum(b, mid, lf[node], x, y) + get_sum(mid+1, e, rf[node], x, y);
	}
};

int n, m, rnk[N], s[N], e[N], r;
int st[N], en[N], fs[N], lf[N], rf[N];
segtree T;
persistent TT;
perSiStent TTT[2];
int root[N], rOOt[N][2];

void get_intervals(){
	for(int i=1;i<=n;i++) fs[i] = i;
	T.build(1, n, 1);
	for(int i=0;i<m;i++){
		int a = s[i], b = e[i];
		st[i] = fs[ T.get_k(1, n, 1, a) ];
		en[i] = T.get_k(1, n, 1, b);
		fs[ en[i] ] = st[i];
		T.update(1, n, 1, st[i], en[i]-1);
	}	
	lf[0] = -1, rf[n] = -1;
	for(int i=1;i<n;i++) lf[i] = (rnk[i] > r) ? i : lf[i-1];
	for(int i=n-1;i>=0;i--) rf[i] = (rnk[i] > r) ? i : rf[i+1];
	TT.idx = 1;
	TT.build(1, n, 1);
	root[0] = 1;
	for(int i=0;i<m;i++){
		root[i+1] = TT.insert(1, n, root[i], en[i], st[i]);
	}
	for(int i=0;i<=1;i++){
		TTT[i].idx = 1;
		TTT[i].build(1, n, 1);
		rOOt[0][i] = 1;
	}
	for(int i=0;i<m;i++){
		rOOt[i+1][0] = TTT[0].insert(1, n, rOOt[i][0], st[i], +1);
		if(en[i] == n) rOOt[i+1][1] = rOOt[i][1];
		else rOOt[i+1][1] = TTT[1].insert(1, n, rOOt[i][1], en[i]+1, -1);
	}
}

bool OK(int pos, int tm){
	if(TT.get_min(1, n, root[tm], pos, n) <= lf[pos]) return true;
	if(rf[pos] == -1) return false;
	if(TT.get_min(1, n, root[tm], rf[pos]+1, n) <= pos) return true;
	return false;
}

int bs(int pos){
	int lo = 1, hi = m, ret = 1;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(OK(pos, mid)) ret = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	return ret-1;
}

int get(int pos){
	int u = bs(pos);
	return TTT[0].get_sum(1, n, rOOt[u][0], 1, pos) + TTT[1].get_sum(1, n, rOOt[u][1], 1, pos);
}

int GetBestPosition(int _N, int _C, int _R, int *K, int *S, int *E) {
	n = _N, m = _C, r = _R;
	for(int i=1;i<n;i++) rnk[i] = K[i-1] + 1;
	for(int i=0;i<m;i++) s[i] = S[i]+1, e[i] = E[i]+1;
	get_intervals();
	int pos = 1, mx = 0;
	for(int i=1;i<=n;i++){
		int g = get(i);
		if(g > mx) pos = i, mx = g;
	}
	return pos - 1;
}