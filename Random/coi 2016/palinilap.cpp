/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

#define rep(i, n)	for(long long i=0;i<n;i++)
#define repn(i, n)	for(long long i=1;i<=n;i++)
#define set(i, n)	memset(i, n, sizeof(i))

#define pb	push_back

using namespace std;

typedef pair<long long, long long> pii;

const long long N = 100005;
const long long BASE = 2327;
const long long MOD = 1770703937;

string str;
long long n, del[N], pre[N], fre[N], sum;
long long add[N][26];
long long H[N], B[N];
long long RH[N];

bool invalid(long long a, long long b){
	if(a >= 0 && b < n) return false;
	else return true;
}

long long get_hash(long long a, long long b){
	long long ret = (H[b+1] - (H[a] * B[b - a + 1])) % MOD;
	ret += MOD;
	ret %= MOD;
	return ret;
}

long long get_reverse_hash(long long a, long long b){
	a += 1, b += 1;
	long long ret = (RH[a] - (RH[b+1] * B[b - a + 1])) % MOD;
	ret += MOD;
	ret %= MOD;
	return ret;
}

long long get_interval(long long a, long long b){
	if(invalid(a, b)) return 0;
	long long lo = 0, hi = min(a, n-b-1), ret = 0;
	while(lo <= hi){
		long long mid = (lo + hi) / 2;
		if(get_hash(a-mid, a) == get_reverse_hash(b, b+mid)){
			ret = mid + 1;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	return ret;
}

void Add(long long a, long long b){
	fre[a] += 1;
	fre[b+1] -= 1;
	fre[b+1] -= b - a + 1;
	fre[b+2] += b - a + 1;
}

void Add_reverse(long long a, long long b){
	fre[a] += b - a + 1;
	fre[a+1] -= b - a + 1;
	fre[a+1] -= 1;
	fre[b+2] += 1;
}

void process(long long a, long long b){
    long long s = a, e = b;
    long long f = get_interval(a, b);
	sum += f;
	if(invalid(a, b)) return;
    if(f){
    	Add(a - f + 1, a);
    	Add_reverse(b, b + f - 1);
    }
	a -= f;
	b += f;
    if(invalid(a, b)) return;
	long long ad = 1 + get_interval(a-1, b+1);
	add[a][str[b]-'a'] += ad;
	add[b][str[a]-'a'] += ad;
}

void calc_hash(){
	long long cur = 0;
	for(long long i=0;i<n;i++){
		cur = (cur * BASE + str[i]) % MOD;
		H[i+1] = cur;
	}
	cur = 0;
	for(long long i=n-1;i>=0;i--){
		cur = (cur * BASE + str[i]) % MOD;
		RH[i+1] = cur;
	}
	B[0] = 1LL;
	for(long long i=1;i<N;i++) B[i] = (B[i-1] * BASE) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> str;
	n = str.size();
	calc_hash();
	rep(i, n){
		process(i-1, i+1);
		process(i-0, i+1);
	}
	long long ret = 0, taseem = 0, raza = 0;
    for(long long i=0;i<n;i++){
    	taseem += fre[i];
    	pre[i] = taseem;
    	raza += pre[i];
        del[i] = raza;
    }
	ret = max(ret, sum + n);
	rep(i, n){
		rep(j, 26){
			long long ans = sum + add[i][j] - del[i];
			ret = max(ret, n + ans);
		}
	}
	cout << ret << endl;
	return 0;
}
