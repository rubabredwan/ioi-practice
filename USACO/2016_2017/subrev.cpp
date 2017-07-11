/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int oo = 1e9;

int dp[N][N][N][N];
bool vis[N][N][N][N];
int n, a[N];

int recur(int l, int r, int lval, int rval){
	if(lval > rval) return -oo;
	if(l > r) return 0;
	if(l == r){
		if(lval <= a[l] && a[r] <= rval) return 1;
		else return 0;
	}
	if(vis[l][r][lval][rval]) return dp[l][r][lval][rval];
	vis[l][r][lval][rval] = 1;

	int ret = 0;

	// case #1

	ret = max(ret, recur(l + 1, r, lval, rval));
	if(lval <= a[l]){
		ret = max(ret, 1 + recur(l + 1, r, a[l], rval));
	}

	// case #2

	ret = max(ret, recur(l, r - 1, lval, rval));
	if(rval >= a[r]){
		ret = max(ret, 1 + recur(l, r - 1, lval, a[r]));
	}

	// case #3

	int x = 0, y = 0;
	if(lval <= a[r]) x = 1;
	if(rval >= a[l]) y = 1;

	if(x) ret = max(ret, 1 + recur(l + 1, r - 1, a[r], rval));
	if(y) ret = max(ret, 1 + recur(l + 1, r - 1, lval, a[l]));
	if(x && y) ret = max(ret, 2 + recur(l + 1, r - 1, a[r], a[l]));

	return dp[l][r][lval][rval] = ret;
}

int main(){
	freopen("subrev.in", "r", stdin);
	freopen("subrev.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	printf("%d\n", recur(1, n, 1, 50));
	return 0;
}
