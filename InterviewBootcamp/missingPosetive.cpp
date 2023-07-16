#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int arr[100100];
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		if(arr[i]>0&&arr[i]<=n&&arr[i]!=i+1&&arr[arr[i]-1]!=arr[i]){
			swap(arr[i],arr[arr[i]-1]);
			i--;
		}
	}
	int ans=n+1;
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<nline;
	for(int i=0;i<n;i++){
		if(arr[i]!=i+1){
			ans=i+1;
			break;
		}
	}
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}