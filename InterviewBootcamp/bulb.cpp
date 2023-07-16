#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int x=0;
	int cnt=0;
	int ans=0;
	for(int i=0;i<n;i++){
		int pos;cin>>pos;
		cnt++;
		x=max(pos,x);
		if(x==cnt){
			ans++;
		}
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