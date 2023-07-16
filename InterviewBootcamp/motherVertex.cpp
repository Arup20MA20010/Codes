#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n,m;
vector<vector<int>>g;
vector<int>visited;
void dfs(int node){
	visited[node]=1;
	for(auto nbrs:g[node]){
		if(visited[nbrs])continue;
		dfs(nbrs);
	}
}
void solve(){
	cin>>n;
	g.resize(n+1);
	visited.assign(n+1,0);
	int mother=0;
	cin>>m;
	set<pair<int,int>>st;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		if(u==v||st.find({u,v})!=st.end())
			continue;
		st.insert({u,v});
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
			mother=i;
		}
	}
	visited.clear();
	visited.assign(n+1,0);
	dfs(mother);
	bool Ok=1;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			Ok=0;
			break;
		}
	}
	if(Ok)cout<<"Yes"<<nline;
	else
		cout<<"No"<<nline;
	g.clear();
	visited.clear();
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