#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>dist;
vector<int>visited;
int n;
void bfs(int src){
	dist.assign(n+1,1e9);
	visited.assign(n+1,0);
	visited[src]=1;
	queue<int>q;q.push(src);
	dist[src]=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(visited[curr])continue;
		visited[curr]=1;
		for(auto nbrs:g[curr]){
			if(dist[nbrs]>dist[curr]+1){
				dist[nbrs]=dist[curr]+1;
				q.push(nbrs);
			}
		}
	}
}
void solve(){
	cin>>n;
	g.resize(n+1);
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
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