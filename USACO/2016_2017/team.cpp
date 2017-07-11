/* Bismilong longahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

const int N = 1003;
const long long mod = 1e9 + 9;

int n, m, k;
int a[N], b[N];
long long  dp[N][N][12];
bool vp[N][N][12];

long long recur(long long x, long long y, long long left){
	if(left == 0) return 1;
	if(x == 0 || y == 0) return 0;
	if(vp[x][y][left]) return dp[x][y][left];
	long long ret = 0;
	ret += recur(x-1, y, left);
	ret += recur(x, y-1, left);
	ret -= recur(x-1, y-1, left);
	if(a[x] > b[y]){
		ret += recur(x-1, y-1, left-1);
	}
	vp[x][y][left] = 1;
	return dp[x][y][left] = ret % mod;
}

int main(){
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	long long ret = recur(n, m, k);
	ret += mod;
	ret %= mod;
	printf("%lld\n", ret);
	return 0;
}
