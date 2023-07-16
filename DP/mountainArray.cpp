#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
const int mod=1e9+7;
/*
dp(level,flag,i)->no of ways to form bitonic array from level...n
given the arr[level-1] went to flag postion and arr[i] is the other value.
if flag==0 => level-1 is in left else right
dp(level,flag,i)=dp(level+1,flag,i)+dp(level+1,!flag,level-1);
*/
int dp[1001][1001][2];
int arr[1001];
int n,k;
// static int cnt=0;
deque<int>dq;
int rec(int level,int index,int flag){
	//base case
	if(level==n){
		if(index==0)return 0;
		return 1;
	}
	// cache check
	if(dp[level][index][flag]!=-1){
		return dp[level][index][flag];
	}
	int ans=0;
	//going in the flag position
	if(arr[level-1]>arr[level]&&arr[level-1]-arr[level]<=k){
		// cout<<"before level left: "<<level<<" "<<ans<<nline;
		// if(flag){
		// 	dq.push_back(level);
		// }else{
		// 	dq.push_front(level);
		// }
		ans=(ans%mod+rec(level+1,index,flag)%mod)%mod;
		// if(flag){
		// 	dq.pop_back();
		// }else{
		// 	dq.pop_front();
		// }
		// cout<<"level left :"<<level<<" "<<ans<<nline;
	}
	//going in opposite of the flag direction
	if(arr[level]<arr[index]&&arr[index]-arr[level]<=k){
		// cout<<"before "<<"level right: "<<level<<" "<<ans<<nline;
		// if(flag){
		// 	dq.push_back(level);
		// }else{
		// 	dq.push_front(level);
		// }
		ans=(ans%mod+rec(level+1,level-1,1-flag)%mod)%mod;
		// cout<<"level right: "<<level<<" "<<ans<<nline;
		// if(flag){
		// 	dq.pop_back();
		// }else{
		// 	dq.pop_front();
		// }
	}
	// cout<<level<<": "<<cnt<<nline;
	// cout<<level<<":"<<"ans "<<ans<<nline;
	// cout<<nline;
	// cout<<nline;
	return dp[level][index][flag]=ans;
}
void solve(){
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i]*=-1;
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		arr[i]*=-1;
	}
	dq.push_back(0);
	cout<<rec(1,0,0)<<nline;
	
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