#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>g;
vector<int>inTime;
vector<int>loTime;
int timer=0;
vector<int>numSplit;
vector<pair<int,int>>bridges;
vector<int>ArtiPoints;
void dfs(int node,int par){
	timer++;
	inTime[node]=timer;
	loTime[node]=timer;
	bool isArti=0;
	numSplit[node]=1;
	int child=0;
	for(auto nbrs:g[node]){
		if(nbrs==par)continue;
		if(!inTime[nbrs]){
			child++;
			dfs(nbrs,par);
			loTime[node]=min(loTime[node],loTime[nbrs]);
			if(loTime[node]>=inTime[node]]){
				numSplit[node]++;
				isArti=1;
			}else if(loTime[node]>inTime[node]){
				//node->nbrs is a bridge
				bridges.push_back({node,nbrs});
				bridges.push_back({nbrs,node});
			}
		}else{
			loTime[node]=min(loTime[node],inTime[nbrs]);
		}
	}
	//check for root
	if(par==0){
		numSplit[node]=child;
	}
	if((par==0&&child>=2)||(par!=0&&isArti)){
		ArtiPoints.push_back(node);
	}
}
void solve(){

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