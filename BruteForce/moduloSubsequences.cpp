#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<int>generate(vector<int>arr,int m){
	int n=arr.size();
	vector<int>ans;
	for(int mask=0;mask<(1<<n);mask++){
		int sum=0;
		for(int i=0;i<n;i++){
			if((mask>>i)&1){
				sum+=arr[i];
				sum%=m;
			}
		}
		ans.push_back(sum);
	}
	sort(ans.begin(),ans.end());
	return ans;
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>sub[2];
	for(int i=0;i<n;i++){
		int x;cin>>x;
		x%=m;
		sub[i&1].push_back(x);
	}
	vector<int>sub1=generate(sub[0],m);
	vector<int>sub2=generate(sub[1],m);
	int ans=0;
	for(auto v:sub1){
		auto it=lower_bound(sub2.begin(),sub2.end(),m-v);
		if(it!=sub2.begin()){
			it--;
			ans=max(ans,v+(*it));
		}
	}
	cout<<ans<<nline;
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