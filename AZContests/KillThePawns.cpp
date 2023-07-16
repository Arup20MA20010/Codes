#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,int>;
#define ff first
#define ss second
int dx[]={1,-1,1,-1,2,-2,2,-2};
int dy[]={2,2,-2,-2,1,1,-1,-1};
int isValid(int i,int j){
	if(i<0||j<0||i>=8||j>=8)return 0;
	return 1;
}
vector<vector<int>>visited;
vector<vector<int>>dist;
void bfs(int x,int y){
	queue<pair<int,int>>q;
	q.push({x,y});
	dist[x][y]=0;
	while(!q.empty()){
		par
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