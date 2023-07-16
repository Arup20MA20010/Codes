#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
string L,R;
int n;
int dp[19][2][2][9][7][8][9][(1<<8)][2];
int k;
int rec(int level,int thi,int tlo,int distinct,int rem7,int rem8,int rem9,int mask,int flag){
	if(level==n){
		//base case
		if(distinct<k)return 0;
		//check for 7
		int cnt=0;
		//check for divisibilty
		if(((mask>>0)&1)&&(rem8%2)==0){
			cnt++;
		}
		if(((mask>>1)&1)&&(rem9%3)==0){
			cnt++;
		}
		if(((mask>>2)&1)&&(rem8%4)==0){
			cnt++;
		}
		if(((mask>>3)&1)&&flag){
			cnt++;
		}
		if(((mask>>4)&1)&&((rem8%2)==0)&&(rem9%3)==0){
			cnt++;
		}
		if(((mask>>5)&1)&&(rem7==0)){
			cnt++;
		}
		if(((mask>>6)&1)&&(rem8==0))
			cnt++;
		if(((mask>>7)&1)&&(rem7==0))
			cnt++;
		return cnt>=k;
	}
	if(dp[level][thi][tlo][distinct][rem7][rem8][rem9][mask][flag]!=-1){
		return dp[level][thi][tlo][distinct][rem7][rem8][rem9][mask][flag];
	}
	int lo=0;int hi=9;
	if(tlo)
		lo=L[level]-'0';
	if(thi)
		hi=R[level]-'0';
	int ans=0;
	int newFlag=0;
	for(int i=lo;i<=hi;i++){
		if(level==n-1&&i==5){
			newFlag=1;
		}else{
			newFlag=0;
		}
		int newThi=thi;int newTlo=tlo;
		if(i!=L[level]-'0'){
			newTlo=0;
		}
		if(i!=R[level]-'0'){
			newThi=0;
		}
		if(i==1||i==0){
			ans+=rec(level+1,newThi,newTlo,distinct,(rem7+i)%7,(rem8+i)%8,(rem9+i)%9,mask,newFlag);
			continue;
		}
		if((mask>>i)&1){
			ans+=rec(level+1,newThi,newTlo,distinct,(rem7+i)%7,(rem8+i)%8,(rem9+i)%9,mask,newFlag);
		}else{
			ans+=rec(level+1,newThi,newTlo,distinct+1,(10*rem7+i)%7,(10*rem8+i)%8,(rem9+i)%9,mask|(1<<i),newFlag);
		}
	}
	return dp[level][thi][tlo][distinct][rem7][rem8][rem9][mask][flag]=ans;
}
void solve(){
	cin>>k;
	cin>>L>>R;
	memset(dp,-1,sizeof(dp));
	string temp=R;
	int n=R.length();
	int i=L.length()-1;
	for(int j=n-1;j>=0;j--){
		if(i>=0){
			temp[j]=L[i];
			i--;
		}else{
			temp[j]='0';
		}
	}
	L=temp;
	// cout<<L<<" "<<R<<nline;
	int ans=rec(0,1,1,0,0,0,0,0,0);
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}