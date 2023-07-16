#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
vector<vector<int>>g;
vector<int>dist;
vector<int>par;
int d;
int cnt=0;
void dfs(int node,int parent,int distance){
	par[node]=parent;
	dist[node]=distance;
	if(dist[node]==d){
		cnt++;
	}
	for(auto nbrs:g[node]){
		if(nbrs==par[node])continue;
		dfs(nbrs,node,distance+1);
	}
}
void solve(){
	int n;cin>>n;
	g.resize(n+1);
	dist.assign(n+1,0);
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(n==1){
		cout<<0<<nline;
		return;
	}
	if(n==2){
		cout<<1<<nline;
		return;
	}
	par.assign(n+1,0);
	//1. Finding the center
	//finding the random farthest node from 1
	dfs(1,0,0);
	int maxNode=1;
	for(int i=1;i<=n;i++){
		if(dist[maxNode]<dist[i]){
			maxNode=i;
		}
	}
	//Now maxNode is the farthest point from 1
	dfs(maxNode,0,0);
	for(int i=1;i<=n;i++){
		if(dist[maxNode]<dist[i]){
			maxNode=i;
		}
	}
	int diameter=dist[maxNode];
	int temp=maxNode;
	int center=0;
	while(temp!=0){
		if(dist[temp]==((diameter+1)/2))center=temp;
		temp=par[temp];
	}
	//found the center
	//1->2->3->4->5->6-7
	// cout<<diameter<<nline;
	// cout<<center<<nline;
	if(diameter&1){
		int center2=par[center];
		cnt=0;
		d=(diameter)/2;
		par.assign(n+1,0);
		dist.assign(n+1,0);
		dfs(center,center2,0);
		int count1=cnt;
		cnt=0;
		par.assign(n+1,0);
		dist.assign(n+1,0);
		dfs(center2,center,0);
		int count2=cnt;
		cout<<count1*count2<<nline;
		// cout<<count1<<" "<<count2<<nline;
	}else{
		vector<int>sol;
		par.assign(n+1,0);
		dist.assign(n+1,0);
		for(auto nbrs:g[center]){
			cnt=0;
			d=((diameter/2)-1);
			dfs(nbrs,center,0);
			sol.push_back(cnt);
		}
		int ans=0;
		int sum=0;
		for(auto v:sol){
			ans+=v*v;
			sum+=v;
		}
		cout<<(sum*sum-ans)/2<<nline;
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