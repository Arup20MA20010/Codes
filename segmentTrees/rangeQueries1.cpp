#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[200100];
int t[800400];
int n;
void build(int index,int l,int r){
	if(l==r){
		t[index]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*index,l,mid);//building the left subtree
	build(2*index+1,mid+1,r);
	t[index]=t[2*index]+t[2*index+1];//merge function
}
void update(int index,int l,int r,int x,int v){
	if(x<l||x>r)return;
	if(l==r){
		arr[l]=v;
		t[index]=v;
		return;
	}
	int mid=(l+r)/2;
	//update the left side
	update(2*index,l,mid,x,v);
	update(2*index+1,mid+1,r,x,v);
	t[index]=t[2*index]+t[2*index+1];
}
int query(int index,int l,int r,int lq,int rq){
	if(lq>r||rq<l)return 0;
	if(lq<=l&&r<=rq){
		return t[index];
	}
	int mid=(l+r)/2;
	return query(2*index,l,mid,lq,rq)+query(2*index+1,mid+1,r,lq,rq);
}
void solve(){
	cin>>n;
	int q;cin>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,0,n-1);
	// for(int i=1;i<4*n;i++){
	// 	cout<<t[i]<<" ";
	// }
	// cout<<nline;
	int ch;
	while(q--){
		cin>>ch;
		if(ch==1){
			int i,x;cin>>i>>x;
			update(1,0,n-1,i-1,x);
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