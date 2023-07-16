#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int x,y;
	cin>>x>>y;
	if(x>=y){
		return x-y;
	}
	if(y%(x<<1)==0){
		cout<<y/(x<<1)<<nline;
	}else{
		int ans=((y/(x<<1)+1)*(x<<1)-y+(y/(x<<1)));
		cout<<ans<<nline;
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}