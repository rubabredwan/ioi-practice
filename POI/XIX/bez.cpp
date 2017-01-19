/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

const int N = 500007;
const long long oo = 1e16;

int n, m, vis[N], comp = 0; 
long long sum = 0;
long long Q[N], B[N], V[N], P[N];
vector<int>edge[N], cost[N], order;

bool isBicolorable(int at, long long cst, int col){
	Q[at] = cst;
	B[at] = col;
	vis[at] = comp;
	bool ret = false;
	for(int i=0;i<edge[at].size();i++){
		int v = edge[at][i]; 
		long long c = cost[at][i];
		if(vis[v] == comp){
			if(B[v] == B[at]) ret = true;
			continue;	
		}
		ret |= isBicolorable(v, c-cst, col^1);
	}
	order.push_back(at);
	return ret;
}

bool dependency_check(int at, long long val){
	V[at] = val; sum += V[at];
	vis[at] = comp;
	bool ret = true;
	if(V[at] < 0 || V[at] > P[at]) ret = false;
	for(int i=0;i<edge[at].size();i++){
		int u = edge[at][i]; 
		long long c = cost[at][i];
		if(vis[u] != comp) ret &= dependency_check(u, c - val);
		if(V[at] + V[u] != c) ret = false;
	}
	return ret;
}

void solve(){
	long long ret = 0, r1 = 0, r2 = 0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		++comp;
		bool bic = isBicolorable(i, 0, 0);
		if(bic == true){
			long long pp;
			for(int j=0;j<order.size();j++){
				int u = order[j];
				for(int k=0;k<edge[u].size();k++){
					int v = edge[u][k], c = cost[u][k];
					if(B[u] != B[v]) continue;
					if(B[u] == 1) pp = (Q[u] + Q[v] - c) / 2;
					else pp = (c - Q[u] - Q[v]) / 2;
				}
			}
			++comp;
			if(dependency_check(i, pp) == false){
				printf("NIE\n");
				return;
			}
			for(int j=0;j<order.size();j++){
				int u = order[j];
				ret += P[u] -  V[u];
			}
		}
		else{
			long long lo = 0, hi = P[i], black = 0, white = 0; 
			long long tot = 0;
			for(int j=0;j<order.size();j++){
				int u = order[j];
				if(B[u] == 0) lo = max(lo, -Q[u]), hi = min(hi, P[u] - Q[u]), white++;
				else lo = max(lo, Q[u] - P[u]), hi = min(hi, Q[u]), black++;
				tot += P[u];
			}
			if(lo > hi){
				printf("NIE\n");
				return;
			}
			long long mn = +oo, mx = -oo;
			comp++; sum=0;
			if(dependency_check(i, lo) == false){ printf("NIE\n"); return; }
			mn = min(mn, tot-sum), mx = max(mx, tot-sum);
			comp++; sum=0;
			if(dependency_check(i, hi) == false){ printf("NIE\n"); return; }
			mn = min(mn, tot-sum), mx = max(mx, tot-sum);
			r1 += mn, r2 += mx;
		}
		order.clear();
	}
	printf("%lld %lld\n", r1+ret, r2+ret);
}

int main(){
//	freopen("in.txt", "r", stdin);
	int x, y, c;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++) scanf("%lld", &P[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d", &x, &y, &c);
		edge[x].push_back(y);
		edge[y].push_back(x);
		cost[x].push_back(c);
		cost[y].push_back(c);
	}
	solve();
	return 0;
}
