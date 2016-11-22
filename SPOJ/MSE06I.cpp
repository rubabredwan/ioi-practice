/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		1000007
#define pb		push_back
#define inf 	(1 << 30)

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

typedef long long int64;

const int
	MAXN = 502,
	MAXE = 100000,
	oo = (int)1e9;

int T, V, L, E;
int src, snk, sol;
int cant[MAXN];
int best[MAXN];
int from[MAXN];
int head[MAXN];
struct edge {
	int u, v, w, cap, next;
} edges[MAXE];

void add_edge( int u, int v, int w, int cap ) {
	edges[E++] = (edge){ u, v, +w, cap, head[u] };
	head[u] = E - 1;
	edges[E++] = (edge){ v, u, -w, 0, head[v] };
	head[v] = E - 1;
}

bool augment( int src, int snk ) {

	fill( best, best + V + 2, oo );
	best[src] = 0;
	
     	queue< int > Q;
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
		      if ( edges[e].cap && best[u] + edges[e].w < best[v] ) {
				Q.push( v );
				best[v] = best[u] + edges[e].w;
				from[v] = e;
			}
		}
	}
	
	if ( best[snk] == oo )
	      return false;
	      
	sol += best[snk];
	for ( int x = snk; x != src; x = edges[ from[x] ].u ) {
		edges[ from[x] ].cap--;
		edges[ from[x]^1 ].cap++;
	}
	      
	return true;
}


int main() {
	int x, y, c, m;
	int cas = 1;
	while(scanf("%d %d", &V, &m) == 2){
		if(V == 0 && m == 0) break;
		memset( head, -1, sizeof( head ) );
		memset( cant, 0, sizeof( cant ) );
		src = 0;
		snk = V-1;
		E = 0;
		rep(i, m){
			scanf("%d %d %d", &x, &y, &c);
			add_edge(x, y, c, 1);
		}
		sol = 0;
		bool flag = true;	
		rep(i, 2){
			if(augment(src, snk) == false){
				flag = false;
				break;
			}
		}
		if(flag == false) printf("Instance #%d:  Not possible\n", cas++);
		else printf("Instance #%d:  %d\n", cas++, sol);
	}
	return 0;
}

