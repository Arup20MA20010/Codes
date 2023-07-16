#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
using pii=pair<int,pair<int,int>>;
#define ff first
#define ss second
vector<vector<ii>>g;
vector<int>dist;
vector<int>visited;
vector<pii>edgeList;
void dijkstra(int src){
	dist[src]=0;
	priority_queue<ii,vector<ii>,greater<ii>>pq;
	pq.push({0,src});
	while(!pq.empty()){
		ii curr=pq.top();
		pq.pop();
		int node=curr.ss;
		if(visited[node])continue;
		visited[node]=1;
		for(auto nbrs:g[node]){
			int nbrsNode=nbrs.ff;
			int weight=nbrs.ss;
			if(dist[nbrsNode]>dist[node]+weight){
				dist[nbrsNode]=dist[node]+weight;
				pq.push({dist[nbrsNode],nbrsNode});
			}
		}
	}
}
 
void solve(){
	int n;cin>>n;
	g.resize(n+1);
	dist.assign(n+1,1e18);
	visited.assign(n+1,0);
	// nodeTime.assign(n+1,-1);
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int u,v,d;cin>>u>>v>>d;
		g[u].push_back({v,d});
		g[v].push_back({u,d});
		edgeList.push_back({d,{u,v}});
	}
	int src;
	cin>>src;
	dijkstra(src);
	int maxTime=0;
	for(auto edge:edgeList){
		int edgeWt=edge.ff;
		int t1=dist[edge.ss.ff];
		int t2=dist[edge.ss.ss];
		maxTime=max(maxTime,(t1+t2+edgeWt)*5);
	}
	cout<<maxTime<<nline;
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