/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> pii;

const int N = 200005;
const long long oo = 1e18;

int n, h[N];
long long sum[N*4];
long long prop[N*4];
long long mn[N*4];

void build(int b, int e, int node){
	if(b == e){
		sum[node] = h[b];
		mn[node] = h[b];
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	build(b, mid, l);
	build(mid + 1, e, h);
	sum[node] = sum[l] + sum[h];
	mn[node] = min(mn[l], mn[h]);
}

void propagate(int b, int e, int node){
	int b1 = b, e1 = (b + e) / 2;
	int b2 = e1 + 1, e2 = e;
	int l = 2 * node, h = l + 1;
	sum[l] += (e1 - b1 + 1) * 1LL * prop[node];
	mn[l] += prop[node];
	prop[l] += prop[node];
	sum[h] += (e2 - b2 + 1) * 1LL * prop[node];
	mn[h] += prop[node];
	prop[h] += prop[node];
	prop[node] = 0;
}

void update(int b, int e, int node, int x, int y, int add){
	if(y < b || e < x) return;
	if(b >= x && e <= y){
		sum[node] += (e - b + 1) * 1LL * add;
		mn[node] += add;
		prop[node] += add;
		return;
	}
	if(prop[node]) propagate(b, e, node);
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	update(b, mid, l, x, y, add);
	update(mid + 1, e, h, x, y, add);
	sum[node] = sum[l] + sum[h];
	mn[node] = min(mn[l], mn[h]);
}

pii query(int b, int e, int node, int x, int y){
	if(y < b || e < x) return {0, oo};
	if(b >= x && e <= y) return {sum[node], mn[node]};
	if(prop[node]) propagate(b, e, node);
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	pii aa = query(b, mid, l, x, y);
	pii bb = query(mid + 1, e, h, x, y);
	return {aa.first + bb.first, min(aa.second, bb.second)};
}

int main(){
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	int q, x, y, z; char c;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) scanf("%d", &h[i]);
	build(1, n, 1);
	while(q--){
		scanf(" %c", &c);
		if(c == 'P'){
			scanf("%d %d %d", &x, &y, &z);
			update(1, n, 1, x, y, z);
		}
		else{
			scanf("%d %d", &x, &y);
			pii ret = query(1, n, 1, x, y);
			if(c == 'M') printf("%lld\n", ret.second);
			else printf("%lld\n", ret.first);
		}
	}
	return 0;
}

