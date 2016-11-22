/* Bismillahir Rahmanir Rahim */
 
#include <bits/stdc++.h>
 
#define rep(i, n)  for(int i=0;i<n;i++)
#define repn(i, n)  for(int i=1;i<=n;i++)
#define set(i, n)  memset(i, n, sizeof(i))
 
#define mx      105
#define inf      1e9
#define pb      push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
struct GridSortMax{
  string findMax(int n, int m, vector <int> grid){
      string ret = "";
    int done[mx];
    int fuck[mx];
    set(done, 0);
    set(fuck, 0);
    rep(i, n){
      bool fixed = false;
      rep(j, m){
        int need = (i * m) + j + 1;
        int pre = done[j];
        if(!fixed){
          bool found = false;
          int x, y;
          for(int a=0;a<n;a++){
            if(fuck[a]) continue;
            for(int b=0;b<m;b++){
              int vl = grid[ a * m + b ];
              if(vl == need){
                found = true;
                x = a;
                y = b;
              }
            }
          }
          if(found == false || (done[j] && y != j) || (done[y] && y != j) ) ret += "0";
          else{
            int s = x * m;
            int ss = i * m;
            done[j] = 1;
            pre |= y == j;
            for(int f=s, c=0, u=ss;c<m;c++, f++, u++) swap(grid[f], grid[u]);
            rep(f, n){
              int aa = f * m + j;
              int bb = f * m + y;
              swap(grid[aa], grid[bb]);
            }
            ret += "1";
            fixed = 1;
          }
        }
        else{
          bool found = false;
          int a = i, x, y;
          for(int b=0;b<m;b++){
            int vl = grid[ a * m + b ];
            if(vl == need){
              found = true;
              x = a;
              y = b;
            }
          }
          if(found == false || (done[j] && y != j) || (done[y] && y != j) ) ret += "0";
          else{
            int s = x * m;
            int ss = i * m;
            done[j] = 1;
            pre |= y == j;
            for(int f=s, c=0, u=ss;c<m;c++, f++, u++) swap(grid[f], grid[u]);
            rep(f, n){
              int aa = f * m + j;
              int bb = f * m + y;
              swap(grid[aa], grid[bb]);
            }
            ret += "1";
            fixed = 1;
          }
        }
      }
      fuck[i] = fixed;
    }
      return ret;
  }
  
 
};
 
 
 
// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
