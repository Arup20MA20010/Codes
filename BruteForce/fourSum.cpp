#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int arr[n];
	int target;cin>>target;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	set<int>st;
	st.insert(arr[n-1]+arr[n-2]);
	for(int partition=n-3;partition>=1;partition--){
		for(int i=0;i<partition;i++){
			if(st.find(target-(arr[i]+arr[partition]))!=st.end()){
				cout<<"YES"<<nline;
				return;
			}
		}
		for(int i=partition+1;i<n;i++){
			st.insert(arr[partition]+arr[i]);
		}
	}
	cout<<"NO"<<nline;
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