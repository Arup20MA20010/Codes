#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
string s,t;
int dp[1001][1001];
int pos[1001][1001];
int rec(int i,int j){
	//base case
	if(i<0)return 1e18;
	if(j<0)return 1;
	//cache check
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int k=pos[i][j];//last position of s[i] in t[1...j]
	if(k==-1)return dp[i][j]=1;
	return dp[i][j]=min(rec(i-1,j),rec(i-1,k-1)+1);
}
void solve(){
	string s,t;
	cin>>s>>t;
	int n=s.length();int m=t.length();
	for(int i=0;i<n;i++){
		int p=-1;
		for(int j=0;j<m;j++){
			if(s[i]==t[j])p=j;
			pos[i][j]=p;
			dp[i][j]=-1;
		}
	}
	int ans=rec(n-1,m-1);
	cout<<(ans>=1e18?-1:ans)<<nline;
	
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