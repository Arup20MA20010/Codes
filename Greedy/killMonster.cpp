#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
bool compare(ii a,ii b){
	if(a.ss-a.ff==b.ss-b.ff){
		return a.ss<=b.ss;
	}
	return a.ss-a.ff>b.ss-b.ff;
}
void solve(){
	int n;cin>>n;
	vector<ii>arr;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		arr.push_back({b,a});
	}
	sort(arr.begin(),arr.end(),compare);
	// for(auto x:arr){
	// 	cout<<x.ss<<" "<<x.ff<<nline;
	// }
	int maxAns=0;
	int Bsum=0;
	for(auto v:arr){
		maxAns=max(maxAns,Bsum+v.ss);
		Bsum+=v.ff;
	}
	cout<<max(maxAns,Bsum)<<nline;
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