/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define REP(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb			push_back

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


struct BiconnectedDiv1{
	int minimize(vector <int> w1, vector <int> w2){
		E = 0;
		memset( head, -1, sizeof( head ) );
		memset( cant, 0, sizeof( cant ) );
		V = w1.size() + 3;
		int tot = 0;
		for(int i=0;i<w1.size();i++){
			add_edge(i, i+1, w1[i], 1);
			tot += w1[i];
		}
		for(int i=0;i<w2.size();i++){
			add_edge(i, i+2, w2[i], 1);
			tot += w2[i];
		}

		src = V;
		snk = V + 1;

		add_edge(src, 0, 0, 2);
		add_edge(w1.size(), snk, 0, 2);

		sol = 0;

		REP(i, 2) augment(src, snk);
	
		return sol;

	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minimize(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,0,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, minimize(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,6,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(2, Arg2, minimize(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46729; verify_case(3, Arg2, minimize(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	BiconnectedDiv1 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
