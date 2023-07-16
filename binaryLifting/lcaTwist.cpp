#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>depth;
vector<vector<int>>par;
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
}
int lca(int u,int v){
	if(depth[u]<depth[v]){
		swap(u,v);
	}
	//taking to the same level
	for(int i=19;i>=0;i--){
		if(((depth[u]-depth[v])>>i)&1){
			u=par[u][i];
		}
	}
	if(u==v)return v;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
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
	int q;cin>>q;
	while(q--){
		int x,y,z;cin>>x>>y>>z;
		int xy=lca(x,y);
		int zy=lca(y,z);
		int zx=lca(z,x);
		if(zx==xy){//one of the x,y,z
			cout<<zy<<nline;
		}else if(zy==xy){
			cout<<zx<<nline;
		}
		else{
			cout<<xy<<nline;
		}
	}
	g.clear();
	depth.clear();
	par.clear();
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