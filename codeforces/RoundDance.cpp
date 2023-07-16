#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
struct UnionFind{
	int n,setSize;
	vector<int>parent;
	vector<int>rank;
	UnionFind(){};
	UnionFind(int n){
		this->n=n;
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
	int arr[n+1];
	UnionFind s(n);
	int complete=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(s.find(i)!=s.find(arr[i])){
			s.merge(i,arr[i]);
		}else{
			if(arr[arr[i]]==i)continue;
			complete++;
		}
	}
	int maxRound=s.setSize;
	// cout<<complete<<nline;
	int minRound=complete+(complete<maxRound);
	cout<<minRound<<" "<<maxRound<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}