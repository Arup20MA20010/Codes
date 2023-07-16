#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct node{
	int cnt;
	node*child[2];
	node(){
		cnt=0;
		child[0]=NULL;
		child[1]=NULL;
	}
};
struct trie{
	node*root;
	trie(){
		root=new node;
		node*curr=root;
		for(int i=31;i>=0;i--){
			curr->cnt++;
			if(curr->child[0]==NULL){
				curr->child[0]=new node;
			}
			curr=curr->child[0];
		}
		curr->cnt++;
	}
	void insert(int x){
		node*curr=root;
		for(int i=31;i>=0;i--){
			curr->cnt++;
			int bit=(x>>i)&1;
			if(curr->child[bit]==NULL){
				curr->child[bit]=new node;
			}
			curr=curr->child[bit];
		}
		curr->cnt++;
	}
	int query(int x){
		node*curr=root;
		int ans=0;
		for(int i=31;i>=0;i--){
			int bit=(x>>i)&1;
			if(curr->child[bit^1]!=NULL){
				ans+=(1<<i);
				curr=curr->child[bit^1];
			}else{
				curr=curr->child[bit];
			}
		}
		return ans;
	}
};
void solve(){
	int n;cin>>n;
	trie t;
	int x;
	int prev=0;
	int maxval=0;
	for(int i=0;i<n;i++){
		cin>>x;
		prev=prev^x;
		maxval=max(maxval,t.query(prev));
		t.insert(prev);
	}
	cout<<maxval<<nline;
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
