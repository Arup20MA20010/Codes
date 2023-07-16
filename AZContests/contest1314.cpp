#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	pair<int,int>arr[100100];
	for(int i=0;i<n;i++){
		int s,e;cin>>s>>e;
		arr[i].first=e;
		arr[i].second=s;
	}
	sort(arr,arr+n);
	int cnt=0;
	int deadline=-1;
	for(int i=0;i<n;i++){
		if(arr[i].second>deadline){
			cnt++;
			deadline=arr[i].second+1;
		}
	}
	cout<<cnt<<nline;
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