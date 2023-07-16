#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
struct UnionFind{
	int n,setSize;
	vector<int>rank;
	vector<int>parent;
	UnionFind(){};
	UnionFind(int a){
		n=setSize=a;
		rank.resize(n);
		parent.resize(n);
		for(int i=0;i<n;i++){
			parent[i]=i;
			rank[i]=1;
		}
	}
	int find(int x){
		if(x!=parent[x])return parent[x]=find(parent[x]);
		return x;
	}
	void merge(int x,int y){
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
	}
};
void solve(){
	int n;cin>>n;
	int q;cin>>q;
	UnionFind s(n);
	while(q--){
		int ch;cin>>ch;
		if(ch==0){
			int x,y;cin>>x>>y;
			s.merge(x,y);
		}else{
			int x,y;cin>>x>>y;
			int ok=(s.find(x)==s.find(y));
			cout<<ok<<nline;
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