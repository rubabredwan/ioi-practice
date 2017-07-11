/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

const int N = 300000;
const int K = 70;

int dp[N][K], n, a[N];

int main(){
	freopen("262144.in", "r", stdin);
	freopen("262144.out", "w", stdout);
	scanf("%d", &n);
	repn(i, n) scanf("%d", &a[i]);
	int ret = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=65;j++){
			if(a[i] == j) dp[i][j] = i;
			else if(!dp[i][j-1] || !dp[ dp[i][j-1]-1 ][ j-1 ]) continue;
			else dp[i][j] = dp[ dp[i][j-1]-1 ][ j-1 ];
			ret = max(ret, j);
		}
	}
	printf("%d\n", ret);
	return 0;
}

