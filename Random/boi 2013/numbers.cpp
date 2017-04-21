/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

long long dp[20][15][15][2][2][2];
vector<int>digits;

int isPal(int a, int b, int c){
	if(b == c) return 1;
	if(a == c) return 1;
	return 0;
}

long long recur(int pos, int l0, int l1, int pal, int fol, int st){
	if(pos == digits.size()) return pal;
	if(dp[pos][l0][l1][pal][fol][st] != -1) return dp[pos][l0][l1][pal][fol][st];
	long long ret = 0, en = fol ? digits[pos] : 9;
	for(int i=0;i<en;i++){ 
		int np = pal | isPal(l0, l1, i);
		if(i == 0){
			if(st) ret += recur(pos+1, l1, i, np, 0, 1);
			else ret += recur(pos+1, l1, 10, np, 0, 0);
		}
		else ret += recur(pos+1, l1, i, np, 0, 1);
	}

	ret += recur(pos+1, l1, en, pal | isPal(l0, l1, en), fol, 1);

	return dp[pos][l0][l1][pal][fol][st] = ret;
}

long long solve(long long val){
	if(val <= 9) return val;
	digits.clear(); set(dp, -1);
	long long n = val;
	while(val){
		digits.pb(val % 10LL);
		val /= 10LL;
	}
	reverse(digits.begin(), digits.end());
	return n - recur(0, 10, 10, 0, 1, 0);
}

int main(){
	long long a, b;
	cin >> a >> b;
	cout << solve(b) - solve(a-1) << endl;
	return 0;
}

