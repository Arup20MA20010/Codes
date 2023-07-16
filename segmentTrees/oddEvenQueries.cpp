#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[100100];
int t[400100];//{stores the count of odd numbers in [l..r]}
void build(int index,int l,int r){
	if(l==r){
		t[index]=arr[l]&1;
		return;
	}
	int mid=(l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	t[index]=t[2*index]+t[2*index+1];
}
//update the no. at index x to y
void update(int index,int l,int r,int x,int y){
	if(x<l||r<x)return;
	if(l==r){
		arr[l]=y;
		t[index]=y&1;
		return;
	}
	int mid=(l+r)/2;
	update(2*index,l,mid,x,y);
	update(2*index+1,mid+1,r,x,y);
	t[index]=t[2*index]+t[2*index+1];
}
//query for the no of odd numbers in l..r
int query(int index,int l,int r,int lq,int rq){
	if(l>rq||r<lq)return 0;
	if(lq<=l&&r<=rq){
		return t[index];
	}
	int mid=(l+r)/2;
	return query(2*index,l,mid,lq,rq)+query(2*index+1,mid+1,r,lq,rq);
}
void solve(){
	int n,q;cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ch;
	cin>>q;
	build(1,0,n-1);
	
	
	while(q--){
		cin>>ch;
		if(ch==0){
			int x,y;cin>>x>>y;
			x--;
			update(1,0,n-1,x,y);
		}else if(ch==1){
			int l,r;cin>>l>>r;
			l--;r--;
			cout<<(r-l+1)-query(1,0,n-1,l,r)<<nline;
		}else{
			int l,r;cin>>l>>r;
			l--;r--;
			cout<<query(1,0,n-1,l,r)<<nline;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}