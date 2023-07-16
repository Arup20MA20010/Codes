#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct node{
	int cnt;
	node*child[26];
	bool is_end;
};
node*getNode(){
	node*temp=new node;
	for(int i=0;i<26;i++){
		temp->child[i]=NULL;
	}
	temp->cnt=0;
	temp->is_end=false;
	return temp;
}
struct trie{
	node*root;
	trie(){
		root=getNode();
	}
	node*getNextNode(node*temp,char ch){
		if(temp==NULL)return NULL;
		return temp->child[ch-'a'];
	}
	void insert(string s){
		node*curr_node=root;
		for(int i=0;i<s.length();i++){
			curr_node->cnt++;
			node*temp=getNextNode(curr_node,s[i]);
			if(temp==NULL){
				temp=getNode();
				curr_node->child[s[i]-'a']=temp;
			}
			curr_node=temp;
		}
		curr_node->cnt++;
		curr_node->is_end=true;
	}
	//no. of string matching till s[0....level]
	int rec(node*curr,int level,string s,int m){
		if(curr==NULL)return 0;
		if(level==m-1){
			if(s[level]=='?'){
				int ans=0;
				for(int i=0;i<26;i++){
					if(curr->child[i]!=NULL&&curr->child[i]->is_end){
						ans+=curr->child[i]->cnt;
					}
				}
				return ans;
			}else{
				curr=curr->child[s[level]-'a'];
				if(curr==NULL)return 0;
				if(curr->is_end){
					return curr->cnt;
				}else{
					return 0;
				}
			}
		}
		//recursive case
		if(s[level]=='?'){
			int ans=0;
			for(int i=0;i<26;i++){
				ans+=rec(curr->child[i],level+1,s,m);
			}
			return ans;
		}else{
			return rec(curr->child[s[level]-'a'],level+1,s,m);
		}
	}
};
void solve(){
	trie tt;
	int n,m;cin>>n>>m;
	string word;
	for(int i=0;i<n;i++){
		cin>>word;
		tt.insert(word);
	}
	int q;cin>>q;
	while(q--){
		string x;cin>>x;
		cout<<tt.rec(tt.root,0,x,m)<<nline;
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