/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			100005
#define inf			1e9
#define pb			push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct BigFibonacci{
	int fibNumber(string index, int M){
    	int ret;
    	return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "7"; int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "5"; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0"; int Arg1 = 23; int Arg2 = 0; verify_case(2, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "17"; int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "54"; int Arg1 = 341890; int Arg2 = 177022; verify_case(4, Arg2, fibNumber(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "300"; int Arg1 = 77531; int Arg2 = 0; verify_case(5, Arg2, fibNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	BigFibonacci ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
