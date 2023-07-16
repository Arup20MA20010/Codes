#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	int ch1=sum/n;int ch2=(sum/n)+1;
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++){
		ans1+=(ch1-arr[i])*(ch1-arr[i]);
		ans2+=(ch2-arr[i])*(ch2-arr[i]);
	}
	cout<<min(ans1,ans2)<<nline;
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