#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int A[]={1,0,0};
	vector<pair<int,int>>arr;
	arr.push_back({0,1});
	arr.push_back({1,2});
	arr.push_back({0,2});
	string s;cin>>s;
	for(int i=0;i<s.length();i++){
		swap(A[arr[s[i]-'A'].first],A[arr[s[i]-'A'].second]);
	}
	int ans=-1;
	for(int i=0;i<=2;i++){
		if(A[i])
			ans=i;
	}
	cout<<ans+1<<nline;
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