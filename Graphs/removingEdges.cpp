#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
struct unionFind{
	int n,setSize;
	vector<int>parent;
	vector<int>rank;
	unionFind(int a){
		n=setSize=a;
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
	int n,m,q;cin>>n>>m>>q;
	vector<ii>edgeList;
	edgeList.push_back({-1,-1});
	set<ii>st;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		edgeList.push_back({a,b});
		st.insert({a,b});
	}
	unionFind s(n);
	vector<ii>queries;
	while(q--){
		int ch;cin>>ch;
		if(ch==1){
			int x;cin>>x;
			queries.push_back({1,x});
			if(st.find(edgeList[x])!=st.end()){
				st.erase(edgeList[x]);
			}
		}else{
			queries.push_back({2,0});
		}
	}
	for(auto edge:st){
		s.merge(edge.ff,edge.ss);
	}
	vector<int>ans;
	reverse(queries.begin(),queries.end());
	for(auto query:queries){
		if(query.ff==1){
			int index=query.ss;
			s.merge(edgeList[index].ff,edgeList[index].ss);
		}else{
			ans.push_back(s.setSize);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<x<<nline;
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