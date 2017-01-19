/* Bismillahir Rahmanir Rahim */

#include "cliclib.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <cassert>

using namespace std;

const int N = 30007;
const int K = 100007;
const int M = 180;

int n, mp[K], id[K];
int dp[N][M];
int vp[N][M];

int recur(int stak, int pot){
	if(stak + id[pot] >= n) return 0;
	if(dp[stak][pot] != -1) return dp[stak][pot];
	dp[stak][pot] = 0, vp[stak][pot] = 1;
	if(1){
		int d = recur(stak, mp[id[pot] * 2]);
		if(d == 0) dp[stak][pot] = 1, vp[stak][pot] = 2;
	}
	if(1){
		int d = recur(stak, mp[id[pot] * 3]);
		if(d == 0) dp[stak][pot] = 1, vp[stak][pot] = 3;
	}
	int d = recur(stak+id[pot], mp[1]);
	if(d == 0) dp[stak][pot] = 1, vp[stak][pot] = 1;	
	return dp[stak][pot];
}

void init(){
	long long tw = 1;
	set<int>S;
	for(int i=0;i<20;i++){
		long long th = 1;
		for(int j=0;j<20;j++){
			if(tw * th > (long long)(N)) break;
			S.insert(tw * th);
			th *= 3LL;
		}
		tw *= 2LL;
	}
	long long a = 1, b = 1;
	for(int i=0;i<20;i++){
		if(a < N) S.insert(a);
		if(b < N) S.insert(b);
		a *= 2LL;
		b *= 3LL;
	}
	set<int>::iterator it;
	int idx = 0;
	id[0] = 1e9;
	for(it=S.begin();it!=S.end();it++){
		mp[*it] = ++idx;
		id[idx] = *it;
	}
}

int main() {
	n = inicjuj();
	int stak = 0, pot = 1;
	memset(dp, -1, sizeof(dp));
	init();
  	while(true){
  		recur(stak, mp[pot]);
  		int mv = vp[stak][mp[pot]];
    	alojzy(mv);
    	if(mv == 2) pot *= 2;
    	if(mv == 3) pot *= 3;
    	if(mv == 1) stak += pot, pot = 1;
    	int op = bajtazar(); // Wczytujemy ruch Bajtazara, ale go ignorujemy
    	if(op == 2) pot *= 2;
    	if(op == 3) pot *= 3;
    	if(op == 1) stak += pot, pot = 1;
  	}
  	return 0;
}
