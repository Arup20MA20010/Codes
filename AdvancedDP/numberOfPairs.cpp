#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
bool isPrime(int n){
	if(n==0||n==1)return false;
	if(n==2)return true;
	if(n%2==0)return false;
	for(int j=3;j<=sqrt(n);j+=2){
		if((n%j)==0){
			return false;
		}
	}
	return true;
}
//flag 0 x=y,1 x<y
int dp[52][500][500][2][2];
string N;
int n;
const int mod=1e9+7;
// vector<int>pos1;
// vector<int>pos2;
int rec(int level,int sum1,int sum2,int flag,int thi){
	if(level==n){
		if(flag==0)return 0;
		if((sum1>sum2)&&(isPrime(sum1+sum2))){
			// cout<<sum1<<" "<<sum2<<nline;
			// cout<<nline;
			// for(auto x:pos1){
			// 	cout<<x;
			// }
			// cout<<" ";
			// for(auto x:pos2){
			// 	cout<<x;
			// }
			// cout<<nline;
			return 1;
		}
		return 0;
	}
	if(dp[level][sum1][sum2][flag][thi]!=-1)return dp[level][sum1][sum2][flag][thi];
	int lo=0,hi=9;
	if(thi)hi=N[level]-'0';
	int ans=0;
	for(int i=lo;i<=hi;i++){
		int newThi=thi;
		if(i!=N[level]-'0')newThi=0;
		for(int j=0;j<=9;j++){
			if(flag==0&&(i<j))break;
			int newFlag=1;
			if(flag==0&&(i==j))newFlag=0;
			ans+=rec(level+1,sum1+i,sum2+j,newFlag,newThi);
			ans%=mod;
		}
	}
	return dp[level][sum1][sum2][flag][thi]=ans;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>N;
	n=N.length();
	cout<<rec(0,0,0,0,1)<<nline;
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