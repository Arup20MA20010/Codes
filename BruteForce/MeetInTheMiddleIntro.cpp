//find the no. of subsets whose sum is <=X for some given X.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<int> generate(vector<int>subset){
	int n=subset.size();
	vector<int>ans;
	for(int mask=0;mask<(1<<n);mask++){
		int x=0;
		for(int j=0;j<n;j++){
			if((mask>>j)&1){
				x+=subset[j];
			}
		}
		ans.push_back(x);
	}
	sort(ans.begin(),ans.end());
	return ans;
}
void solve(){
	int ans=0;
	vector<int>sub[2];
	int n;cin>>n;
	int k;cin>>k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sub[i&1].push_back(x);
	}
	vector<int>sub1=generate(sub[0]);
	vector<int>sub2=generate(sub[1]);
	for(auto v:sub1){
		ans+=(upper_bound(sub2.begin(),sub2.end(),k-v)-sub2.begin());
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
	int T;cin>>T;
	while(T--){
		solve();
	}

	return 0;
}