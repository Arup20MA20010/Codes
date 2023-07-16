#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	vector<int>dp;
	string s;cin>>s;
	int n=s.length();
	dp.assign(n+1,0);
	dp[0]=0;
	dp[1]=2*(s[0]=='('&&s[1]==')');
	for(int i=2;i<n;i++){
		if(s[i]=='(')continue;
		if(s[i-1]==')'&&i-dp[i-1]>=1&&s[i-dp[i-1]-1]=='('){
			dp[i]=2+dp[i-1];
			if(i-dp[i-1]-2>=0){
				dp[i]+=dp[i-dp[i-1]-2];
			}
		}
		else if(s[i-1]=='('){
			dp[i]=2+dp[i-2];
		}
	}
	int maxL=0;
	for(int i=0;i<n;i++){
		maxL=max(dp[i],maxL);
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=(maxL==dp[i]);
	}
	if(maxL==0){
		cout<<0<<" "<<1<<nline;
		return;
	}	
	cout<<maxL<<" "<<cnt<<nline;
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