#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[200100];
int t[800400];
void build(int index,int l,int r){
	if(l==r){
		t[index]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
}
//add +v from the range lq to rq
void update(int index,int l,int r,int lq,int rq,int v){
	if(rq<l||lq>r)return;
	if(lq<=l&&r<=rq){
		t[index]+=v;
		return;
	}
	int mid=(l+r)/2;
	update(2*index,l,mid,lq,rq,v);
	update(2*index+1,mid+1,r,lq,rq,v);
}
int query(int index,int l,int r,int pos){
	if(l>pos||r<pos){
		return -1;
	}
	if(l==r&&l==pos){
		return t[index];
	}
	int mid=(l+r)/2;
	int ch1=query(2*index,l,mid,pos);
	int ch2=query(2*index+1,mid+1,r,pos);
	if(ch1==-1&&ch2==-1){
		return -1;
	}
	if(ch2==-1){
		//ch1 is the thing
		return t[index]+ch1;
	}
	return t[index]+ch2;
}
void solve(){
	int n,q;cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,0,n-1);
	
	while(q--){
		int ch;cin>>ch;
		if(ch==1){
			int i,j,x;cin>>i>>j>>x;
			i--;j--;
			update(1,0,n-1,i,j,x);
		}else{
			int i;cin>>i;
			i--;
			cout<<query(1,0,n-1,i)<<nline;
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