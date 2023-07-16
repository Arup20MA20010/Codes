#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
struct box{
	int height;
	int width;
	int length;
	box(){};
	box(int l,int w,int h){
		height=h;
		width=w;
		length=l;
	}
	void setVal(int l,int w,int h){
		height=h;
		width=w;
		length=l;
	}
};
box arr[3001];
int dp[3001][3001][2];
int rec(int i,int j,int flag){
	if(i==3*n){
		return 0;
	}
	if(dp[i][j][flag]!=-1)return dp[i][j][flag];
	if(flag){
		return dp[i][j][flag]=max(rec(i+1,i,0)+arr[i].height,rec(i+1,j,flag));
	}
	int ans=0;
	if(arr[i].width<arr[j].width&&arr[i].length<arr[j].length){
		ans=max(ans,rec(i+1,i,0)+arr[i].height);
	}
	ans=max(ans,rec(i+1,j,flag));
	return dp[i][j][flag]=ans;
}
void solve(){
	cin>>n;
	for(int i=0;i<3*n;i+=3){
		int h,l,w;
		cin>>h>>l>>w;
		arr[i].setVal(max(l,w),min(l,w),h);
		arr[i+1].setVal(max(h,w),min(h,w),l);
		arr[i+2].setVal(max(l,h),min(l,h),w);
	}
	sort(arr,arr+3*n,[&](box a,box b){
		if(a.length==b.length){
			return (a.width==b.width)&&(a.height>b.height)||(a.width>b.width);
		}
		return a.length>b.length;
	});
	// for(int i=0;i<3*n;i++){
	// 	cout<<arr[i].length<<" "<<arr[i].width<<" "<<arr[i].height<<nline;
	// }
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0,1)<<nline;
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