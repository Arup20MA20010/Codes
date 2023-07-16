#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[1001001];
int prefix[1001001];
int suffix[1001001];
void solve(){
	int n;cin>>n;
	int m;cin>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		prefix[i]=arr[i]%m;
		suffix[i]=arr[i]%m;
		if(i)
			prefix[i]*=prefix[i-1];
		prefix[i]%=m;
	}
	for(int i=n-2;i>=0;i--){
		suffix[i]*=suffix[i+1];
		suffix[i]%=m;
	}
	for(int i=0;i<n;i++){
		int l=(i?prefix[i-1]:1);
		int r=(i<n-1?suffix[i+1]:1);
		int ans=l*r;
		ans%=m;
		cout<<ans<<" ";
	}
	cout<<nline;
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