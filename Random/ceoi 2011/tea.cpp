/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back
#define gc	getchar_unlocked
#define f	first
#define s	second

using namespace std;

const int N = 1000005;
const int oo = 1e9;
const int SQ = 1000;

typedef pair<int, int>pii;

void scanF(int &x){
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int n, mx, lst[N];
pii A[N], dp[N], dummy;

void init(){
	sort(A+1, A+1+n);
	dp[0] = make_pair(0, 0);
	for(int i=1;i<=n;i++){ 
		dp[i] = dp[i-1]; 
		if(i - A[i].f > 0) dp[i] = max(dp[i], make_pair(dp[ i - A[i].f ].f + 1, 0));
	}
	mx = dp[n].f;
}

void reset(){
	dummy = make_pair(-oo, +oo);
	rep(i, N) dp[i] = dummy;
}

bool OK(int gap, bool print){
	reset();
	dp[0] = make_pair(0, 0);
	lst[0] = 0;
	for(int i=1;i<=n;i++){
		lst[i] = lst[i-1];

		if(A[i].first > i) continue;

		if(gap >= i) dp[i] = make_pair(1, 0);

		if(i > A[i].first){
			int S = max(1, i - gap), E = i - A[i].first;
			if(lst[E] >= S){
				pii g = dp[lst[E]]; 
				g.f += 1, g.s = lst[E];
				dp[i] = max(dp[i], g);
			}
		}

		if(dp[i].f >= dp[lst[i]].f) lst[i] = i;

	}
	if(!print){
		if(dp[n].f >= mx) return true;
		else return false;
	}
	printf("%d\n", dp[n].f);
	int cur = n;
	while(cur){
		int f = dp[cur].s;
		printf("%d", cur - f);
		for(int i=f+1;i<=cur;i++) printf(" %d", A[i].s);
		printf("\n");
		cur = f;
	}
	return true;
}

int main(){
	scanF(n);
	repn(i, n) scanF(A[i].first), A[i].second = i;
	init();
	int lo = A[n].first, hi = n, ret = n;
	while(lo <= hi){
		int Mid = (lo + hi) / 2;
		if(OK(Mid, 0)) ret = Mid, hi = Mid - 1;
		else lo = Mid + 1;
	}
	OK(ret, 1);
	return 0;
}

