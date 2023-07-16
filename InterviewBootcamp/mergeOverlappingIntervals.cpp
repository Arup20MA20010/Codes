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
		int s,e;cin>>s>>e;
		arr[i]={s,e};
	}
	sort(arr,arr+n);
	int start=arr[0].ff;int end=arr[0].ss;
	vector<ii>ans;
	for(int i=1;i<n;i++){
		if(end<arr[i].ff){
			ans.push_back({start,end});
			start=arr[i].ff;
			end=arr[i].ss;
		}else{
			end=max(arr[i].ss,end);
		}
	}
	ans.push_back({start,end});
	for(auto v:ans){
		cout<<v.ff<<" "<<v.ss<<nline;
	}
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