#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int arr[n];
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i&&arr[i-1]>=arr[i])ans+=(arr[i-1]-arr[i]);
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