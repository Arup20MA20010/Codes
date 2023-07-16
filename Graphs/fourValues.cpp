#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<60;i++){
        ans+=((n>>i)&1LL);
    }
    // cout<<ans<<nline;
    int oddCount=1LL<<ans;
    int evenCount=(n+1)-oddCount;
    cout<<evenCount<<" "<<oddCount<<nline;
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