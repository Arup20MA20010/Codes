#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[5001][2][5001];//it returns the minimum time to do the job given val job was done in cpu[flag]
int hot[5001];
int cold[5001];
int arr[5001];
int n;
int rec(int level,int flag,int val){
	if(level==n)return 0;
	if(dp[level][flag][val]!=-1)return dp[level][flag][val];
	int ans=0;
	int ch1=1e18;int ch2=1e18;
	ch1=rec(level+1,1-flag,arr[level-1])+hot[arr[level]]*(arr[level]==val)+cold[arr[level]]*(arr[level]!=val);
	ch2=rec(level+1,flag,val)+hot[arr[level]]*(arr[level]==arr[level-1])+cold[arr[level]]*(arr[level]!=arr[level-1]);
	return dp[level][flag][val]=min(ch1,ch2);
}
void solve(){
	int k;cin>>n>>k;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<k;i++)cin>>cold[i+1];
	for(int i=0;i<k;i++)cin>>hot[i+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][0][j]=-1;
			dp[i][1][j]=-1;
		}
	}
	cout<<rec(1,0,arr[0])+cold[arr[0]]<<nline;
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