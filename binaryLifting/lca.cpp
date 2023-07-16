#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define nline '\n'
vector<vector<int>>g;
vector<vector<int>>par;//par(X,i)->X -- X+2^i;
vector<int>depth;
void dfs(int node,int parent,int dist){
	depth[node]=dist;
	par[node][0]=parent;
	for(int i=1;i<20;i++){
		par[node][i]=par[par[node][i-1]][i-1];
	}
	for(auto nbrs:g[node]){
		if(nbrs==parent)continue;
		dfs(nbrs,node,dist+1);
	}
	//par[node][i]=par[par[node][i-1]][i-1];
}
int lca(int u,int v){//always keep u at a higher depth than v
	if(depth[u]<depth[v]){
		swap(u,v);
	}
	//taking to the same level
	for(int i=19;i>=0;i--){
		if(((depth[u]-depth[v])>>i)&1){
			u=par[u][i];
		}
	}
	if(u==v)return u;
	//finding the lca
	for(int i=19;i>=0;i--){
		if(par[v][i]!=par[u][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
void solve(){
	int n;cin>>n;
	g.resize(n+1);
	depth.assign(n+1,0);
	par.assign(n+1,vector<int>(20,0));
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<i<<" "<<j<<" : "<<lca(i,j)<<nline;
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
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}