/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

struct bit{
	int t[N], n, tot;
	void init(){
		memset(t, 0, sizeof(t));
		n = 1000000;
		tot = 0;
	}
	void update(int pos, int val){
		while(pos <= n){
			t[pos] += val;
			pos += pos & -pos;
		}
		tot += val;
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

vector <int> ins[N];
bit t1, t2;

int main(){
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	t1.init();
	t2.init();
	int n, x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &x, &y);
		ins[x].push_back(y);
		t2.update(y, +1);
	}
	int ret = n;
	for(int i = 1; i <= 1000000; ++i){
		if(i & 1){
			for(auto u : ins[i]){
				t2.update(u, -1);
				t1.update(u, +1);
			}
		}
		else{
			int lo = 1, hi = 1000000;
			while(lo <= hi){
				int mid = (lo + hi) / 2;
				int m1 = t1.get(mid), m2 = t1.tot - m1;
				int m3 = t2.get(mid), m4 = t2.tot - m3;
				ret = min(ret, max({m1, m2, m3, m4}));
				if(max(m1, m3) == max(m2, m4)) break;
				else if(max(m1, m3) < max(m2, m4)) lo = mid + 1;
				else hi = mid - 1;
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}

