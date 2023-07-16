#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct node{
	bool is_end;
	node*child[26];
};
node*getNewNode(){
	node*temp=new node;
	temp->is_end=false;
	for(int i=0;i<26;i++){
		temp->child[i]=NULL;
	}
	return temp;
}
struct trie{
	node*root;//pointer to the rootNode
	trie(){
		root=getNewNode();
	}
	node* getNextNode(node*temp,char ch){
		if(temp==NULL)return NULL;
		return temp->child[ch-'a'];
	}
	void insert(string s){
		node*curr_node=root;
		for(int i=s.length()-1;i>=0;i--){
			node*temp=getNextNode(curr_node,s[i]);
			if(temp==NULL){
				temp=getNewNode();
				curr_node->child[s[i]-'a']=temp;
			}
			curr_node=temp;
		}
		curr_node->is_end=true;
	}
};
//dp[i]-> it returns if s[0...i] is breakable or not
// vector<vector<string>>sol;
// //generate all possible solution for level....n
// void generateSol(int level,vector<int>dp,string s,vector<string>ans){
// 	if(level==s.length()){
// 		sol.push_back(ans);
// 	}//base case
// 	for(int i=level;i<s.length();i++){
// 		if(dp[i]){
// 			ans.push_back(s.substr(level,i-level+1));
// 			generateSol(i+1,dp,s,ans);
// 			ans.pop_back();
// 		}
// 	}
// }
void solve(){
	int k;cin>>k;
	string s;cin>>s;
	trie tt;
	string dict;
	int n=s.length();
	while(k--){
		cin>>dict;
		tt.insert(dict);
	}
	vector<int>dp(n,0);
	for(int i=0;i<n;i++){
		dp[i]=0;
		node*root=tt.root;
		for(int j=i;j>=0;j--){
			node*temp=tt.getNextNode(root,s[j]);
			if(temp==NULL){
				break;
			}
			if(temp->is_end){
				if(j==0||dp[j-1]){
					dp[i]=1;
					break;
				}
			}
		}
	}
	if(dp[n-1])
		cout<<"Yes"<<nline;
	else
		cout<<"No"<<nline;	
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