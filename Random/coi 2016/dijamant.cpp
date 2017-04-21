/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)

#define pb	push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;

int n;
map<string, int>mp;
int can[N][N];
int vis[N][N];
bitset<N>mat[N];

int main(){
	ios_base::sync_with_stdio(false);
	string str, node, par;
	cin >> n; getline(cin, str);
	repn(i, n){
		getline(cin, str);
		stringstream ss;
		ss << str;
		ss >> par;
		if(mp.count(par)){
			cout << "greska\n";
			continue;
		}
		vector<string>son;
		bool flag = true;
		while(ss >> node){
			if(node == ":") continue;
			if(node == ";") continue;
			son.pb(node);
			if(mp.count(node) == 0) flag = false;
		}
		if(flag == false){
			cout << "greska\n";
			continue;
		}
		vector<int>child;
		for(auto u : son) child.pb(mp[u]);
        for(auto u : child){
		    mat[i] |= mat[u];
		    mat[i].set(u);
        }
		flag = false;
		rep(a, child.size()){
			for(int b=a+1;b<child.size();b++){
				int u = child[a];
				int v = child[b];
				if(!vis[u][v]){
					vis[u][v] = 1;
					vis[v][u] = 1;
					if(mat[u].test(v) || mat[v].test(u)) continue;
					if((mat[u] & mat[v]).count()){
                        can[u][v] = 1, can[v][u] = 1;
                        flag = true;
                        break;
                    }
                }
				else{
					if(can[u][v] || can[v][u]){
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag == true){
			cout << "greska\n";
			continue;
		}
		cout << "ok\n";
		mp[par] = i;
	}
	return 0;
}
