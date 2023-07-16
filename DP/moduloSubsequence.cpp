/*
    "The greater the difficulty, the more the glory in surmounting it."
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
// *************************************************************************************************************************
const int MOD = 1e9 + 7;
// *************************************************************************************************************************
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int sub(int x, int y) {int res = x - y; return (res < 0 ? res + MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
int mod_inv(int x) {return power(x, MOD - 2);}
int lcm(int x, int y) {int res = x / __gcd(x, y); return (res * y);}
// *************************************************************************************************************************

int n, m;
int arr[100100];
int dp[100100];

int rec(int level){
    if(level==n)
        return 0;

    if(dp[level]!=-1)
        return dp[level];

    int ans=0;
    ans=max((arr[level]%m + rec(level+1)%m)%m, rec(level+1)%m);

    return dp[level]=ans;
}

void solve(){
    cin>>n>>m;

     for(int i=0; i<n; i++)
        cin>>arr[i]; 

    for(int i=0; i<=n; i++)
        dp[i]=-1;

    int maxValue=rec(0);
    maxValue%=m;
    if(maxValue<0)
        maxValue+=m;
    cout<<maxValue%m<<"\n"; 
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}