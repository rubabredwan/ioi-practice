/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define read(x)		freopen(x, "r", stdin)
#define write(x) 	freopen(x, "w", stdout)

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		10005
#define pb		push_back

#define inf		(1 << 29)	
#define	eps		1e-6
#define pi 		acos(-1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, in[mx];
vector<int>edge[mx];

int main(){
	int x, y;
	scanf("%d %d", &n, &m);
	rep(i, m){
		scanf("%d %d", &x, &y);
		edge[x].pb(y);
		edge[y].pb(x);
		in[x]++;
		in[y]++;
	}
	vector<pii>vec;
	repn(i, n) vec.pb(pii(in[i], i));
	sort(vec.begin(), vec.end());
	rep(i, vec.size()/3){
		x = vec[i].first, y = vec[i].second;
		rep(j, edge[y].size()){
			int u = edge[y][j];
			in[u]--;
			in[y]--;
		}
	}
	vec.clear();
	repn(i, n) vec.pb(pii(in[i], i));
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	vector<int>ret;
	rep(i, n/3) ret.pb(vec[i].second);
	sort(ret.begin(), ret.end());
	rep(i, n/3) printf("%d\n", ret[i]);
	return 0;
}

