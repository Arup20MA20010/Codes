#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using pii=pair<int,pair<int,int>>;
using ii=pair<int,int>;
#define ff first
#define ss second
struct UnionFind{
	int cost,n;
	int setSize;
	vector<int>parent;
	vector<int>rank;
	UnionFind(){};
	UnionFind(int n){
		this->n=n;
		cost=0;
		setSize=n;
		parent.resize(n+1);
		rank.resize(n+1);
		for(int i=1;i<=n;i++){
			parent[i]=i;
			rank[i]=1;
		}
	}
	int find(int x){
		if(x!=parent[x])return parent[x]=find(parent[x]);
		return x;
	}
	void merge(int x,int y,int cost){
		int nodeX=find(x);int nodeY=find(y);
		if(nodeX==nodeY)return;
		if(rank[nodeX]>=rank[nodeY]){
			rank[nodeX]+=rank[nodeY];
			parent[nodeY]=nodeX;
		}else{
			rank[nodeY]+=rank[nodeX];
			parent[nodeX]=nodeY;
		}
		setSize--;
		this->cost+=cost;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	vector<pii>edgeList;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		edgeList.push_back({c,{a,b}});
	}
	sort(edgeList.begin(),edgeList.end());
	UnionFind s(n);
	for(auto edge:edgeList){
		s.merge(edge.ss.ff,edge.ss.ss,edge.ff);
	}
	if(s.setSize==1){
		cout<<s.cost<<nline;
	}else{
		cout<<"IMPOSSIBLE"<<nline;
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