#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int mat[1001][1001];
int n;
bool isValid(int x,int y){
	if(x<0||y<0||x>=n||y>=n)return false;
	return true;
}
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,-2,2,1,-1,1,-1};
void solve(){
	cin>>n;
	vector<vector<int>>dist(n,vector<int>(n,1e18));
	int sr,sc,er,ec;
	cin>>sr>>sc>>er>>ec;
	queue<pair<int,int>>q;
	q.push({sr,sc});
	dist[sr][sc]=0;
	vector<vector<int>>visited(n,vector<int>(n,0));
	while(!q.empty()){
		pair<int,int>curr=q.front();
		q.pop();
		int x=curr.first;
		int y=curr.second;
		visited[x][y]=1;
		for(int dir=0;dir<8;dir++){
			int xx=x+dx[dir];
			int yy=y+dy[dir];
			if(isValid(xx,yy)&&(1-visited[xx][yy])&&dist[xx][yy]>dist[x][y]+1){
				dist[xx][yy]=dist[x][y]+1;
				q.push({xx,yy});
			}
		}
	}
	int ans=dist[er][ec];
	cout<<(ans!=1e18?ans:-1)<<nline;
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