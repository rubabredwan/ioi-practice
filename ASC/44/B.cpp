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

const int N = 5007;
const double eps = 1e-6;

int n;
double A[N][5], S[N][5];
double dp[N][2], P[5];
int vis[N][2];

double solve(int s, int e){
	repn(i, 4) P[i] = S[e][i] - S[s-1][i];
	double P1 = P[1] + P[2];
	double P2 = P[3] + P[4];
	double TT = P[1] + P[3];
	if(TT < eps) return min(P[2], P[4]);
	if(P1 < P[4]) return P1;
	if(P2 < P[2]) return P2;
	return ((((P[4] + P[3]) - P[2]) / (P[1] + P[3])) * P[1]) + P[2];
}

double recur(int at, int tp){
	if(at == n + 1) return 0;
	if(vis[at][tp]) return dp[at][tp];
	double ret;
	if(tp) ret = -1e18;
	else ret = 1e18;
	for(int i=at;i<=n;i++){
		if(tp) ret = max(ret, solve(at, i) + recur(i+1, tp));
		else ret = min(ret, solve(at, i) + recur(i+1, tp));
	}
	vis[at][tp] = 1;
	return dp[at][tp] = ret;
}

int main(){
	freopen("braess.in", "r", stdin);
	freopen("braess.out", "w", stdout);
	scanf("%d", &n);
	repn(i, n){
		repn(j, 4){
			scanf("%lf", &A[i][j]);
			S[i][j] = A[i][j] + S[i-1][j];
		}
	}
	double ret1 = solve(1, n);
	double ret2 = 0.0;
	repn(i, n) ret2 += solve(i, i);
	double ret3 = recur(1, 0);
	double ret4 = recur(1, 1);
	printf("%.10lf\n", ret1);
	printf("%.10lf\n", ret2);
	printf("%.10lf\n", ret3);
	printf("%.10lf\n", ret4);
	return 0;
}