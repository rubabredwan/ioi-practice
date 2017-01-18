/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define f	first
#define s	second

using namespace std;

void scanF(long long &x){
    long long c = getchar();
    x = 0;
    int neg = 0;
    for(;((c < 48 || c > 57) && c != '-');c = getchar());
    if(c == '-'){ 
		neg = 1; 
		c = getchar();
	}
    for(;c > 47 && c < 58;c = getchar()){
		x = (x<<1LL) + (x<<3LL) + c - 48LL;
	}
    if(neg) x = -x;
}


typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll>fii;

const int N = 100007;
const int M = 300007;

int n, m, idx;
long long p[N], d[N];
long long s[N], t[N];
long long tsum[M*4], tmin[M*4], V[M];
map<long long, int>mp;
vector<pii>pairs; 
vector<fii>order;
vector<int>ans;

void reset(){
	pairs.clear();
	mp.clear();
	ans.clear();
	order.clear();
	idx = 0;
}

void build(int b, int e, int node){
	if(b == e){
		tsum[node] = V[b];
		tmin[node] = V[b];
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	build(b, mid, l);
	build(mid+1, e, h);
	tsum[node] = tsum[l] + tsum[h];
	tmin[node] = min(tmin[l], tsum[l] + tmin[h]);
}

void update(int b, int e, int node, int pos, int val){
	if(b == e){
		tsum[node] += val;
		tmin[node] += val;
		return;
	}
	int mid = (b + e) / 2, l = 2 * node, h = l + 1;
	if(pos <= mid) update(b, mid, l, pos, val);
	else update(mid+1, e, h, pos, val);
	tsum[node] = tsum[l] + tsum[h];
	tmin[node] = min(tmin[l], tsum[l] + tmin[h]);
}

void init(){
	repn(i, n) mp[d[i]];
	repn(i, m) mp[s[i]], mp[t[i]];
	for(auto &u : mp) u.s = ++idx;
	repn(i, n) pairs.push_back({d[i], 3});
	repn(i, m) pairs.push_back({s[i], 1}), pairs.push_back({t[i], 2});
	sort(pairs.begin(), pairs.end());
	long long past = 0, ptp = 2;
	for(int i=0;i<pairs.size();i++){
		long long tp = pairs[ i ].s;
		long long st = pairs[ i ].f;
		if(ptp == 1 && tp == 2){
			if(st != past) V[mp[  st  ]] = 0;
		}
		else{
			long long raga = st - past;
			if(tp == 1) raga--;
			V[ mp[ st ] ] = raga;
		}
		past = st;
		ptp = tp;
	}
	build(1, idx, 1);
}

int solve(){
	init();
	repn(i, n) order.push_back({{p[i], d[i]}, i});
	sort(order.begin(), order.end());
	int ret = 0;
	for(auto u : order){
		long long date = u.f.s;
		long long need = u.f.f + 1LL;
		long long dx = u.s;
		update(1, idx, 1, mp[date], -need);
		if(tmin[1] < 0) update(1, idx, 1, mp[date], need);
		else{
			ret++;
			ans.push_back(dx);
		}
	}
	return ret;
}

int main(){
	freopen("intelligent.in", "r", stdin);
	freopen("intelligent.out", "w", stdout);
	while(scanf("%d", &n) == 1){
		if(n == 0) break;
		reset();
		repn(i, n) scanf("%lld %lld", &d[i], &p[i]);
		scanf("%d", &m);
		repn(i, m) scanf("%lld %lld", &s[i], &t[i]);
		int ret = solve();
		printf("%d\n", ret);
		sort(ans.begin(), ans.end());
		for(auto u : ans) printf("%d ", u);
		printf("\n");
	}
	return 0;
}
