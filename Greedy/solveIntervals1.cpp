#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using pii=pair<int,int>;
#define ff first
#define ss second
void solve(){
	int n,L;cin>>n>>L;
	vector<pii>intervals;
	map<int,int>rightExtreme;
	map<int,int>leftExtreme;
	// map<int,int>leftExtreme;
	for(int i=0;i<n;i++){
		int l,r;cin>>l>>r;
		intervals.push_back({l,0});
		intervals.push_back({r,1});
		if(rightExtreme.find(l)==rightExtreme.end()){
			rightExtreme[l]=r;
		}else{
			rightExtreme[l]=max(rightExtreme[l],r);
		}
	}
	sort(intervals.begin(),intervals.end());
	int rightChoice=0;
	int potentialChoice=0;
	int ans=0;
	int leftChoice=0;
	// for(auto interval:intervals){
	// 	cout<<interval.ff<<" "<<interval.ss<<nline;
	// }
	for(int i=0;i<intervals.size();i++){
		if(intervals[i].ss==0){
			int l=intervals[i].ff;
			if(leftChoice==l){
				rightChoice=max(rightExtreme[l],rightChoice);
			}
			potentialChoice=max(rightExtreme[l],potentialChoice);
		}else{
			/*
			When i am exiting i am updating the answer. So if I dont get an potential choice other than right Choice that means right choice is L
			*/
			int r=intervals[i].ff;
			if(rightChoice==L){
				break;
			}
			if(r==rightChoice){
				ans++;
				rightChoice=potentialChoice;
			}
		}
		// cout<<rightChoice<<" "<<potentialChoice<<nline;
	}
	ans++;
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