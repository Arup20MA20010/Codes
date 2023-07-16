#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
vector<vector<ii>>g;
vector<int>cost;
vector<int>visited;
int n;
int arr[200100];
void dijkstra(int src){
	cost[src]=0;
	priority_queue<ii,vector<ii>,greater<ii>>pq;
	pq.push({0,src});
	while(!pq.empty()){
		ii curr=pq.top();
		pq.pop();
		int currNode=curr.ss;
		if(visited[currNode])continue;
		visited[currNode]=1;
		for(auto nbrs:g[currNode]){
			int nbrsNode=nbrs.ff;
			int weight=nbrs.ss;
			if(cost[nbrsNode]>cost[currNode]+weight){
				cost[nbrsNode]=cost[currNode]+weight;
				pq.push({cost[nbrsNode],nbrsNode});
			}
		}
	}
}
void solve(){
	cin>>n;
	int a,b;cin>>a>>b;
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mp[arr[i]].push_back(i);
	}
	g.resize(n+mp.size()+1);
	visited.assign(n+mp.size()+1,0);
	cost.assign(n+mp.size()+1,1e18);
	int count=0;
	//creation of super nodes
	for(auto v:mp){
		int superNode=v.ff;
		count++;
		for(auto normalNodeIdx:mp[superNode]){
			g[n+count].push_back({normalNodeIdx,a});
			g[normalNodeIdx].push_back({n+count,0});
		}
	}
	//adjacent nodes join
	for(int i=2;i<=n;i++){
		g[i].push_back({i-1,b});
	}
	for(int i=1;i<n;i++){
		g[i].push_back({i+1,b});
	}
	// for(int i=1;i<=n+mp.size();i++){
	// 	cout<<i<<": ";
	// 	for(auto k:g[i]){
	// 		cout<<"("<<k.ff<<" "<<k.ss<<")->";
	// 	}
	// 	cout<<nline;
	// }
	int src;cin>>src;
	dijkstra(src);
	for(int i=1;i<=n;i++){
		cout<<cost[i]<<" ";
	}
	cout<<nline;
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