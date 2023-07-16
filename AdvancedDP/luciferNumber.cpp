#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int dp[11][500][2][2];
int isNotPrime[520];
int n;
string L,R;
int rec(int level,int diff,int thi,int tlo){
	if(level==n){
		if(diff>0&&(!isNotPrime[diff]))return 1;
		return 0;
	}
	if(dp[level][diff][thi][tlo]!=-1){
		return dp[level][diff][thi][tlo];
	}
	int lo=0,hi=9;
	if(tlo)lo=L[level]-'0';
	if(thi)hi=R[level]-'0';
	int ans=0;
	for(int i=lo;i<=hi;i++){
		int newTlo=tlo;
		int newThi=thi;
		if(i!=L[level]-'0')newTlo=0;
		if(i!=R[level]-'0')newThi=0;
		if((n-level)&1){
			ans+=rec(level+1,diff-i,newThi,newTlo);
		}else{
			ans+=rec(level+1,diff+i,newThi,newTlo);
		}
	}
	return dp[level][diff][thi][tlo]=ans;
}
void solve(){
	cin>>L>>R;
	string temp=R;
	int j=L.length()-1;
	for(int i=R.length()-1;i>=0;i--){
		if(j>=0){
			temp[i]=L[j];
			j--;
		}else{
			temp[i]='0';
		}
	}
	memset(dp,-1,sizeof(dp));
	L=temp;
	n=R.length();
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
	isNotPrime[1]=1;
	isNotPrime[0]=1;
	for(int i=2;i*i<=502;i++){
		if(!isNotPrime[i]){
			for(int j=i*i;j<=502;j+=i){
				isNotPrime[j]=1;
			}
		}
	}
	while(T--){
		solve();
	}
	return 0;
}