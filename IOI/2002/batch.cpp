/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int oo = 1e9;

vector<long long>M, B;

bool bad(int a, int b, int c){
	return (B[a] - B[b]) * (M[c] - M[a]) < (B[a] - B[c]) * (M[b] - M[a]);
}

long long n, S, T[N], F[N];
long long sum[N], cst[N];
int ptr;

void add(long long m, long long b){
	M.push_back(m);
	B.push_back(b);
	while(M.size() >= 3 && bad(M.size()-3, M.size()-2, M.size()-1)){
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
}

long long query(long long x){
	if(ptr >= M.size()) ptr = M.size() - 1;
	while(ptr + 1 < M.size() && M[ptr+1] * x + B[ptr+1] < M[ptr] * x + B[ptr]){
		++ptr;
	}
	return M[ptr] * x + B[ptr];
}

int main(){
	scanf("%lld %lld", &n, &S);
	for(int i=1;i<=n;i++) scanf("%lld %lld", &T[i], &F[i]);
	for(int i=n;i>=1;i--) sum[i] = sum[i+1] + T[i], cst[i] = cst[i+1] + F[i];
	add(0, 0);
	long long ret = 0;
	for(int i=n;i>=1;i--){
		ret = query(-cst[i]) + (S + sum[i]) * cst[i];
		add( sum[i], ret );
	}
	cout << ret << endl;
	return 0;
}
