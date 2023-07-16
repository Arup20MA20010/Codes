#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>succ;
vector<int>par;
int n;
void dfs(int node,int parent){
	par[node]=parent;
	succ[node]=1;
	for(auto nbrs:g[node]){
		if(nbrs==par[node])continue;
		dfs(nbrs,node);
		succ[node]+=succ[nbrs];
	}
}
int findCentroid(int root){
	int centroid=root;
	for(auto nbrs:g[root]){
		if(nbrs==par[root])continue;
		if(succ[nbrs]<((n+1)/2))continue;
		if((n%2==0)&&succ[nbrs]==(n/2)){
			centroid=min(root,nbrs);
		}else{
			centroid=findCentroid(nbrs);
		}
	}

	return centroid;
}
void solve(){
	cin>>n;
	g.resize(n+1);
	succ.assign(n+1,1);
	par.assign(n+1,0);
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	int centroid=findCentroid(1);
	cout<<centroid<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	solve();
	return 0;
}