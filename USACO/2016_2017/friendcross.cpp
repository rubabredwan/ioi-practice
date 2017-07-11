/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int M = 20000000;

int n, k;
int p[N], q[N], a[N], b[N];
int t[M], lf[M], rf[M], root[N], idx;

int update(int b, int e, int node, int pos, int val){
	if(!node) node = ++idx;
	t[node] += val;
	if(b != e){
		int mid = (b + e) / 2;
		if(pos <= mid) lf[node] = update(b, mid, lf[node], pos, val);
		else rf[node] = update(mid + 1, e, rf[node], pos, val);
	}
	return node;
}

void Update(int x, int y, int val){
	while(x <= n){
		root[x] = update(1, n, root[x], y, val);
		x += x & -x;
	}
}

int query(int b, int e, int node, int x, int y){
	if(y < b || e < x || !node || x > y) return 0;
	if(b >= x && e <= y) return t[node];
	int mid = (b + e) / 2;
	return query(b, mid, lf[node], x, y) + query(mid + 1, e, rf[node], x, y);
}

int Query(int xd, int A, int B, int C, int D){
	int ret = 0;
	while(xd){
		ret += query(1, n, root[xd], A, B) + query(1, n, root[xd], C, D);
		xd -= xd & -xd;
	}
	return ret;
}

int main(){
	freopen("friendcross.in", "r", stdin);
	freopen("friendcross.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &p[i]);
		a[p[i]] = i;
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &q[i]);
		b[q[i]] = i;
	}
	for(int i = 1; i <= n; ++i) Update(b[i], i, +1);
	long long ret = 0;
	for(int i = 1; i <= n; ++i){
		int id = p[i];
		Update(b[id], id, -1);
		ret += Query(b[id], 1, id - k - 1, id + k + 1, n);
	}
	printf("%lld\n", ret);
	return 0;
}