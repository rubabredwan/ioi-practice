/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define f	first
#define s	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 250007;

int n;
long long A[N], B[N];
long long tsum[N*4], tmin[N*4];
vector<pii>order;
vector<int>ans;

void build(int b, int e, int node){
	if(b == e){
		tsum[node] = A[b];
		tmin[node] = A[b];
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	build(b, mid, l);
	build(mid+1, e, h);
	tsum[node] = tsum[l] + tsum[h];
	tmin[node] = min(tmin[l], tsum[l] + tmin[h]);
}

void update(int b, int e, int node, int pos, int val){
	if(b == e){
		tsum[node] += val;
		tmin[node] += val;
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	if(pos <= mid) update(b, mid, l, pos, val);
	else update(mid+1, e, h, pos, val);
	tsum[node] = tsum[l] + tsum[h];
	tmin[node] = min(tmin[l], tsum[l] + tmin[h]);
}

int solve(){
	build(1, n, 1);
	repn(i, n) order.push_back(pii(B[i], i));
	sort(order.begin(), order.end());
	int ret = 0;
	rep(i, order.size()){
		int nd = order[i].f, dd = order[i].s;
		update(1, n, 1, dd, -nd);
		if(tmin[1] < 0) update(1, n, 1, dd, nd);
		else ret++, ans.push_back(dd);
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	repn(i, n) scanf("%lld", &A[i]);
	repn(i, n) scanf("%lld", &B[i]);
	int ret = solve();
	printf("%d\n", ret);
	sort(ans.begin(), ans.end());
	rep(i, ans.size()){
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
