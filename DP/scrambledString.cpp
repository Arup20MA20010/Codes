#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[41][41][41];
//state reffers to wether match is cross or straight
string s,t;

bool rec(int l,int r,int start){
	if(l==r){
		if(s[l]==t[start]){
			return dp[l][r][start]=1;
		}
		return dp[l][r][start]=0;
	}
	if(dp[l][r][start]!=-1){
		return dp[l][r][start];
	}
	int ans=0;
	for(int k=l;k<r;k++){
		bool ch1=rec(l,k,start);
		bool ch2=rec(k+1,r,start+k-l+1);
		bool ch3=rec(l,k,start+r-k);
		bool ch4=rec(k+1,r,start);
		ans=((ch1&&ch2)||(ch3&&ch4));
		if(ans){
			return dp[l][r][start]=ans;
		}
	}
	return dp[l][r][start]=ans;
}
void solve(){
	cin>>s>>t;
	int n=s.length();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k]=-1;
			}
		}
	}
	if(rec(0,n-1,0)){
		cout<<"Yes"<<nline;
	}else{
		cout<<"No"<<nline;
	}
	// for(int k=0;k<n-1;k++){
	// 	for(int i=0;i<n;i++){
	// 		for(int j=0;j<n;j++){
	// 			cout<<dp[i][j][k]<<" ";
	// 		}
	// 		cout<<nline;
	// 	}
	// 	cout<<nline;
	// }
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