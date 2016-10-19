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

int fx[] = {-1, -1, +1, +1, -2, -2, +2, +2};
int fy[] = {-2, +2, -2, +2, -1, +1, -1, +1};

struct ChessKnight{
	double probability(int x, int y, int n){
    	double ret = 0;
    	double pro[105][10][10];
    	pro[0][x][y] = 1;
    	for(int level=0;level<n;level++){
    		repn(i, 8){
    			repn(j, 8){
    				rep(f, 8){
    					int xx = i + fx[f], yy = j + fy[f];
    					if(xx >= 1 && yy >= 1 && xx <= 8 && yy <= 8){
    						pro[level+1][xx][yy] += pro[level][i][j] / 8.0;
    					}
    				}
    			}
    		}
    	}
/*    	rep(f, n+1){

    		cout << "level -> " << f << endl;


    		repn(i, 8){
    			repn(j, 8){

    				printf("%.4lf ", pro[f][i][j]);
    			}
    			cout << endl;
    		}

    		cout << "--------------------------------\n";
    	}*/
    	repn(i, 8) repn(j, 8) ret += pro[n][i][j];
    	return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.1875; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; double Arg3 = 1.0; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; double Arg3 = 0.0522148497402668; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 50; double Arg3 = 8.356427906809618E-7; verify_case(3, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	ChessKnight ___test;
	___test.run_test(0);
	return 0;
}
// END CUT HERE
