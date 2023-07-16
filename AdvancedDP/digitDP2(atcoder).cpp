#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
const int mod=1e9+7;
int dp[10010][101][2][2];
int n;string R;
int D;
int rec(int level,int sum,int tightHi,int tightLo){
	if(level==n){
		return sum==0;
	}
	int hi=R[level]-'0';
	if(dp[level][sum][tightHi][tightLo]!=-1){
		return dp[level][sum][tightHi][tightLo];
	}
	int ans=0;
	int lo=(level==n-1);
	if(tightHi&tightLo){
		if(lo==hi){
			ans=(ans%mod+rec(level+1,(sum+lo)%D,tightHi,tightLo)%mod)%mod;
			return dp[level][sum][tightHi][tightLo]=ans;
		}
		ans=(ans%mod+rec(level+1,(sum+lo)%D,0,tightLo)%mod)%mod;
		ans=(ans%mod+rec(level+1,(sum+hi)%D,tightHi,0)%mod)%mod;
		for(int i=lo+1;i<hi;i++){
			ans=(ans%mod+rec(level+1,(sum+i)%D,0,0)%mod)%mod;
		}
	}else if(tightHi){
		for(int i=0;i<hi;i++){
			ans=(ans%mod+rec(level+1,(sum+i)%D,0,0)%mod)%mod;
		}
		ans=(ans%mod+rec(level+1,(sum+hi)%D,tightHi,0)%mod)%mod;
	}else if(tightLo){
		for(int i=lo+1;i<10;i++){
			ans=(ans%mod+rec(level+1,(sum+i)%D,0,0)%mod)%mod;
		}
		ans=(ans%mod+rec(level+1,(sum+lo)%D,0,tightLo)%mod)%mod;
	}else{
		for(int i=0;i<10;i++){
			ans=(ans%mod+rec(level+1,(sum+i)%D,0,0)%mod)%mod;
		}
	}
	return dp[level][sum][tightHi][tightLo]=ans;
}
void solve(){
	cin>>R>>D;
	n=R.length();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=100;j++){
			dp[i][j][0][0]=-1;
			dp[i][j][0][1]=-1;
			dp[i][j][1][0]=-1;
			dp[i][j][1][1]=-1;
		}
	}
	cout<<rec(0,0,1,1)<<nline;
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