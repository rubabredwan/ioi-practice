/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define read(x)		freopen(x, "r", stdin)
#define write(x) 	freopen(x, "w", stdout)

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			1000005
#define pb			push_back

#define inf			(1 << 29)	
#define	eps			1e-6
#define pi 			acos(-1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, xx[mx], yy[mx];
vector<int>cord[mx];
int bit[2][mx];
int N = 1e6;

void update(int id, int pos, int val){
	while(pos <= N){
		bit[id][pos] += val;
		pos += pos & -pos;
	}
}

int query(int id, int pos){
	int ret = 0;
	while(pos){
		ret += bit[id][pos];
		pos -= pos & -pos;
	}
	return ret;
}

int main(){
	read("balancing.in");
	write("balancing.out");
	scanf("%d", &n);
	repn(i, n){
		scanf("%d %d", &xx[i], &yy[i]);
		cord[ xx[i] ].push_back(yy[i]);
		update(1, yy[i], +1);
	}
	int ret = inf;
	for(int i=0;i<=N;i++){
		if(i % 2 == 0){
			int lo = 0, hi = N, rt = inf;
			while(lo <= hi){
				int mid = (lo + hi) / 2;
				int r1 = query(0, mid), r2 = query(1, mid);
				int r3 = query(0, N) - r1, r4 = query(1, N) - r2;
				int a = max(r1, r2);
				int b = max(r3, r4);
				rt = min(rt, max(a, b));
				if(a == b) break;
				else if(a < b) lo = mid + 1;
				else hi = mid - 1;
			}
			ret = min(ret, rt);
		}
		else{
			for(auto x : cord[i]){
				update(1, x, -1);
				update(0, x, +1);
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
