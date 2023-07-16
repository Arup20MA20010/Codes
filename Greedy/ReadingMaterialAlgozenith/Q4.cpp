#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;int arr[n];
	int negCount=0;
	int minVal=1e9;
	int maxNeg=-1e9;
	int prod=1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]<0){
			negCount++;
			maxNeg=max(maxNeg,arr[i]);
		}
		minVal=min(arr[i],minVal);
		if(arr[i])prod*=arr[i];
	}
	if(negCount&1){
		cout<<prod<<nline;
		return;
	}else{
		cout<<prod/maxNeg<<nline;
		return;
	}
	cout<<minVal<<nline;
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