#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
void solve(){
	int n;cin>>n;
	ii arr[n];
	for(int i=0;i<n;i++){
		int st,et;cin>>st>>et;
		arr[i]={et,st};
	}
	sort(arr,arr+n);
	int count=0;
	int endTime=-1;
	for(int i=0;i<n;i++){
		if(arr[i].ss>endTime){
			count++;
			endTime=arr[i].ff;
		}
	}
	cout<<count<<nline;
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