#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct node{
	node*child[2];
	int cnt;
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
	int query(int x,int k){
		node*curr=root;
		int ans=0;
		for(int i=31;i>=0;i--){
			int kbit=(k>>i)&1;
			int xbit=(x>>i)&1;
			if(kbit){
				//then if we take the bit to be zero then all possible answers are possible
				if(curr->child[xbit]!=NULL){
					ans+=curr->child[xbit]->cnt;
					ans--;
				}
				if(curr->child[xbit^1]!=NULL){
					curr=curr->child[xbit^1];
				}else{
					ans++;
					return ans;
				}
			}else{
				if(curr->child[xbit]!=NULL){
					curr=curr->child[xbit];
				}else{
					ans++;
					return ans;
				}
			}

		}
		if(curr!=NULL){
			ans+=curr->cnt;
		}
		return ans;
	}
};
void solve(){
	int n,k;cin>>n>>k;
	trie t;
	int prev=0;
	int ans=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		prev=prev^x;
		ans+=t.query(prev,k);
		t.insert(prev);
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
	int T;cin>>T;
	while(T--)solve();
	return 0;
}