#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int pow=26;
	int cnt=0;
	while(n>pow){
		n-=pow;
		pow*=26;
		cnt++;
	}
	// n--;
	vector<char>ans;
	while(n){
		cnt--;
		char ch='A'+(n-1)%26;
		ans.push_back(ch);
		n/=26;
	}
	while(cnt>=0){
		ans.push_back('A');
		cnt--;
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<x;
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