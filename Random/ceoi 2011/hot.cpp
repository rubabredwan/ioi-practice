/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

typedef pair<int, int> pii;

const int N = 500005;

int n, m, o;
pii t[N*4], a[N], b[N];

void build(int l, int r, int id){
	if(l == r){
		t[id] = make_pair(b[l].second, l);
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2*id);
	build(mid+1, r, 2*id+1);
	t[id] = max(t[2*id], t[2*id+1]);
}

void update(int l, int r, int id, int pos){
	if(l == r){
		t[id] = make_pair(0, l);
		return;
	}
	int mid = (l + r) / 2;
	if(pos <= mid) update(l, mid, 2*id, pos);
	else update(mid+1, r, 2*id+1, pos);
	t[id] = max(t[2*id], t[2*id+1]);
}

pii get(int l, int r, int id, int x, int y){
	if(y < l || r < x || x > y) return make_pair(-1, -1);
	if(x <= l && r <= y) return t[id];
	int mid = (l + r) / 2;
	return max(get(l, mid, 2*id, x, y), get(mid+1, r, 2*id+1, x, y));
}

int bs(int val){
	int lo = 1, hi = m, ret = 0;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(b[mid].first <= val) ret = mid, lo = mid + 1;
		else hi = mid - 1;
	}
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &m, &o);
	repn(i, n) scanf("%d %d", &a[i].first, &a[i].second);
	repn(i, m) scanf("%d %d", &b[i].second, &b[i].first);
	sort(a+1, a+1+n);
	sort(b+1, b+1+m);
	build(1, m, 1);
	long long ret = 0;
	vector<long long>v;
	repn(i, n){
		pii f = get(1, m, 1, 1, bs(a[i].second));

		if(f.first < a[i].first) continue;

		update(1, m, 1, f.second);

		v.push_back(f.first - a[i].first);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	o = min(o, int(v.size()));
	rep(i, o) ret += v[i];
	printf("%lld\n", ret);
	return 0;
}

