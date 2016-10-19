/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			10005
#define inf			1e9
#define pb			push_back
#define mod			1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct XYZCoder{
	ll dp[mx], vp[mx];
	int countWays(int room, int size){
    	dp[0] = 1;
    	for(int i=1;i<=room*size;i++){
    		for(int j=0;j<=room*size;j++){
    			ll sum = 0;
    			if(j) sum += dp[j-1];
    			if(j + size - 1 <= room * size) sum += dp[j+size-1];
    			sum %= mod;
    			vp[j] = sum;
    		}
    		for(int j=0;j<=room*size;j++) dp[j] = vp[j];
    	}
    	ll ret = dp[0];
    	repn(i, room) ret = (ret * i) % mod;
    	return int(ret);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 6840; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 718243627; verify_case(4, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	XYZCoder ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
