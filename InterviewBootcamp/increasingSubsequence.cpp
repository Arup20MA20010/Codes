#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
const int mod=998244353;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    int maxLimit=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxLimit=max(maxLimit,a[i]);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        maxLimit=max(maxLimit,b[i]);
    }
    vector<vector<int>>dp(n+1,vector<int>(maxLimit+1,0));
    for(int l=min(a[0],b[0]);l<=max(a[0],b[0]);l++){
        dp[0][l]=1;
    }
    for(int i=1;i<n;i++){
        for(int l=min(a[i],b[i]);l<=max(a[i],b[i]);l++){
            for(int p=min(a[i-1],b[i-1]);p<=min(l-1,max(a[i-1],b[i-1]));p++){
                dp[i][l]+=dp[i-1][p];
                dp[i][l]%=mod;
            }
        }
    }
    int ans=0;
    for(int l=min(a[n-1],b[n-1]);l<=max(a[n-1],b[n-1]);l++){
        ans+=dp[n-1][l];
        ans%=mod;
    }
    cout<<ans<<nline;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}