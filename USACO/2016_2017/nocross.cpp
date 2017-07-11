/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 100005;

int n, a[N], b[N], p[N], q[N];
int t[N * 4];

void update(int b, int e, int node, int pos, int val){
	if(b == e){
		t[node] = max(t[node], val);
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	if(pos <= mid) update(b, mid, l, pos, val);
	else update(mid + 1, e, h, pos, val);
	t[node] = max(t[l], t[h]);
}

int query(int b, int e, int node, int x, int y){
	if(y < b || e < x || y < x) return 0;
	if(b >= x && e <= y) return t[node];
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	return max(query(b, mid, l, x, y), query(mid + 1, e, h, x, y));
}

int main(){
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &p[i]);
		a[p[i]] = i;
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &q[i]);
		b[q[i]] = i;
	}
	int ret = 0;
	for(int i = 1; i <= n; ++i){
		int id = p[i];
		vector <pii> upd;
		for(int j = max(1, id - 4); j <= min(n, id + 4); ++j){
			upd.push_back({ b[j], 1 + query(1, n, 1, 1, b[j] - 1) });
		}
		for(auto u : upd){
			update(1, n, 1, u.first, u.second);
			ret = max(ret, u.second);
		}
	}
	printf("%d\n", ret);
	return 0;
}