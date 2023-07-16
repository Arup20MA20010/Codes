#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,k;cin>>n>>k;
	//prefix[i]-prefix[i-1]=arr[i];
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=n-1;i>0;i--){
		arr[i]-=arr[i-1];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<nline;
	int i=1,j=0;
	while(i<n){
		int sum=0;
		if(arr[i]<=0){
			i++;
			continue;
		}
		j=i;
		while(j<n&&arr[j]>0){
			sum+=arr[j];
			j++;
		}
		if(sum>k){
			ans+=(sum-k);
		}
		i=j+1;
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