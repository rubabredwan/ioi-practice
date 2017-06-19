/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

const int N = 1000007;

int n, m, b[N], used[N], st[N];

int main(){
	int x;
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d", &x);
		b[x] = 1;
	}
	scanf("%d", &n);
	vector <long long> ans;
	long long idx = 0;
	while(n--){
		scanf("%d", &x);
		if(st[x] == 0) st[x] = x;
		long long cs = 0;
		for(int i = st[x]; i < N && cs < x; i += x, st[x] = i){
			if(used[i]) continue;
			++cs;
			used[i] = 1;
			if(b[i]) ans.push_back(idx + cs);
		}
		idx += x;
	}
	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size(); ++i){		
		printf("%lld\n", ans[i]);
	}
	return 0;
}