#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
string L,R;
int n;
int dp[19][9][7][2][2][8][2];
int digitIndex[]={-1,-1,-1,0,-1,-1,-1,1,-1,2};
int rec(int level,int sum,int div7,int tlo,int thi,int mask,int flag){
	if(level==n){
		if(flag==0)return 0;
		//checking for 3
		if(mask&1){
			if(sum%3==0)return 0;
		}
		if(((mask>>1)&1)&&div7==0)return 0;
		if(((mask>>2)&1)&&sum==0)return 0;
		return 1;
	}
	if(dp[level][sum][div7][tlo][thi][mask][flag]!=-1){
		return dp[level][sum][div7][tlo][thi][mask][flag];
	}
	int lo=0,hi=9;
	if(tlo)lo=L[level]-'0';
	if(thi)hi=R[level]-'0';
	int ans=0;
	for(int i=lo;i<=hi;i++){
		if(i==1)continue;
		if(level==n-1&&i==5)continue;
		int newTlo=tlo;
		int newThi=thi;
		if(i!=L[level]-'0')newTlo=0;
		if(i!=R[level]-'0')newThi=0;
		if(flag==0&&i==0){
			ans+=rec(level+1,sum,div7,newTlo,newThi,mask,flag);
			continue;
		}
		if((i&1)==0)continue;
		int newMask=mask;
		if(digitIndex[i]!=-1){
			newMask=(mask|(1<<digitIndex[i]));
		}
		ans+=rec(level+1,(sum+i)%9,(10*div7+i)%7,newTlo,newThi,newMask,1);

	}
	return dp[level][sum][div7][tlo][thi][mask][flag]=ans;
}
int k;
bool check(int mid,int l){
	memset(dp,-1,sizeof(dp));
	R=to_string(mid);
	L=to_string(l);
	string temp=R;
	n=R.length();
	int j=L.length()-1;
	for(int i=R.length()-1;i>=0;i--){
		if(j>=0){
			temp[i]=L[j];
			j--;
		}else{
			temp[i]='0';
		}
	}
	L=temp;
	int ans=rec(0,0,0,1,1,0,0);
	return ans>=k;
}
void solve(){
	int l,r;cin>>l>>r;
	cin>>k;
	int lo=l;int hi=r;
	int ans=-1;
	while(lo<=hi){
		int mid=lo+(hi-lo)/2;
		if(check(mid,l)){
			ans=mid;
			hi=mid-1;
		}else{
			lo=mid+1;
		}
	}
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
	while(T--){
		solve();
	}
	return 0;
}