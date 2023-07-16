#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
using pii=pair<int,pair<int,int>>;
#define ff first
#define ss second
int n,m;
int c;
vector<vector<ii>>g;
vector<vector<int>>cost;
int p[10010];
vector<vector<int>>visited;
//{node,petrol}
void dijkstra(int start){
	cost[start][0]=0;
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,{start,0}});
	while(!pq.empty()){
		pii curr=pq.top();
		pq.pop();
		int node=curr.ss.ff;
		int petrol=curr.ss.ss;
		if(visited[node][petrol])continue;
		visited[node][petrol]=1;
		//buying the 1L petrol
		if(petrol<c&&cost[node][petrol+1]>cost[node][petrol]+p[node]){
			cost[node][petrol+1]=cost[node][petrol]+p[node];
			pq.push({cost[node][petrol+1],{node,petrol+1}});
		}
		//not buying any thing
		for(auto nbrs:g[node]){
			int nbrsNode=nbrs.ff;
			int d=nbrs.ss;
			if(petrol>=d&&cost[nbrsNode][petrol-d]>cost[node][petrol]){
				cost[nbrsNode][petrol-d]=cost[node][petrol];
				pq.push({cost[nbrsNode][petrol-d],{nbrsNode,petrol-d}});
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int u,v,d;cin>>u>>v>>d;
		g[u].push_back({v,d});
		g[v].push_back({u,d});
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int start,end;
	cin>>start>>end>>c;
	cost.assign(n+1,vector<int>(c+1,1e18));
	visited.assign(n+1,vector<int>(c+1,0));
	dijkstra(start);
	int ans=1e18;
	for(int i=0;i<=c;i++){
		ans=min(ans,cost[end][i]);
	}
	cout<<ans<<nline;
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