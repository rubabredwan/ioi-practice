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

struct SquareFreeString{

	bool ok(string s){
		if(s.size() % 2) return false;
		int n = s.size();
		n /= 2;
		for(int i=0, j=n;j<s.size();i++, j++){
			if(s[i] != s[j]) return false;
		}
		return true;
	}

	string isSquareFree(string s){
    	string ret;
		int n = s.size();
		for(int i=0;i<n;i++){
			string str = "";
			for(int j=i;j<n;j++){
				str += s[j];
				if(ok(str)) return "not square-free";
			}
		}
		return "square-free";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "bobo"; string Arg1 = "not square-free"; verify_case(0, Arg1, isSquareFree(Arg0)); }
	void test_case_1() { string Arg0 = "apple"; string Arg1 = "not square-free"; verify_case(1, Arg1, isSquareFree(Arg0)); }
	void test_case_2() { string Arg0 = "pen"; string Arg1 = "square-free"; verify_case(2, Arg1, isSquareFree(Arg0)); }
	void test_case_3() { string Arg0 = "aydyamrbnauhftmphyrooyq"; string Arg1 = "not square-free"; verify_case(3, Arg1, isSquareFree(Arg0)); }
	void test_case_4() { string Arg0 = "qwertyuiopasdfghjklzxcvbnm"; string Arg1 = "square-free"; verify_case(4, Arg1, isSquareFree(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	SquareFreeString ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
