#include <bits/stdc++.h>
 
#define rep(i, n)  for(int i=0;i<n;i++)
#define repn(i, n)  for(int i=1;i<=n;i++)
#define set(i, n)  memset(i, n, sizeof(i))
 
#define mx      100005
#define inf      1e12
#define pb      push_back
 
#define PI      acos(-1)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
struct Xylophone{
  int countKeys(vector <int> keys){
      int ret;
      set<int>st;
      for(auto f: keys) st.insert(f % 7);
      return st.size();
  }
 
 
 
};
