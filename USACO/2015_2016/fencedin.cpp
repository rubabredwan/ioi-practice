/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> pii;

const long long N = 25005;

long long A, B, n, m;
vector <long long> xx, yy;
vector <pii> mst;

int main(){
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	long long x;
	scanf("%lld %lld %lld %lld", &A, &B, &n, &m);
	for(long long i = 1; i <= n; ++i){
		scanf("%lld", &x);
		xx.push_back(x);
	}
	for(long long i = 1; i <= m; ++i){
		scanf("%lld", &x);
		yy.push_back(x);
	}
	xx.push_back(0);
	xx.push_back(A);
	yy.push_back(0);
	yy.push_back(B);
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	for(long long i = 1; i < xx.size(); ++i){
		mst.push_back({xx[i] - xx[i-1], 0});
	}
	for(long long i = 1; i < yy.size(); ++i){
		mst.push_back({yy[i] - yy[i-1], 1});
	}
	sort(mst.begin(), mst.end());
	long long cnt[2] = {0, 0};
	long long ret = 0;
	for(auto u : mst){
		if(cnt[0] && cnt[1]){
			if(u.second == 0) ret += u.first * (m - cnt[1] + 1);
			else ret += u.first * (n - cnt[0] + 1);
		}
		else{
			if(u.second == 0) ret += u.first * m;
			else ret += u.first * n;
		}
		++cnt[u.second];
	}
	printf("%lld\n", ret);
	return 0;
}