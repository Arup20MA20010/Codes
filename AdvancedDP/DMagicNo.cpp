#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
string L,R;
int D,M;
const int mod=1e9+7;
int dp[2001][2001][2][2];
int rec(int level,int sum,int tightLo,int tightHi){
	if(level==n){
		return sum==0;
	}
	if(dp[level][sum][tightLo][tightHi]!=-1){
		return dp[level][sum][tightLo][tightHi];
	}
	int lo=0;
	int hi=9;
	if(tightHi)hi=R[level]-'0';
	if(tightLo)lo=L[level]-'0';
	int ans=0;
	for(int i=lo;i<=hi;i++){
		if((level&1)==0&&i==D)continue;
		else if((level&1)==1&&i!=D)continue;
		int newTightHi=tightHi;
		int newTightLo=tightLo;
		if(i!=R[level]-'0')newTightHi=0;
		if(i!=L[level]-'0')newTightLo=0;
		ans+=(rec(level+1,(sum*10+i)%M,newTightLo,newTightHi)%mod);
		ans%=mod;
	}
	return dp[level][sum][tightLo][tightHi]=ans;
}
void solve(){
	cin>>M>>D;
	cin>>L>>R;
	n=L.length();
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0,1,1)<<nline;
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