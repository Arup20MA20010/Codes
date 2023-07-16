//min of manhattan distance is at mean and that of the squared distance is mean
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int x[n],y[n];
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	sort(x,x+n);
	sort(y,y+n);
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=(abs(x[n/2]-x[i])+abs(x[n/2]-y[i]));
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
	solve();
	return 0;
}