/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>
#include "icc.h"

using namespace std;

const int N = 105;

int n, par[N], mat[N][N];
set<int>comp;
vector<int>nudes[N];

int Find(int at){
    return par[at] == at ? at : par[at] = Find(par[at]);
}

void Union(int a, int b){
    int x = Find(a);
    int y = Find(b);
    for(auto u : nudes[y]){
        nudes[x].push_back(u);
    }
    par[y] = x;
    comp.erase(y);
}

int bs[N], tt;

int get(int sa, int sb, int a[], int b[]){
    int lo = 0, hi = sb - 1;
    while(lo < hi){
        int mid = (lo + hi) / 2; tt = 0;
        for(int i=lo;i<=mid;i++) bs[tt] = b[i], ++tt;
        if(query(sa, tt, a, bs)) hi = mid;
        else lo = mid + 1;
    }
    return b[lo];
}

int aa[N], bb[N];
int sa, sb;

void run(int _n){
    srand(time(NULL));
    n = _n;
    comp.clear();
    for(int i=1;i<=n;i++){
        par[i] = i;
        comp.insert(i);
        nudes[i].push_back(i);
    }
    int road = n - 1;
    while(road--){
        for(int bit=7;bit>=0;bit--){
            sa = 0, sb = 0;
            for(auto u : comp){
                if(u & (1 << bit)) for(auto v : nudes[u]) aa[sa] = v, ++sa;
                else for(auto v : nudes[u]) bb[sb] = v, ++sb;
            }
            if(sa == 0 || sb == 0) continue;
            if(query(sa, sb, aa, bb)){
                int x = get(sa, sb, aa, bb);
                int y = get(sb, sa, bb, aa);
                Union(x, y);
                break;
            }
        }
    }
}