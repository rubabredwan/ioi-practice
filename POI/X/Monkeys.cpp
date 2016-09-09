/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define read(x)		freopen(x, "r", stdin)
#define write(x) 	freopen(x, "w", stdout)

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			400005
#define pb			push_back

#define inf			(1 << 29)	
#define	eps			1e-6
#define pi 			acos(-1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int ret[mx];
int b[mx][2];
int f[mx][2];
int del[mx][2];
int par[mx];
vector<int>fft[mx];

int Find(int at){
	if(par[at] == at) return at;
	return par[at] = Find(par[at]);
}

void Union(int x, int y, int t){
	int a = Find(x);
	int b = Find(y);
	if(a == b) return;
	if(a > b) swap(a, b);
	if(a == 1){
		par[b] = 1;
		rep(i, fft[b].size()) ret[fft[b][i]] = t;
	}
	else{
		if(fft[a].size() > fft[b].size()) swap(a, b);
		par[a] = b;
		rep(i, fft[a].size()) fft[b].push_back(fft[a][i]);
	}
}

void init(){
	repn(i, n){
		par[i] = i;
		fft[i].pb(i);
	}
}

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	init();
	repn(i, n){
		scanf("%d %d", &x, &y);
		b[i][0] = x, b[i][1] = y;
		f[i][0] = x, f[i][1] = y;
	}
	set(ret, -1);
	repn(i, m){
		scanf("%d %d", &x, &y); y--;
		f[x][y] = -1;
		del[i][0] = x;
		del[i][1] = y;
	}
	repn(i, n){
		if(f[i][0] != -1) Union(i, f[i][0], -1);
		if(f[i][1] != -1) Union(i, f[i][1], -1);
	}
	for(int i=m;i>=1;i--){
		x = del[i][0], y = del[i][1];
		f[x][y] = b[x][y];
		if(f[x][y] != -1) Union(x, f[x][y], i-1);
	}
	repn(i, n) printf("%d\n", ret[i]);
	return 0;
}

