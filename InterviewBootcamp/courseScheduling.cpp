#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>visited;
bool isCycle;
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
	int m;cin>>m;
	g.resize(n);
	visited.assign(n,1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
	}
	
	for(int i=1;i<=n;i++){
		if(visited[i]==1)dfs(i);
	}
	if(isCycle){
		cout<<"No"<<nline;
	}else{
		cout<<"Yes"<<nline;
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