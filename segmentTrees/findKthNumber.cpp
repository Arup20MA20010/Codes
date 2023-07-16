/*
we need to define the datastructure for for inserting, removing and finding the kth element
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void udpdateSet(int index,int l,int r,int x,bool remove){
	if(x<l||x>r)return;
	if(l==r){
		if(remove)t[l]=0;
		else
			t[l]=1;
		return;
	}
	int mid=(l+r)/2;
	insertIntoSet(2*index,l,mid,x);
	insertIntoSet(2*index+1,mid+1,r,x);
	t[index]=t[2*index]+t[2*index+1];
}
int query(int index,int l,int r,int k){
	if(k<0||k>r-l+1)return -1;
	if(l==r){
		return l;
	}
	int mid=(l+r)/2;
	int ans=-1;
	if(t[2*index]<=k){
		ans=query(2*index,l,mid,k);
	}else{
		ans=query(2*index+1,mid+1,r,k-t[2*index]);
	}
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	return 0;
}