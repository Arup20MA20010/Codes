#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;string P;
int dp[100100][2][2];
const int mod=1e9+7;
//returns no. of strings
//flag tells if there is any recent x for which Q[x]<P[x]
int rec(int level,int tlo,int flag){
	if(level==n){
		//base case
		// if(flag==0||flag==1)return 0;
		return flag;
	}
	if(dp[level][tlo][flag]!=-1){
		return dp[level][tlo][flag];
	}
	int lo=0;
	int hi=25;
	if(tlo)lo=P[level]-'A';
	int ans=0;
	for(int i=lo;i<=hi;i++){
		int newFlag=flag;
		int newTlo=tlo;
		if(i!=P[level]-'A')newTlo=0;
		if(P[level]-'A'>i)newFlag=0;
		if(P[level]-'A'<i)newFlag=1;
		// cout<<('A'+i)<<nline;
		// cout<<P[level]-'A'<<newFlag<<nline;
		// cout<<nline;
		ans+=(rec(level+1,newTlo,newFlag)%mod);
		ans%=mod;
	}
	return dp[level][tlo][flag]=ans;
}
void solve(){
	cin>>P;
	n=P.length();
	for(int i=0;i<n;i++){
		dp[i][0][0]=-1;
		dp[i][0][1]=-1;
		dp[i][1][0]=-1;
		dp[i][1][1]=-1;
	}
	cout<<rec(0,1,0)<<nline;
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