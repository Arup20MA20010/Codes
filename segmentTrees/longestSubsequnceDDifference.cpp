/*
To find the maximum length subsequence such that abs(ai-ai+1)<D.
dp(i) the maximum length of the subsequence that ends in i
now using segment trees we can find the maximum length that ends in certain value(compressed value). dp(i)=max(length in range arr[i]-D to arr[i]+D)+1;
then update the value of segment tree in the range for comp[arr[i]] with dp(i)+1;
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[100100],n;
int dp[100100];
int t[400100];
int D;
#define mid ((l+r)>>1)
void update(int index,int l,int r,int x,int val){
	if(x<l||x>r)return;
	if(l==r){
		t[index]=val;
		return;
	}
	update(index<<1,l,mid,x,val);
	update(index<<1|1,mid+1,r,x,val);
	t[index]=max(t[index<<1],t[index<<1|1]);
}
int query(int index,int l,int r,int lq,int rq){
	if(lq>r||rq<l)return 0;
	if(lq<=l&&r<=rq){
		return t[index];
	}
	return max(query(index<<1,l,mid,lq,rq),query(index<<1|1,mid+1,r,lq,rq));
}
void solve(){
	cin>>n>>D;
	map<int,int>compVal;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		compVal[arr[i]];
	}
	int cnt=0;
	for(auto &v:compVal){
		v.second=cnt++;//updating the compressed value
	}
	int ans=0;
	for(int i=0;i<n;i++){
	//need to find the max in range arr[i]-D to arr[i]+D
		auto it=compVal.upper_bound(arr[i]+D);
		it--;int hi=it->second;//taking the compressed value
		it=compVal.lower_bound(arr[i]-D);
		int lo=it->second;//taking the compressed value
		dp[i]=query(1,0,cnt-1,lo,hi)+1;
		ans=max(ans,dp[i]);
		update(1,0,cnt-1,compVal[arr[i]],dp[i]);//updating the leaf node that have the compressedVal[arr[i]] to dp[i]
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
	solve();
	return 0;
}