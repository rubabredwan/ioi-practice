/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

const int N = 30005;
const int M = 200;
const int oo = 1e9;

struct data{
    int cost, pos, b;
    bool operator < (const data &p) const{
        return cost > p.cost;
    }
    data () {}
    data (int _cost, int _pos, int _b){
        cost = _cost;
        pos = _pos;
        b = _b;
    }
};

int dis[N][M+10];
int n, m, B[N], P[N];
vector<int>ps[N];
priority_queue<data>q;

void propagate(int pos, int sz, int pst){
    int ds = pst;
    for(int i=pos;i>=0;i-=sz){
        if(dis[i][0] > ds){
            dis[i][0] = ds;
            q.push(data(ds, i, 0));
        }
        ++ds;
    }
    ds = pst;
    for(int i=pos;i<n;i+=sz){
        if(dis[i][0] > ds){
            dis[i][0] = ds;
            q.push(data(ds, i, 0));
        }
        ++ds;
    }
}

int solve(){
    for(int i=0;i<N;i++) for(int j=0;j<=M;j++) dis[i][j] = oo;
    if(B[1] <= M){
        dis[P[1]][B[1]] = 0;
        q.push(data(0, P[1], B[1]));
    }
    else propagate(P[1], B[1], 0);
    while(!q.empty()){
        data u = q.top(); q.pop();
        int pos = u.pos, sz = u.b;
        for(auto u : ps[pos]){
            if(B[u] <= M){
                if(dis[pos][B[u]] > dis[pos][sz]){
                    dis[pos][B[u]] = dis[pos][sz];
                    q.push(data(dis[pos][sz], pos, B[u]));
                }
            }
            else propagate(pos, B[u], dis[pos][sz]);
        }
        ps[pos].clear();
        if(pos - sz >= 0 && dis[pos-sz][sz] > dis[pos][sz] + 1){
            dis[pos-sz][sz] = dis[pos][sz] + 1;
            q.push(data(dis[pos-sz][sz], pos-sz, sz));
        }
        if(pos + sz <  n && dis[pos+sz][sz] > dis[pos][sz] + 1){
            dis[pos+sz][sz] = dis[pos][sz] + 1;
            q.push(data(dis[pos+sz][sz], pos+sz, sz));
        }
    }
    int ret = oo;
    for(int i=0;i<=M;i++) ret = min(ret, dis[P[2]][i]);
    return ret == oo ? -1 : ret;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++) scanf("%d %d", &P[i], &B[i]);
    for(int i=1;i<=m;i++) ps[P[i]].push_back(i);
    int ret = solve();
    printf("%d\n", ret);
	return 0;
}
