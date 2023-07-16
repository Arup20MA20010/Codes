#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,a,b;cin>>n>>a>>b;
	int arr[n+1];
	for(int i=0;i<=n;i++){
		arr[i]=i*a/b;
	}
	for(int i=1;i<=n;i++){
		for(int j=2*i;j<=n;j+=i){
			arr[j]-=arr[i];
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans+=arr[i];
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
	while(T--)solve();
	return 0;
}