#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;int target;cin>>target;
	int arr[n];
	int firstOcc=-1;
	int lastOcc=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==target){
			lastOcc=i;
			if(firstOcc==-1){
				firstOcc=i;
			}
		}
	}
	if(firstOcc==-1){
		cout<<-1<<nline;
		return;
	}
	cout<<firstOcc+1<<" "<<lastOcc+1<<nline;
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