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

struct BearPasswordLexic{
	int n;
	string findPassword(vector<int>x){
		n = x.size();
		string ret = "";
		int p = 1;
		vector<int>aa, bb;
		vector<int>vec;
		while(1){
			bool flag = false;
			for(int i=n-1;i>=0;i--){
				if(x[i] > 0){
					flag = true;
					int cur = 1;
					vec.pb(i+1);
					for(int j=i;j>=0;j--){
						x[j] -= cur;
						cur += 1;
					}
					break;
				}
			}
			if(flag == false) break;
			p ^= 1;
		}
		for(auto u : x) if(u != 0) return "";

		sort(vec.begin(), vec.end());

		int fk = vec.size() / 2;

		for(int i=0;i<fk;i++) bb.pb(vec[i]);
		for(int i=fk;i<vec.size();i++) aa.pb(vec[i]);

		sort(aa.begin(), aa.end());
		reverse(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());
		if((aa.size() - bb.size()) > 1) return "";
		int sum = 0;
		for(auto u : aa) sum += u;
		for(auto u : bb) sum += u;
		if(sum != x.size()) return "";

		for(int i=0;i<aa.size()+bb.size();i++){
			if(i % 2 == 0){
				rep(j, aa[i/2]) ret += "a";
			}
			else{
				rep(j, bb[i/2]) ret += "b";
			}
		}

    	return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ababa"; verify_case(0, Arg1, findPassword(Arg0)); }
	void test_case_1() { int Arr0[] = {4,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaab"; verify_case(1, Arg1, findPassword(Arg0)); }
	void test_case_2() { int Arr0[] = {3,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, findPassword(Arg0)); }
	void test_case_3() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaa"; verify_case(3, Arg1, findPassword(Arg0)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(4, Arg1, findPassword(Arg0)); }
	void test_case_5() { int Arr0[] = {4,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(5, Arg1, findPassword(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	BearPasswordLexic ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
