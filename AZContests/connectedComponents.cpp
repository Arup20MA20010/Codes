#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<vector<int>>mat;
int n,m;
bool isValid(int x,int y){
	if(x<0||y<0||x>=n||y>=m||mat[x][y]==1)return 0;
	return 1;
}
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
vector<vector<int>>visited;
void dfs(int x,int y,int components){
	visited[x][y]=components;
	//going through all the neighbours
	// cout<<x<<" "<<y<<" "<<components<<nline;
	for(int dir=0;dir<4;dir++){
		int xx=x+dx[dir];
		int yy=y+dy[dir];
		// cout<<xx<<" "<<yy<<" "<<isValid(xx,yy)<<nline;
		// if(visited[xx][yy]!=0)continue;
		if(isValid(xx,yy)&&visited[xx][yy]==0){
			// cout<<xx<<" "<<yy<<nline;
			dfs(xx,yy,components);
		}
	}
}
void solve(){
	cin>>n>>m;
	mat.assign(n,vector<int>(m,0));
	visited.assign(n,vector<int>(m,0));
	vector<int>cmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	cmp.assign(n*m+1,0);
	int comp=0;
	// dfs(0,1,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]==0&&mat[i][j]==0){
				comp++;
				// cout<<comp<<nline;
				dfs(i,j,comp);
			}
			cmp[visited[i][j]]++;
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<visited[i][j]<<" ";
	// 		// cout<<cmp[visited[i][j]]<<"  ";
	// 	}
	// 	cout<<nline;
	// }
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==0&&cmp[visited[i][j]]!=1){
				mat[i][j]=cmp[visited[i][j]];
			}
			cout<<mat[i][j]<<" ";
		}
		cout<<nline;
	}
	mat.clear();
	visited.clear();
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