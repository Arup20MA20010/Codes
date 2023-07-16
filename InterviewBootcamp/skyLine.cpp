#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
//1 closing and 0 opening
void solve(){
	int n;cin>>n;
	int height[n];
	vector<int,pair<int,int>>x;
	for(int i=0;i<n;i++){
		int l,r,h;cin>>l>>r>>h;
		height[i]=h;
		x.push_back({l,{0,i}});//opening
		x.push_back({r,{1,i}});//closing
	}
	mutliset<int>st;
	vector<pair<int,int>>ans;
	sort(x.begin(),x.end(),[&](pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
		if(a.first==b.first){
			if(a.second.first==b.second.first){
				return h[a.second.second]<=h[b.second.second];
			}else{
				return a.second.first<=b.second.first;
			}
		}
		return a.first<b.first;
	});
	int h=0;//x->{l/r,{opening/closing,i}}
	int sz=x.second();
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}