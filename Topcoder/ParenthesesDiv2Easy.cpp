#include <bits/stdc++.h> 

#define REP(i, n)        for(int i=0;i<n;i++) 
#define REPN(i, n)     for(int i=1;i<=n;i++) 
#define SET(i, n)      memset(i, n, sizeof(i)) 

#define MAX    100 
#define INF    1e9 
#define EPS    1e-9 
#define PI    acos(-1) 
#define pb    push_back 

using namespace std; 

typedef long long ll; 

int dp[MAX][MAX]; 

struct ParenthesesDiv2Easy{ 

  string f; 

  bool isOK(int l, int r){ 
    stack<int>st; 
    for(int i=l;i<=r;i++){ 
      if(f[i] == '('){ 
        st.push(1); 
      } 
      else{ 
        if(st.empty()) return 0; 
        st.pop(); 
      } 
    } 
    if(st.empty()) return 1; 
    else return  0; 
  } 

  bool Canbe(int l, int r){ 
    stack<int>st; 
    for(int i=l;i<=r;i++){ 
      if(f[i] == '('){ 
        st.push(1); 
      } 
      else{ 
        st.pop(); 
      } 
      if(st.empty() && i != r) return 1; 
    } 
    return  0; 
  } 

  int recur(int l, int r){ 
    if(r < l) return 0; 
    if(dp[l][r] != -1) return dp[l][r]; 
    if(isOK(l+1, r-1)) return dp[l][r] = 1 + recur(l+1, r-1); 
        int ret = 0; 
    for(int i=l+1;i<=r;i++){ 
      if(!isOK(l, i)) continue; 
      if(!isOK(i+1, r)) continue; 
      ret = max(ret, 1 +  recur(l+1, i-1) ); 
      if(isOK( i+2, r-1 )) ret = max(ret, 1 + recur(i+2, r-1)); 
      else ret = max(ret, recur(i+1, r)); 
      break; 
    } 
    return dp[l][r] = ret; 
  } 


  int getDepth(string s){ 
      f = s; SET(dp, -1); 
      int ret = recur(0, s.size()-1); 
      return ret; 
  } 


}; 
