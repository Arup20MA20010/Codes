#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;cin>>s;
	string temp=s;
	temp+=temp;
	int n=s.length();
	string pattern1;
	string pattern2;
	for(int i=0;i<2*n;i++){
		if(i&1){
			pattern1.push_back('w');
			pattern2.push_back('b');
		}else{
			pattern1.push_back('b');
			pattern2.push_back('w');
		}
	}
	int misMatch1[2*n];
	int misMatch2[2*n];
	for(int i=0;i<2*n;i++){
		misMatch1[i]=(pattern1[i]!=temp[i]);
		misMatch2[i]=(pattern2[i]!=temp[i]);
		if(i){
			misMatch1[i]+=misMatch1[i-1];
			misMatch2[i]+=misMatch2[i-1];
		}
	}
	int ans=1e18;
	for(int i=0;i<n;i++){
		int ans1=misMatch1[i+n-1];
		int ans2=misMatch2[i+n-1];
		if(i){
			ans2-=misMatch2[i-1];
			ans1-=misMatch1[i-1];
		}
		ans=min(ans,min(ans1,ans2));
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