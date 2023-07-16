#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int t[400100];
void build(int index,int l,int r){
	if(l==r){
		t[index]=1;
		return;
	}
	int mid=(l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	t[index]=t[2*index]+t[2*index+1];
}
void remove(int index,int l,int r,int x){
	if(x<l||x>r)return;
	if(l==r){
		t[index]=0;
		return;
	}
	int mid=(l+r)/2;
	remove(2*index,l,mid,x);
	remove(2*index+1,mid+1,r,x);
	t[index]=t[2*index]+t[2*index+1];
}
int query(int index,int l,int r,int k){
	if(l==r){
		return l;
	}
	int mid=(l+r)/2;
	int ans=-1;
	if(k<=t[2*index]){
		ans=query(2*index,l,mid,k);
	}else{
		ans=query(2*index+1,mid+1,r,k-t[2*index]);
	}
	return ans;
}
void solve(){
	int n;cin>>n;
	vector<int>arr(n,0);
	map<int,int>mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]=i+1;
	}
	sort(arr.begin(),arr.end());
	vector<int>ans(n,0);
	vector<int>p(n,0);
	build(1,0,n-1);
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	for(int i=n-1;i>=0;i--){
		int compIndex=query(1,0,n-1,i-p[i]+1);
		ans[i]=mp[arr[compIndex]];
		remove(1,0,n-1,compIndex);
	}
	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<nline;
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