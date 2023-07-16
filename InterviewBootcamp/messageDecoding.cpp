#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int stringToInt(string s){
	if(s.length()==1)return (s[0]-'0');
	return (s[0]-'0')*10+(s[1]-'0');
}
const int mod=1e9+7;
void solve(){
	string s;cin>>s;
	int n=s.length();
	vector<int>dp(n,0);
	dp[0]=(s[0]!='0');
	if(n==1){
		cout<<dp[0]<<nline;
		return;
	}
	dp[1]=(stringToInt(s.substr(0,2))<=26)+(s[1]!=0);
	for(int i=2;i<n;i++){
		dp[i]+=dp[i-1]*(s[i]!='0')+dp[i-2]*(stringToInt(s.substr(i-1,2))<=26)*(s[i-1]!='0');
		dp[i]%=mod;
	}
	cout<<dp[n-1]<<nline;
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