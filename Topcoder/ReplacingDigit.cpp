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
typedef pair<int, int>  pii; 

struct ReplacingDigit{ 

  vector<int> getdigit(int n){ 
    int cur = n; 
    vector<int> digit; 
        if(cur == 0) digit.pb(0); 
        while(cur != 0){ 
          digit.pb(cur % 10); 
          cur /= 10; 
        } 
        reverse(digit.begin(), digit.end()); 
    return digit; 
  } 

  int getsum(vector<int>digit){ 
    int ret = 0; 
    for(int i=0;i<digit.size();i++){ 
      ret *= 10; 
      ret += digit[i]; 
    } 
    return ret; 
  } 

  int getMaximumStockWorth(vector <int> A, vector <int> D){ 
      int ret = 0; 
        sort(A.begin(), A.end()); 
        for(int i=9;i>=1;i--){ 
          int rem = D[i-1]; 
          bool F = false; 
          while(rem){ 
            vector<pair<pii, int> >vec; 
            REP(j, A.size()){ 
              int r1 = A[j]; 
              int r2 = 0; 
              bool flag = false; 
              vector<int>digit = getdigit(r1); 
              REP(k, digit.size()){ 
              //  cout << digit[k] << ' '; 
                if( i > digit[k] ){ 
                  flag = true; 
                  int cur = digit[k]; 
                  digit[k] = i; 
                  r2 = getsum(digit); 
              //    cout << "# " << j << ' ' << r2 << ' ' << k << endl; 
                  digit[k] = cur; 
                  break; 
                } 
              } 
            //  cout << endl; 
              if(flag == true){ 
                vec.pb(make_pair(pii(r2-r1, j), r2)); 
              } 
            } 
            sort(vec.rbegin(), vec.rend()); 
            //cout << "## " << vec.size() << endl; 
            if(vec.size()){ 
              int k = vec[0].first.second; 
              A[k] = vec[0].second; 
              rem--; 
            } 
            /*REP(f, vec.size()){ 
              cout << vec[f].first.first << ' ' << vec[f].first.second << ' ' << vec[f].second << endl; 
            }*/ 
            if(!vec.size()){ 
              F = true; 
              break; 
            } 
          } 
          if(F) break; 
        } 
      REP(i, A.size()) ret += A[i]; 
      return ret; 
    } 

}; 



// Powered by FileEdit 
// Powered by TZTester 1.01 [25-Feb-2003] 
// Powered by CodeProcessor
