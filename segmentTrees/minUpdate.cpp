#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
int arr[200100];
ii t[800100];
void build(int index,int l,int r){
	if(l==r){
		t[index]={arr[l],1};return;
	}
	int mid=(l+r)/2;
	build(2*index,l,mid);
	build(2*index+1,mid+1,r);
	ii ch1=t[index*2];
	ii ch2=t[index*2+1];
	if(ch1.ff==ch2.ff){
		t[index]={ch1.ff,ch1.ss+ch2.ss};
	}else{
		t[index]=min(ch1,ch2);
	}
}
void update(int index,int l,int r,int pos,int x){
	if(pos<l||pos>r)return;//not in the range
	if(l==r){
		t[index]={x,1};
		arr[pos]=x;
		return;
	}
	int mid=(l+r)/2;
	update(2*index,l,mid,pos,x);//updating the left side
	update(2*index+1,mid+1,r,pos,x);//update the right side
	ii ch1=t[index*2];
	ii ch2=t[index*2+1];
	if(ch1.ff==ch2.ff){
		t[index]={ch1.ff,ch1.ss+ch2.ss};
	}else{
		t[index]=min(ch1,ch2);
	}
}

ii query(int index,int l,int r,int lq,int rq){
	if(lq>r||rq<l)return {1e18,0};
	if(lq<=l&&r<=rq)return t[index];
	int mid=(l+r)/2;
	ii ch1=query(2*index,l,mid,lq,rq);
	ii ch2=query(2*index+1,mid+1,r,lq,rq);
	if(ch1.ff==ch2.ff){
		return {ch1.ff,ch1.ss+ch2.ss};
	}else{
		return min(ch1,ch2);
	}
}
void solve(){
	int n,q;cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ch;
	build(1,0,n-1);
	while(q--){
		cin>>ch;
		if(ch==1){
			int pos,x;cin>>pos>>x;
			pos--;
			update(1,0,n-1,pos,x);
		}else{
			int l,r;cin>>l>>r;
			ii ans=query(1,0,n-1,l,r);
			cout<<ans.ff<<" "<<ans.ss<<nline;
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