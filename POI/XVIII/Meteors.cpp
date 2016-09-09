/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>
 
#define REP(i, n)	for(int i=0;i<n;i++)
#define REPN(i, n)	for(int i=1;i<=n;i++)
#define SET(i, n)	memset(i, n, sizeof(i))
 
#define MAX		300050
#define pb		push_back
#define INF		(1 << 28)
 
using namespace std;
 
typedef long long ll;
 
ll A[MAX], T[MAX], maxi;
int ret[MAX], n, m, k;
int L[MAX], R[MAX], V[MAX];
int lo[MAX], hi[MAX];
vector<int>M[MAX];
vector<int>edge[MAX];
 
void update(int idx, ll val){
	while(idx <= n){
		T[idx] += val;
		idx += (idx & -idx);
	}
}
 
ll query(int idx){
	ll ret = 0;
	while(idx > 0){
		ret += T[idx];
		idx -= (idx & -idx);
	}
	return ret;
}
 
void apply(int idx){
	if(R[idx] < L[idx]){
		update(1, V[idx]);
		update(L[idx], V[idx]);
		update(R[idx]+1, -V[idx]);
	}
	else{
		update(L[idx], V[idx]);
		update(R[idx]+1, -V[idx]);
	}
}
 
int main(){
	REPN(i, MAX-1) ret[i] = INF;
	int x, y, c;
	scanf("%d %d", &m, &n);
	REPN(i, n){
		scanf("%d", &x);
		edge[x].pb(i);
	}
	REPN(i, m){
		scanf("%lld", &A[i]);
		maxi = max(maxi, A[i]);
	}
	scanf("%d", &k);
	REPN(i, k) scanf("%d %d %d", &L[i], &R[i], &V[i]);
	REPN(i, m){
		lo[i] = 1;
		hi[i] = k;
		M[ (lo[i] + hi[i])/2  ].pb(i); 
	}
	bool flag = true;
	while(flag){
		SET(T, 0);
		flag = false;
		REPN(i, k){
			apply(i);
			REP(f, M[i].size()){
				int u = M[i][f];
				
				ll tot = 0;
				REP(j, edge[u].size()){
					int v = edge[u][j];
					tot += query(v);
					tot = min(tot, maxi);
				}
				
				if(tot >= A[u]){
					ret[u] = min(i, ret[u]);
					hi[u] = i - 1;
				}
				else lo[u] = i + 1;
				
				if(lo[u] <= hi[u]){
					M[ (lo[u] + hi[u]) / 2 ].pb(u);
					flag = true;
				}
			}
			M[i].clear();
		}
	}
 
	REPN(i, m){
		if(ret[i] >= INF) printf("NIE\n");
		else printf("%d\n", ret[i]);
	}
 
	return 0;
}
