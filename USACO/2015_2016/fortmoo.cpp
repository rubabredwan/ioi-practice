/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n, m;
char g[N][N];
int sum[N][N];

int get(int a, int b, int c, int d){
	return sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1];
}

bool ok(int a, int b, int c, int d){
	if(get(a, c, a, d)) return false;
	if(get(b, c, b, d)) return false;
	if(get(a, c, b, c)) return false;
	return true;
}

int main(){
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			if(g[i][j] == 'X') sum[i][j] += 1;
		}
	}
	int ret = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			int ptr = 1;
			for(int k = 1; k <= m; ++k){
				while(ptr <= k && !ok(i, j, ptr, k)) ++ptr;
				if(ptr < k && ok(i, j, k, k)){ 
					ret = max(ret, (k - ptr + 1) * (j - i + 1));
				}
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}

