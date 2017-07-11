/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int M = N * N;

int mat[N][N];
int n;
int mxx[M], mxy[M];
int mnx[M], mny[M];
int valid[M];

int main(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < M; ++i){
		mnx[i] = n + 1;
		mny[i] = n + 1;
	}
	set <int> s;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &mat[i][j]);
			if(mat[i][j] == 0) continue;
			s.insert(mat[i][j]);
			int c = mat[i][j];
			mnx[c] = min(mnx[c], i);
			mxx[c] = max(mxx[c], i);
			mny[c] = min(mny[c], j);
			mxy[c] = max(mxy[c], j);
		}
	}
	int col = n * n;
	if(s.size() == 1){
		printf("%d\n", col - 1);
		return 0;
	}
	for(int c = 1; c <= col; ++c){
		if(mxx[c] == 0) continue;
		for(int i = mnx[c]; i <= mxx[c]; ++i){
			for(int j = mny[c]; j <= mxy[c]; ++j){
				if(mat[i][j] == c) continue;
				valid[mat[i][j]] = 1;
			}
		}
	}
	int ret = 0;
	for(int c = 1; c <= col; ++c) ret += (!valid[c]);
	printf("%d\n", ret);
	return 0;
}

