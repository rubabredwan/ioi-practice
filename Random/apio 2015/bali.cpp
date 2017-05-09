/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int oo = 1e9;

int n, a, b, y[N];
int dp[N];

bool solve_big(long long fixed){
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = oo;
        long long sum = 0;
        for(int j=i;j>=1;j--){
            sum += y[j];
            if(sum & fixed) continue;
            dp[i] = min(dp[i], dp[j-1] + 1);
        }
    }
    if(dp[n] <= b) return true;
    else return false;
}

long long F, fn[105][105];

int recur(int at, int cnt){
    if(at == n+1){
        if(cnt >= a && cnt <= b) return 1;
        else return 0;
    }
    if(fn[at][cnt] != -1) return fn[at][cnt];
    int ret = 0;
    long long sum = 0;
    for(int i=at;i<=n;i++){
        sum += y[i];
        if(sum & F) continue;
        ret |= recur(i+1, cnt+1);
    }
    return fn[at][cnt] = ret;
}

bool solve_small(long long fixed){
    F = fixed;
    memset(fn, -1, sizeof(fn));
    if(recur(1, 0)) return true;
    else return false;
}

bool OK(long long fixed){
    if(n <= 100) return solve_small(fixed);
    else return solve_big(fixed);
}

int main(){
    scanf("%d %d %d", &n, &a, &b);
    for(int i=1;i<=n;i++) scanf("%d", &y[i]);
    long long ret = 0, fixed = 0;
    for(long long bit=45;bit>=0;bit--){
        if(OK(fixed | (1LL << bit))){
            fixed |= (1LL << bit);
        }
    	else{
            ret |= (1LL << bit);
        }
    }
    cout << ret << endl;
	return 0;
}
