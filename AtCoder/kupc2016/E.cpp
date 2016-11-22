/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		1007
#define pb		push_back
#define oo		1e9

#define f	first
#define s 	second

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

int n, m;
string grid[mx];
int fx[] = {0, 0, +1, -1};
int fy[] = {+1, -1, 0, 0};

int in(int x, int y){
	return m * x + y;
}

int out(int x, int y){
	return m * x + y + n * m;
}

bool valid(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) cin >> grid[i];
	Dinic flow(n*m*2 + 3);
	rep(i, n){
		rep(j, m){
			if(grid[i][j] == 'X') flow.AddEdge(in(i, j), out(i, j), oo);
			else flow.AddEdge(in(i, j), out(i, j), 1);
		}
	}
	rep(i, n){
		rep(j, m){
			rep(f, 4){
				int x = i + fx[f], y = j + fy[f];
				if(valid(x, y)) flow.AddEdge(out(i, j), in(x, y), oo);
			}
		}
	}
	int source = n * m * 2 + 1, sink = source + 1;
	rep(i, m){
		flow.AddEdge(source, in(0, i), oo);
		flow.AddEdge(source, in(n-1, i), oo);
	}
	for(int i=2;i<n-1;i++){
		flow.AddEdge(source, in(i, 0), oo);
		flow.AddEdge(source, in(i, m-1), oo);
	}
	rep(i, n){
		rep(j, m){
			if(grid[i][j] == 'X'){
				flow.AddEdge(out(i, j), sink, oo);
				if(i==0||i==n-1||j==0||j==m-1){
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	cout << flow.MaxFlow(source, sink) << endl;
	return 0;
}
