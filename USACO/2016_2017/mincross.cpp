/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, a[N], b[N], p[N], q[N];

struct bit{
	int t[N];
	void init(){
		memset(t, 0, sizeof(t));
	}
	void update(int pos, int val){
		while(pos <= n){
			t[pos] += val;
			pos += pos & -pos;
		}
	}
	int get(int pos){
		int ret = 0;
		while(pos){
			ret += t[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

bit T;

int main(){
	freopen("mincross.in", "r", stdin);
	freopen("mincross.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &p[i]);
		a[p[i]] = i;
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &q[i]);
		b[q[i]] = i;
	}
	T.init();
	for(int i = 1; i <= n; ++i) T.update(i, +1);
	long long tot = 0;
	for(int i = 1; i <= n; ++i){
		int id = p[i];
		T.update(b[id], -1);
		tot += T.get(b[id]);
	}
	long long ans = 0;
	long long aa = 0, bb = 0;
	for(int i = n; i >= 1; --i){
		aa += 2 * b[p[i]] - (n + 1);
		bb += 2 * a[q[i]] - (n + 1);
		ans = min({ans, aa, bb});
	}
	tot += ans;
	cout << tot << endl;
	return 0;
}