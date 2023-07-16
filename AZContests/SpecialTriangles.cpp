#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int h;cin>>h;
	int n=h*(h+1)/2;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bool Ok=1;
	for(int i=0;i<n;i++){
		if(2*i<n&&arr[i]>=arr[2*i]||2*i+1<n&&arr[i]>=arr[2*i+1]){
			Ok=0;
			break;
		}
	}
	if(Ok)
		cout<<"YES"<<nline;
	else
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