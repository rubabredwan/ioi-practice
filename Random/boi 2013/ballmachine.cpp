/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back
#define mp	make_pair

using namespace std;

typedef pair<int, int> pii;

const int N = 100005;

struct segtree{
	int t[N*4], p[N*4];
	inline void build(int l, int r, int id){
		if(l == r){
			t[id] = 1, p[id] = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, 2*id);
		build(mid+1, r, 2*id+1);
		t[id] = t[2*id] + t[2*id+1];
		p[id] = 0;
	}
	inline void propagate(int l, int r, int id){
		int mid = (l + r) / 2;
		t[2*id] = 0;	p[2*id] = 1;
		t[2*id+1] = 0;	p[2*id+1] = 1;
		p[id] = 0;
	}
	inline void update(int l, int r, int id, int x, int y){
		if(y < l || r < x) return;
		if(l >= x && r <= y){
			t[id] = 0, p[id] = 1;
			return;
		}
		if(p[id]) propagate(l, r, id);
		int mid = (l + r) / 2;
		update(l, mid, 2*id, x, y);
		update(mid+1, r, 2*id+1, x, y);
		t[id] = t[2*id] + t[2*id+1];
	}
	inline void update(int l, int r, int id, int pos){
		if(l == r){
			t[id] = 1, p[id] = 0;
			return;
		}
		if(p[id]) propagate(l, r, id);
		int mid = (l + r) / 2;
		if(pos <= mid) update(l, mid, 2*id, pos);
		else update(mid+1, r, 2*id+1, pos);
		t[id] = t[2*id] + t[2*id+1];
	}
	inline int query(int l, int r, int id, int need){
		if(l == r) return l;
		if(p[id]) propagate(l, r, id);
		int mid = (l + r) / 2;
		if(t[2*id] >= need) return query(l, mid, 2*id, need);
		else return query(mid+1, r, 2*id+1, need - t[2*id]);
	}
	inline int query(int l, int r, int id, int x, int y){
		if(y < l || r < x) return 0;
		if(l >= x && r <= y) return t[id];
		if(p[id]) propagate(l, r, id);
		int mid = (l + r) / 2;
		return query(l, mid, 2*id, x, y) + query(mid+1, r, 2*id+1, x, y);
	}
};

int n, q, root;
int mn[N], st[N], en[N], idx[N], t;
int pa[N][20], dep[N];
segtree tree;
vector<int>g[N];

void dfs(int at, int l){
	dep[at] = l;
	mn[at] = at;
	for(int i=1;i<=17;i++) pa[at][i] = pa[ pa[at][i-1] ][ i-1 ];
	for(auto u : g[at]){
		pa[u][0] = at;
		dfs(u, l+1);
		mn[at] = min(mn[at], mn[u]);
	}
}

void ass(int at){
	st[at] = t + 1;
	vector<pii>son;
	for(auto u : g[at]){
		son.push_back({mn[u], u});
	}
	sort(son.begin(), son.end());
	for(auto u : son) ass(u.second);
	en[at] = ++t;
	idx[t] = at;
}

int add(int k){
	int nd = tree.query(1, n, 1, k);
	tree.update(1, n, 1, 1, nd);
	return idx[nd];
}

bool full(int node){
	return tree.query(1, n, 1, st[node], en[node]) == 0;
}

int rem(int nd){
	int cur = nd;
	for(int i=17;i>=0;i--){
		if(pa[cur][i] == 0) continue;
		if(full(pa[cur][i])){
			cur = pa[cur][i];
		}
	}
	tree.update(1, n, 1, en[cur]);
	return dep[nd] - dep[cur];
}

int main(){
	// freopen("in.txt", "r", stdin);
	int x, y;
	scanf("%d %d", &n, &q);
	repn(i, n){
		scanf("%d", &x);
		if(x == 0) root = i;
		else g[x].pb(i);
	}
	dfs(root, 0);
	ass(root);
	tree.build(1, n, 1);
	while(q--){
		scanf("%d", &x);
		if(x == 1){
			scanf("%d", &y);
			printf("%d\n", add(y));
		}
		else{
			scanf("%d", &y);
			printf("%d\n", rem(y));
		}
	}
	return 0;
}
