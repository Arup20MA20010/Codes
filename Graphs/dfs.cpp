#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
int n;
vector<int>visited;
void dfs(int src,int cmp){
	visited[src]=cmp;
	for(auto nbrs:g[src]){
		if(!visited[nbrs]){
			dfs(nbrs);
		}
	}
}
void solve(){
	cin>>n;
	g.resize(n+1);
	visited.assign(n+1,0);
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cmp=0;
	for(int i=1;i<n;i++){
		if(!visited[i]){
			cmp++;
			dfs(i,cmp);
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
	solve();
	return 0;
}