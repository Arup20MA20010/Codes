#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int arr[n];
	map<int,int>mp;
	int k;cin>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]=i;
	}
	for(int i=0;i<n;i++){
		if(k==2*arr[i])continue;
		if(mp.find(k-arr[i])!=mp.end()){
			cout<<i<<" "<<mp[k-arr[i]];
			break;
		}
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