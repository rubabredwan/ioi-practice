#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			100005
#define inf			1e12
#define pb			push_back

#define PI  		acos(-1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct QuizShow{
	int wager(vector <int> scores, int wager1, int wager2){
    	int ret = 0, fx = 0;
    	for(int wage=0;wage<=scores[0];wage++){
    		int ans = 0;
    		for(int i=-1;i<=1;i+=2){
    			for(int j=-1;j<=1;j+=2){
    				for(int k=-1;k<=1;k+=2){
    					if(scores[0] + wage * i > scores[1] + wager1 * j && scores[0] + wage * i > scores[2] + wager2 * k) ans++;
    				}
    			}
    		}
    		if(ans > fx) fx = ans, ret = wage;
    	}
    	return ret;
	}
};
