/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			305
#define inf			1e9
#define pb			push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct FriendlyRobot{
	int dp[mx][mx];
	int findMaximumReturns(string instructions, int changesAllowed){
		set(dp, 0);
		int n = instructions.size();
		int m = changesAllowed;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<=m;j++){
				int x = 0, y = 0;
				for(int k=i;k<n;k++){
					if(instructions[k] == 'U') x--;
					if(instructions[k] == 'D') x++;
					if(instructions[k] == 'R') y++;
					if(instructions[k] == 'L') y--;
					if((abs(x) + abs(y)) % 2 == 0){
						int need = (abs(x) + abs(y)) / 2;
						if(need <= j){
							dp[i][j] = max(dp[i][j], 1 + dp[k+1][j-need]);
						}
					}
				}
			}
		}
		return dp[0][m];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "UULRRLLL"; int Arg1 = 1; int Arg2 = 3; verify_case(0, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ULDR"; int Arg1 = 0; int Arg2 = 1; verify_case(1, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ULDR"; int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ULDRRLRUDUDLURLUDRUDL"; int Arg1 = 4; int Arg2 = 8; verify_case(3, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLDRURDRDUDDDDRLLRUUDURURDRRDRULRDLLDDDDRLRRLLRRDDLRURLRULLLLLRRRDULRULULRLRDLLDDLLRDLUUDUURRULUDUDURULULLDRUDUUURRRURUULRLDLRRRDLLDLRDUULUURUDRURRLURLDLDDUUURRURRLRDLDDULLUDLUDULRDLDUURLUUUURRLRURRDLRRLLLRDRDUUUDRRRDLDRRUUDUDDUDDRLUDDULRURRDRUDLDLLLDLUDDRLURLDUDRUDDDDURLUUUDRLURDDDDLDDRDLUDDLDLURR"; int Arg1 = 47; int Arg2 = 94; verify_case(4, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"; int Arg1 = 300; int Arg2 = 150; verify_case(5, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "UD"; int Arg1 = 1; int Arg2 = 1; verify_case(6, Arg2, findMaximumReturns(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	FriendlyRobot ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
