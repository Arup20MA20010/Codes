#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>partial;
vector<vector<int>>par;
vector<int>depth;
void dfs(int node,int dist,int parent){
	depth[node]=dist;
	par[node][0]=parent;
	for(int i=1;i<20;i++){
		par[node][i]=par[par[node][i-1]][i-1];
	}
	for(auto nbrs:g[node]){
		if(nbrs==parent)continue;
		dfs(nbrs,dist+1,node);
	}
}
int lca(int u,int v){
	if(depth[u]<depth[v]){
		swap(u,v);
	}
	for(int i=19;i>=0;i--){
		if(((depth[u]-depth[v])>>i)&1){
			u=par[u][i];
		}
	}
	//now u and v are at the same level
	if(u==v)return u;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
void addX(int u,int v,int x){
	partial[u]+=x;
	partial[v]+=x;
	int z=lca(u,v);
	partial[z]-=x;
	partial[par[z][0]]-=x;
}
void pushDown(int src){
	for(auto nbrs:g[src]){
		if(nbrs==par[src][0])continue;
		pushDown(nbrs);
	}
	partial[par[src][0]]+=partial[src];
}
void solve(){
	int n;cin>>n;
	g.resize(n+1);
	depth.assign(n+1,0);
	par.assign(n+1,vector<int>(21,0));
	partial.assign(n+1,0);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0,0);
	int q;cin>>q;
	while(q--){
		int u,v,z;cin>>u>>v>>z;
		addX(u,v,z);
	}
	pushDown(1);
	for(int i=1;i<=n;i++){
		cout<<partial[i]<<" ";
	}
	cout<<nline;
	g.clear();
	depth.clear();
	par.clear();
	partial.clear();
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