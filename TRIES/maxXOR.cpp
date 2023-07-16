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
	bool search(int x){
		node*curr=root;
		for(int i=31;i>=0;i--){
			int bit=(x>>i)&1;
			if(curr->child[bit]==NULL||curr->cnt==0)return false;
			curr=curr->child[bit];
		}
		if(curr->cnt==0)return false;
		return true;
	}
	void remove(int x){
		node*curr=root;
		for(int i=31;i>=0;i--){
			curr->cnt--;
			int bit=(x>>i)&1;
			curr=curr->child[bit];
		}
		curr->cnt--;
	}
	int query(int x){
		node*curr=root;
		int ans=0;
		for(int i=31;i>=0;i--){
			int bit=(x>>i)&1;
			if(curr->child[bit^1]!=NULL&&curr->child[bit^1]->cnt>0){
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
	int q;cin>>q;
	trie t;
	while(q--){
		char ch;cin>>ch;
		if(ch=='+'){
			int x;cin>>x;
			t.insert(x);
		}else if(ch=='-'){
			int x;cin>>x;
			t.remove(x);
		}else{
			int x;cin>>x;
			cout<<t.query(x)<<nline;
		}
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