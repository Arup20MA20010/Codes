#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	vector<int>pos(26,0);
	string s;cin>>s;
	int n=s.length();
	//stored the extreme positions of elements 
	for(int i=0;i<n;i++){
		pos[s[i]-'a']=i;
	}
	vector<int>ans;
	int cnt=0;
	int maxL=0;
	for(int i=0;i<n;i++){
		maxL=max(pos[s[i]-'a'],maxL);
		if(i<maxL)cnt++;
		else if(i==maxL){
			maxL=0;
			ans.push_back(cnt+1);
			cnt=0;
		}
	}
	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<nline;
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