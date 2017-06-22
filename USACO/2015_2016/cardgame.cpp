/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

struct segtree{
	int t[N*4], cnt[N*4][2];
	void init(){
		memset(t, 0, sizeof(t));
		memset(cnt, 0, sizeof(cnt));
	}
	void update(int b, int e, int node, int pos, int id, int add){
		if(b == e){
			cnt[node][id] += add;
			return;
		}
		int mid = (b + e) / 2, l = 2 * node, h = l + 1;
		if(pos <= mid) update(b, mid, l, pos, id, add);
		else update(mid + 1, e, h, pos, id, add);
		t[node] = t[l] + t[h] + min(cnt[l][0], cnt[h][1]);
		cnt[node][0] = cnt[l][0] + cnt[h][0] - min(cnt[l][0], cnt[h][1]);
		cnt[node][1] = cnt[l][1] + cnt[h][1] - min(cnt[l][0], cnt[h][1]);
	}
	int get(){
		return t[1];
	}
};

int n, used[N];
vector <int> a, b;
segtree t1, t2;

int solve(){
	t1.init();
	t2.init();
	for(int i = 0; i < n; ++i){
		t2.update(1, 2 * n, 1, a[i], 1, +1);
		t2.update(1, 2 * n, 1, b[i], 0, +1);
	}
	int ret = t2.get();
	for(int i = 0; i < n; ++i){
		t2.update(1, 2 * n, 1, a[i], 1, -1);
		t2.update(1, 2 * n, 1, b[i], 0, -1);
		t1.update(1, 2 * n, 1, b[i], 1, +1);
		t1.update(1, 2 * n, 1, a[i], 0, +1);
		ret = max(ret, t1.get() + t2.get());
	}
	return ret;
}

int main(){
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	int x;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x);
		used[x] = 1;
		a.push_back(x);
	}
	for(int i = 1; i <= 2 * n; ++i){
		if(!used[i]) b.push_back(i);
	}
	reverse(b.begin(), b.end());
	int ret = solve();
	printf("%d\n", ret);
	return 0;
}

