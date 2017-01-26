/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back
#define f	first
#define s	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100007;

int n, fx;
vector<int>edge[N];

int dfs(int at, int past){
	int mask = 0, cnt[25];
	set(cnt, 0);
	rep(i, edge[at].size()){
		int u = edge[at][i];
		if(u == past) continue;
		int fask = dfs(u, at);
		rep(j, 20){
			if(fask & (1 << j)) cnt[j]++;
		}
		mask |= fask;
	}
	int s = 0;
	for(int i=20;i>=0;i--){
		 if(cnt[i] < 2) continue;
		 s = i + 1;
		 break;
	} 
	for(int i=s;i<=20;i++){
		if(cnt[i] == 0){
			for(int j=0;j<i;j++) if(mask & (1 << j)) mask ^= (1 << j);
			mask |= (1 << i);
			return mask;
		}
	}
}

int main(){
	int x, y;
	scanf("%d", &n);
	repn(i, n-1){
		scanf("%d %d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	int ret = dfs(1, 1);
	for(int i=20;i>=0;i--){
		if(ret & (1 << i)){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}