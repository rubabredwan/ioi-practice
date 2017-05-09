/* Bismillahir Rahmanir Rahim */

#include "gap.h"
#include <bits/stdc++.h>

using namespace std;

const long long M = 1e18;

long long mdiff = 0;

void solve(long long st, long long en, long long n){
    long long mn, mx;
    MinMax(st, en, &mn, &mx);
    long long rng = 1LL + (mx - mn) / (n - 1LL);
    long long lst = mn;
	for(long long i=mn+1;i<mx;i+=rng){
		long long A, B;
		MinMax(i, min(i + rng - 1LL, mx), &A, &B);
		if(A == -1) continue;
		if(lst != -1) mdiff = max(mdiff, A - lst);
		lst = B;
	}
	if(lst != -1) mdiff = max(mdiff, mx - lst);
}


long long findGap(int T, int N){
    if(T == 1){
		long long st = 0, en = M;
		set<long long>S;
        for(int i=N;i>=0;i-=2){
			long long A, B;
			MinMax(st, en, &A, &B);
			S.insert(A);
			S.insert(B);
			st = A + 1LL;
			en = B - 1LL;
		}
		long long lst = -1;
		for(auto u : S){
			if(lst != -1) mdiff = max(mdiff, u - lst);
			lst = u;
		}
    }
    else solve(0, M, N);
	return mdiff;
}
