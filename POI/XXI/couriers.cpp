/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		500007
#define pb		push_back
#define inf 	(1 << 30)

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct data{
	int val, cnt;
	data () {}
	data (int a, int b){
		val = a;
		cnt = b;
	}
};

data t[mx * 4];
int n, m, a[mx];
vector<int>con[mx];

data join(data a, data b){
	data ret;
	if(a.cnt > b.cnt) ret = a, ret.cnt -= b.cnt;
	else ret = b, ret.cnt -= a.cnt;
	if(a.val == b.val) ret.cnt = a.cnt + b.cnt;
	return ret;
}

void build(int b, int e, int node){
	if(b == e){
		t[node] = data(a[b], 1);
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	build(b, mid, l);
	build(mid+1, e, h);
	t[node] = join(t[l], t[h]);
}

data query(int b, int e, int node, int x, int y){
	if(x <= b && e <= y) return t[node];
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	if(y <= mid) return query(b, mid, l, x, y);
	else if(x > mid) return query(mid+1, e, h, x, y);
	else{
		return join(query(b, mid, l, x, y), query(mid+1, e, h, x, y));
	}
}

int get(int val, int x, int y){
	assert(val);
	int lo = 0, hi = con[val].size() - 1, uf = -2, up = -1;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(con[val][mid] <= y){
			up = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	lo = 0, hi = con[val].size() - 1;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(con[val][mid] >= x){
			uf = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	assert(up >= 0 && uf >= 0);
	return up - uf + 1;
}

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	repn(i, n) scanf("%d", &a[i]);
	repn(i, n) con[ a[i] ].pb( i );
	build(1, n, 1);
	while(m--){
		scanf("%d %d", &x, &y);
		data rt = query(1, n, 1, x, y);
		int ret = get(rt.val, x, y); 
		if(ret * 2 > (y - x + 1)) printf("%d\n", rt.val);
		else printf("0\n");
	}
	return 0;
}

