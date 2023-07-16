#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>visited;
vector<int>vistime;
int timer=0;
void dfs(int node,int par,int &cycle){
	visited[node]=1;
	vistime[node]=timer;
	timer++;
	//going through all the neighbours
	for(auto nbrs:g[node]){
		if(nbrs==par)continue;
		if(!visited[nbrs]){
			dfs(nbrs,node,cycle);
		}else{
			if(vistime[nbrs]<vistime[node])
				cycle++;
		}
	}
}
void solve(){
	int n,m;cin>>n>>m;
	g.resize(n+1);
	visited.assign(n+1,0);
	vistime.assign(n+1,1e18);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int countCycle=0;
	dfs(1,0,countCycle);
	cout<<countCycle<<nline;
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