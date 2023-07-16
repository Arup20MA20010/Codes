#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct node{
	bool is_end;
	node*child[26];
	int cnt;
};
node*getNewNode(){
	node*temp=new node;
	temp->cnt=0;
	temp->is_end=false;
	for(int i=0;i<26;i++){
		temp->child[i]=NULL;
	}
	return temp;
}
struct trie{
	node*root;
	map<string,int>mp;
	trie(){
		root=getNewNode();
	}
	node*getNextNode(node*temp,char ch){
		if(temp==NULL)return NULL;
		return temp->child[ch-'a'];
	}
	void insert(string s){
		mp[s]++;
		node*curr_node=root;
		for(int i=0;i<s.length();i++){
			curr_node->cnt++;
			node*temp=getNextNode(curr_node,s[i]);
			if(temp==NULL){
				temp=getNewNode();
				curr_node->child[i]=temp;
			}
			curr_node=temp;
		}
		curr_node->cnt++;
		curr_node->is_end=true;
	}
};
void dfs(node*curr_)