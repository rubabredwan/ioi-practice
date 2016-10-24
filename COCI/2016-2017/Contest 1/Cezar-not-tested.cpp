/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		107
#define pb		push_back
#define inf 	(1 << 30)

#define f	first
#define s 	second

using namespace std;

typedef long long ll;
typedef pair<int, string> pii;

int n, perm[mx];
string str[mx];
vector<pii>vec;
string ret = "";
int deg[mx], mat[mx][mx];
int inQ[mx];

void solve(){
	sort(vec.begin(), vec.end());
	for(int i=1;i<vec.size();i++){
		string a = vec[i-1].s;
		string b = vec[i].s;
		int sz = min(a.size(), b.size());
		for(int j=0;j<sz;j++){
			if(a[j] == b[j]) continue;
			int x = a[j] - 'a';
			int y = b[j] - 'a';
			mat[x][y] = 1;
			deg[y]++;
			break;
		}
	}

	queue<int>q;
	
	rep(i, 26){
		if(deg[i] == 0){
			q.push(i); 
			inQ[i] = 1;
		}
	}
	int cnt = 0;
	ret.resize(26);
	int cur = 'a';
	while(!q.empty()){
		int u = q.front(); q.pop();
		char c = u + 'a';
		ret[u] = cur;
		cur++;
		cnt++;
		rep(i, 26){
			if(mat[u][i]){
				mat[u][i] = 0;
				deg[i]--;
			}
		}
		rep(i, 26){
			if(deg[i] == 0 && !inQ[i]){
				q.push(i);
				inQ[i] = 1;
			}
		}
	}

	if(cnt < 26) cout << "NE\n";
	else{
		cout << "DA\n";
		cout << ret << '\n';
	}
}

int main(){
	cin >> n;
	repn(i, n){
		cin >> str[i];
	}
	repn(i, n) scanf("%d", &perm[i]);
	repn(i, n) vec.pb(pii(i, str[perm[i]]));
	solve();
	return 0;
}

