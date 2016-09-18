/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define read(x) 	freopen(x, "r", stdin)
#define write(x) 	freopen(x, "w", stdout)

#define rep(i, n)	for(ll i=0;i<n;i++)
#define repn(i, n)	for(ll i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define inf			1e9
#define pb			push_back
#define mx			2005

using namespace std;

typedef long long ll;

struct data{
	ll st, f, c;
	bool operator < (const data &p) const{
		return c < p.c;
	}
	data () {}
	data (ll a, ll b, ll d){
		st = a;
		f = b;
		c = d;
	}
};

ll n, m, a, b, par[mx*mx];
vector<ll>xx, yy;
vector<data>edge;
ll tot;

ll Find(ll at){
	if(par[at] == at) return at;
	return par[at] = Find(par[at]);
}

ll solve(){
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	for(ll k=1, st = 1;k<yy.size();k++, st+=a+1){
		ll sz = yy[k] - yy[k-1];
		edge.push_back(data(st, 0, sz));
	}
	for(ll k=1, st = 1;k<xx.size();k++, st++){
		ll sz = xx[k] - xx[k-1];
		edge.push_back(data(st, 1, sz));
	}
	repn(i, tot) par[i] = i;
	sort(edge.begin(), edge.end());
	ll ret = 0;
	rep(i, edge.size()){
		ll x = edge[i].st, y = edge[i].f, c = edge[i].c;
		if(!y){
			for(int j=x+1;j<=x+a;j++){
				if(Find(j) != Find(j-1)){
					ret += c;
					par[Find(j)] = Find(j-1);
				}
			}
		}
		else{
			for(int j=x, cnt=1;cnt<=b;cnt++, j+=a+1){
				if(Find(j) != Find(j+a+1)){
					par[Find(j)] = Find(j+a+1);
					ret += c;
				}
			}
		}
	}
	return ret;
}




int main(){
	read("fencedin.in");
	write("fencedin.out");
	ll x, y;
	cin >> n >> m >> a >> b;
	tot = (a + 1) * (b + 1);
	rep(i, a){
		cin >> x;
		xx.pb(x);
	}
	rep(i, b){
		cin >> y;
		yy.pb(y);
	}
	xx.pb(0); xx.pb(n);
	yy.pb(0); yy.pb(m);
	ll ret = solve();
	cout << ret << endl;
}
