/*
We are given certain ranges and k. Need to find the total length of segments that have more than k segments covering them.
Idea:
We classify the segments (l,r) as (l,0) and (r,1) where 0,1 signfies starting index and ending index respectively.
So there is a sweepline which cross through all the segments. As we encounter a starting index the no. of segments covering the interval increases by 1 and we encounter the ending index it decreases there by giving the total no. of segments crossed by the sweepline at each instant.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n,k;cin>>n<<k;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		v.push_back({a,0});
		v.push_back({b,1});
	}
	sort(v.begin(),v.end());
	int cnt=0;
	int ans=0;
	for(int i=0;i<v.size();i++){
		if(v[i].second==0){
			cnt++;
		}else{
			cnt--;
		}
		if(i+1<v.size()&&cnt>=k){
			ans+=(v[i+1].first-v[i].first);
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