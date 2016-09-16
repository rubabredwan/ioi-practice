/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(int i=0;i<n;i++)
#define repn(i, n)	for(int i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define mx		5005
#define inf		1e9

using namespace std;

typedef pair<int, int> pii;

int n, q;
int a[mx], dis[mx*10];

void init(){
	priority_queue<pii>q;
	rep(i, a[0]) dis[i] = inf;
	dis[0] = 0;
	q.push(pii(0, 0));
	while(!q.empty()){
		pii f = q.top();
		q.pop();
		int x = f.first, y = f.second;
		repn(i, n-1){
			if(dis[ (y + a[i]) % a[0] ] > x + a[i]){
				dis[ (y + a[i]) % a[0] ] = x + a[i];
				q.push( pii(dis[ (y + a[i]) % a[0] ], (y + a[i]) % a[0]  ) );
			}
		}
	}
}

int main(){
	int x;
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	init();
	scanf("%d", &q);
	while(q--){
		scanf("%d", &x);
		if(dis[x % a[0]] <= x) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
