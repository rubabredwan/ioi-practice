/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define read(x)		freopen(x, "r", stdin)
#define write(x) 	freopen(x, "w", stdout)

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx			205
#define pb			push_back

#define inf			(1 << 29)	
#define	eps			1e-6
#define pi 			acos(-1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
string str[mx];
int mat[mx][mx];

int sum(int a, int b, int c, int d){
	return mat[c][d] - mat[c][b-1] - mat[a-1][d] + mat[a-1][b-1];
}

int solve(int r1, int r2){
	vector<int>vec;
	repn(i, m){
		if(sum(r1, i, r2, i) == 0) vec.pb(i);
	}
	int p1 = 0, p2 = 0;
	int ret = 0;
	while(p2 < vec.size()){
		int f = vec[p1];
		while((sum(r1, vec[p1], r1, vec[p2]) || sum(r2, vec[p1], r2, vec[p2]))) p1++;
		ret = max(ret, (r2 - r1 + 1) * (vec[p2] - vec[p1] + 1));
		p2++;
	}
	return ret;
}

int main(){
	read("fortmoo.in");
	write("fortmoo.out");
	cin >> n >> m;
	repn(i, n){ cin >> str[i]; str[i] = "#" + str[i]; }
	repn(i, n){
		repn(j, m){
			mat[i][j] = str[i][j] == 'X';
			mat[i][j] += mat[i-1][j];
			mat[i][j] += mat[i][j-1];
			mat[i][j] -= mat[i-1][j-1];
		}
	}
	int ret = 0;
	repn(i, n){
		for(int j=i+1;j<=n;j++){
			ret = max(ret, solve(i, j));
		}
	}
	cout << ret << endl;
	return 0;
}

