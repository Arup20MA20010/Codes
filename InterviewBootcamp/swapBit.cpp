#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int i=0;
	int ans=0;
	while(n){
		int x=n&3;
		n>>=2;
		int y=0;
		if(x==1){
			x=2;
		}else if(x==2){
			x=1;
		}
		ans+=(x<<i);
		i+=2;
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