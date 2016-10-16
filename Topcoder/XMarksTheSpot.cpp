#include <bits/stdc++.h>
 
#define rep(i, n)  for(int i=0;i<n;i++)
#define repn(i, n)  for(int i=1;i<=n;i++)
#define set(i, n)  memset(i, n, sizeof(i))
 
#define mx      55
#define inf      1e5
#define pb      push_back
 
#define PI      acos(-1)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
struct XMarksTheSpot{
  int n, m;
  int row[mx], col[mx];
  int countArea(vector <string> board){
    n = board.size();
    m = board[0].size();
    reverse(board.begin(), board.begin()); board.push_back("fuck u");
    reverse(board.begin(), board.end());
    repn(i, n) board[i] = "#" + board[i];
    vector<pii>vec;
    repn(i, n){
      repn(j, m){
        row[i] += board[i][j] == 'O';
        col[j] += board[i][j] == 'O';
        if(board[i][j] == '?'){
          vec.pb(pii(i, j));
        }
      }
    }
    ll ret = 0;
    for(int mask = 0;mask < (1 << vec.size());mask++){
      rep(i, vec.size()){
        if(mask & (1 << i)){
          row[vec[i].first]++;
          col[vec[i].second]++;
        }
      }
      int f = inf, u = -inf;
      int c = inf, k = -inf;
      repn(i, n) if(row[i]) f = min(f, i), u = max(u, i);
      repn(i, m) if(col[i]) c = min(c, i), k = max(k, i);
      ret += ll(k - c + 1) * ll(u - f + 1);
      //cout << f << ' ' << u << ' ' << c << ' ' << k << endl;
      rep(i, vec.size()){
        if(mask & (1 << i)){
          row[vec[i].first]--;
          col[vec[i].second]--;
        }
      }
    }  
    return ret;
  }
 
 
 
};
