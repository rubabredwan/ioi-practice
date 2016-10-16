#include <bits/stdc++.h> 

#define REP(i, n)        for(int i=0;i<n;i++) 
#define REPN(i, n)     for(int i=1;i<=n;i++) 
#define SET(i, n)      memset(i, n, sizeof(i)) 

#define MAX    100050 
#define INF    1e9 
#define EPS    1e-9 
#define PI    acos(-1) 
#define pb    push_back 

using namespace std; 

typedef long long ll; 

struct ParenthesesDiv2Medium{ 
  vector <int> correct(string s){ 
        vector <int> ret; 
      int n = s.size(); 
      stack<int>st; 
      int f = n/2; 
      for(int i=0;i<n;i++){ 
            if(s[i] == '('){ 
                if(st.size()+1 < n - i){ 
                    st.push(i); 
                }    
                else{ 
                    ret.pb(i); 
                    st.pop(); 
                }                  
            } 
            else{ 
                 
                if(st.size()){ 
                    st.pop(); 
                } 
                else{ 
                    ret.pb(i); 
                    st.push(i); 
                } 
            } 
      } 
       
      return ret; 
  } 
   

};
