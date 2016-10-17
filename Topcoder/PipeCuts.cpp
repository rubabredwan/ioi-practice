/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			100005
#define inf			1e9
#define pb			push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct PipeCuts{
	double probability(vector <int> f, int L){
    	double ret = 0, cnt = 0;
		sort(f.begin(), f.end());
		rep(i, f.size()){
			for(int j=i+1;j<f.size();j++){
				int a = f[i];
				int b = f[j] - f[i];
				int c = 100 - f[j];
				if(a > L || b > L || c > L) ret += 1.0;
				cnt += 1.0;
//				cout << a << ' ' << b << ' ' << c << endl;
			}
		}
		ret = ret / cnt;
    	return ret;
	}
	
};
