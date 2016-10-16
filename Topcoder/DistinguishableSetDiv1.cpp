#include <bits/stdc++.h>
 
#define REP(i, n)  for(int i=0;i<n;i++)
#define REPN(i, n)  for(int i=1;i<=n;i++)
#define SET(i, n)  memset(i, n, sizeof(i))
 
#define MAXN    53
#define MAXK    260
 
using namespace std;
 
struct TrySail{
  vector<int>vec;
  int dp[MAXN][MAXK][MAXK][2][2], DP[MAXN][MAXK][MAXK][2][2];
  int solve(){
    int n = vec.size();
    dp[ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 1;
    REPN(i, n){
      REP(f, 51) REP(j, MAXK) REP(k, MAXK) REP(a, 2) REP(b, 2) DP[f][j][k][a][b] = dp[f][j][k][a][b];
      REP(f, 51) REP(j, MAXK) REP(k, MAXK) REP(a, 2) REP(b, 2) {
        if(!dp[f][j][k][a][b]) continue;
      //  cout << "HELLo\n";
        int z = vec[i-1];
      //  cout << f << ' ' << j << ' ' << k << ' ' << a << ' ' << b << endl;
        DP[f+1][j^z][k][a|1][b] = 1;
      //  cout << f+1 << j << (k^z) << a << (b|1) << endl;
      //  cout << f+1 << (j^z) << (k) << (a|1) << b  << endl;
        DP[f+1][j][k^z][a][b|1] = 1;
        
      }
      REP(f, 51) REP(j, MAXK) REP(k, MAXK) REP(a, 2) REP(b, 2) dp[f][j][k][a][b] = DP[f][j][k][a][b];
    }
    int tot = 0;
    REP(i, n){
      tot ^= vec[i];
    }
    int ret = 0;
    for(int i=1;i<n;i++){
      REP(j, MAXK){
        REP(k, MAXK){
          //cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k][1][1] << endl;
          if(dp[i][j][k][1][1]){
            ret = max(ret, j + k + (tot ^ j ^ k));
          }
        }
      }
    }
    return ret;
  }
  
  int get(vector<int>s){
    vec = s;
    int ret = solve();
  //  cout << "@@@ " << ret << endl;
    return ret;
  }
 
};
