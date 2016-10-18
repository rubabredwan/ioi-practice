/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			10005
#define inf			1e9
#define pb			push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct NestedRandomness{
	double probability(int N, int nestings, int target){
    	double A[mx];
    	rep(i, N) A[i] = double(1) / double(N);
    	for(int level = 2;level <= nestings; level++){
    		rep(i, N){
    			A[i] = 0;
    			double sum = 0.0;
    			for(int j=i+1;j<N;j++){
    				sum += A[j] * (1.0 / double(j));
    			}
    			A[i] = sum;
    		}
    	}
    	return A[target];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.21666666666666667; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 0; double Arg3 = 0.19942680776014104; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 10; int Arg2 = 990; double Arg3 = 1.0461776397050886E-30; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	NestedRandomness ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
