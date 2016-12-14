/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx	3000007
#define pb	push_back
#define oo	1e9 

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k, cnt[mx];
int occupied[mx];

int main(){
	freopen("empty.in", "r", stdin);
	freopen("empty.out", "w", stdout);
	int x, y;
	long long a, b;
	scanf("%d %d", &n, &k);
	rep(i, k){
		scanf("%d %d %lld %lld", &x, &y, &a, &b);
		for(long long i=1;i<=y;i++){
			ll f = (a * i + b) % ll(n);
			cnt[f] += x;
		}
	}
	int hand = 0;
	rep(i, n){
		hand += cnt[i];
		if(occupied[i] == 0 && hand){
			occupied[i] = 1;
			hand--;
		}
	}
	rep(i, n){
		if(occupied[i] == 0 && hand){
			hand--;
			occupied[i] = 1;
		}
	}
	int ret = n;
	rep(i, n) if(occupied[i] == 0){ ret = i; break; }
	printf("%d\n", ret);
	return 0;
}

