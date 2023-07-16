#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>visited;
bool isCycle=0;
vector<int>parent;
void dfs(int node){
	visited[node]=2;
	for(auto nbrs:g[node]){
		if(visited[nbrs]==1){
			dfs(nbrs);
		}else if(visited[nbrs]==2){
			isCycle=1;
		}
	}
	visited[node]=3;
}
void solve(){
	int n;cin>>n;
	vector<string>s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	g.resize(26);
	visited.assign(26,1);
	vector<int>arr(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<string>temp=s;
	for(int i=0;i<n;i++){
		s[i]=temp[arr[i]-1];	
	}
	bool Ok=1;
	set<int>st[26];
	for(int i=1;i<n;i++){
		int j=0;
		while(j<min(s[i].length(),s[i-1].length())&&s[i][j]==s[i-1][j]){
			j++;
		}
		if(j<min(s[i].length(),s[i-1].length())){
			if(!st[s[i-1][j]-'a'].empty()&&st[s[i-1][j]-'a'].find(s[i][j]-'a')!=st[s[i-1][j]].end()){
				continue;
			}
			st[s[i-1][j]-'a'].insert(s[i][j]-'a');
			g[s[i-1][j]-'a'].push_back(s[i][j]-'a');
		}else if(s[i].length()<s[i-1].length()){
			Ok=0;
			break;
		}
	}
	// for(int i=0;i<26;i++){
	// 	char ch=i+'a';
	// 	cout<<ch<<": ";
	// 	for(auto nbrs:g[i]){
	// 		cout<<(char)(nbrs+'a')<<" ";
	// 	}
	// 	cout<<nline;
	// }
	if(!Ok){
		cout<<"NO"<<nline;
	}
	isCycle=0;
	for(int i=0;i<26;i++){
		if(visited[i]==1){
			dfs(i);
		}
	}
	if(isCycle){
		Ok=0;
	}
	if(Ok){
		cout<<"YES"<<nline;
	}else{
		cout<<"NO"<<nline;
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