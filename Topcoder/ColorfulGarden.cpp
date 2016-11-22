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
typedef pair<int, char>pii;

struct ColorfulGarden{
	vector <string> rearrange(vector <string> garden){
		int n = garden[0].size();
		map<char, int>mp;
		rep(i, n) mp[ garden[0][i] ]++, mp[ garden[1][i] ]++;
		vector<pii>vec;
		for(auto u : mp) vec.pb(pii(u.second, u.first));
    	vector <string> ret;

		for(auto u : mp) if(u.second > n) return ret;
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());

		ret = garden;

		int cur = 0;

		rep(i, n){
			while(vec[cur].first == 0) cur++;
			vec[cur].first--;
			ret[i % 2][i] = vec[cur].second;	
		}
		rep(i, n){
			while(vec[cur].first == 0) cur++;
			vec[cur].first--;
			ret[1 - (i % 2)][i] = vec[cur].second;
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"aa",
 "bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ba", "ab" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, rearrange(Arg0)); }
	void test_case_1() { string Arr0[] = {"xxxx",
 "xxxx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, rearrange(Arg0)); }
	void test_case_2() { string Arr0[] = {"abcd",
 "abcd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcd", "dcba" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, rearrange(Arg0)); }
	void test_case_3() { string Arr0[] = {"abcdefghijklm",
 "nopqrstuvwxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcdefghijklm", "nopqrstuvwxyz" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, rearrange(Arg0)); }
	void test_case_4() { string Arr0[] = {"aaa",
 "aab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, rearrange(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	ColorfulGarden ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
