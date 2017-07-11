/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long oo = 1e18;

int n, k;
long long r[N], sum[N], inc[N];
long long dp[8][N];

long long get(int l, int r){
	if(l > r) return 0;
	long long ret = inc[r] - inc[l-1];
	ret -= (sum[r] - sum[l-1]) * (l - 1);
	return ret;
}

long long get_rot(int l, int r){
	return get(l, r + n);
}

void divide(int v, int l, int r, int L, int R){
	if(l > r) return;
	int mid = (l + r) / 2;
	int opt = -1;
	dp[v][mid] = oo;
	for(int i = L; i <= min(mid, R); ++i){
		long long cur = dp[v-1][i] + get(i + 1, mid - 1);
		if(cur < dp[v][mid]){
			dp[v][mid] = cur;
			opt = i;
		}
	}
	divide(v, l, mid - 1, L, opt);
	divide(v, mid + 1, r, opt, R);
}

void init(){
	for(int i = 1; i <= n; ++i) r[n + i] = r[i];
	for(long long i = 1; i <= n + n; ++i){
		sum[i] = sum[i-1] + r[i];
		inc[i] = inc[i-1] + r[i] * i;
	}
}

int main(){
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &r[i]);
	}
	init();
	long long ret = oo;
	for(int i = 1; i <= n; ++i){
		dp[1][i] = 0;
		for(int j = i + 1; j <= n; ++j) dp[1][j] = oo;
		for(int j = 2; j <= k; ++j){
			divide(j, i, n, i, n);
		}
		for(int j = i; j <= n; ++j){
			long long fk = dp[k][j] + get_rot(j + 1, i - 1);
			ret = min(ret, fk);
		}
	}
	printf("%lld\n", ret);
	return 0;
}