#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
    int hh,mm;cin>>hh>>mm;
    int ans=abs(60*hh-11*mm);
    if(ans>360*1LL){
        ans=720*1LL-ans;
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