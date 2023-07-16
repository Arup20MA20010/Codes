#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[200100];
struct node{
	int maxSum;
	int fullSum;
	int leftSum;
	int rightSum;
	node(int val=0){
		maxSum=val>=0?val:0;
		fullSum=val;
		leftSum=val>=0?val:0;;
		rightSum=val>=0?val:0;;
	}
};
//c=amergeb
node merge(node &a,node &b){
	node c;
	c.fullSum=a.fullSum+b.fullSum;
	c.leftSum=max(a.fullSum+b.leftSum,a.leftSum);
	c.rightSum=max(b.fullSum+a.rightSum,b.rightSum);
	c.maxSum=max(a.maxSum,max(b.maxSum,a.rightSum+b.leftSum));
	return c;
}
node t[800100];
void build(int index,int l,int r){
	if(l==r){
		t[index]=node(arr[l]);
		return;
	}
	int mid=(l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	t[index]=merge(t[2*index],t[2*index+1]);
}
void update(int index,int l,int r,int k,int x){
	if(k<l||k>r)return;
	if(l==r){
		arr[l]=x;
		t[index]=node(x);
		return;
	}
	int mid=(l+r)/2;
	update(2*index,l,mid,k,x);
	update(2*index+1,mid+1,r,k,x);
	t[index]=merge(t[2*index],t[2*index+1]);
}
void solve(){
	int n;cin>>n;
	int m;cin>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,0,n-1);
	for(int i=0;i<m;i++){
		int k,x;cin>>k>>x;
		k--;
		update(1,0,n-1,k,x);
		cout<<t[1].maxSum<<nline;
	}
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