/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 1000005;

int n, q;
int a[N], b[N], c[N];
int m[N], k[N], s[N];
int ans[N], dp[N];

int main(){
	vector <pii> aa, bb;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d %d", &c[i], &a[i], &b[i]);
		aa.push_back(make_pair(a[i], i));
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		scanf("%d %d %d", &m[i], &k[i], &s[i]);
		bb.push_back(make_pair(m[i], i));
	}
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	dp[0] = INT_MAX;
	int ptr = 0;
	for(int j = 0; j < bb.size(); ++j){
		pii u = bb[j];
		while(ptr < aa.size() && aa[ptr].first <= u.first){
			int id = aa[ptr].second;
			for(int i = 100000; i >= c[id]; --i){
				dp[i] = max(dp[i], min(dp[i-c[id]], b[id]));
			}
			++ptr;
		}
		int id = u.second;
		ans[id] = (dp[ k[id] ] > (m[id] + s[id]));
	}
	for(int i = 1; i <= q; ++i){
		if(ans[i]) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}