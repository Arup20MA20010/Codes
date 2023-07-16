#include <bits/stdc++.h>
using namespace std;
using ii=pair<int,int>;
#define ff first
#define ss second
int n;
int check(int x,int y){
	if(x<1||x>n||y<1||y>n)return 0;
	return 1;
}
int dx[]={1,-1,1,-1,2,-2,2,-2};
int dy[]={2,2,-2,-2,1,1,-1,-1};
vector<vector<int>>dist;
void bfs(int Sx,int Sy){
	queue<ii>q;
	dist[Sx][Sy]=0;
	q.push({Sx,Sy});
	while(!q.empty()){
		ii curr=q.front();
		q.pop();
		int x=curr.ff;int y=curr.ss;
		for(int dir=0;dir<8;dir++){
			int xx=x+dx[dir];int yy=y+dy[dir];
			if(check(xx,yy)&&dist[xx][yy]>dist[x][y]+1){
				dist[xx][yy]=dist[x][y]+1;
				q.push({xx,yy});
			}
		}
	}
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	n=N;
	dist.assign(N+1,vector<int>(N+1,1e9));
	bfs(Sx,Sy);
	return (dist[Fx][Fy]!=1e9?dist[Fx][Fy]:-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}