#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define ff first
#define ss second
int visited[10][10];
bool isValid(int i,int j){
	if(i<0||j<0||i>9||j>9||visited[i][j])return 0;
	return 1;
}
int diagx[]={-1,1,-1,1,2,-2,-2,2};
int diagy[]={-1,-1,1,1,2,-2,2,-2};
int jumpx[]={1,1,-1,-1,2,2,-2,-2};
int jumpy[]={-1,1,-1,1,-2,2,-2,2};
vector<pair<int,int>>sol;
int rec(int x,int y,int count){
	visited[x][y]=1;
	//first going along the x direction
	if(count==1){
		for(auto x:sol){
			cout<<"("<<x.ff<<" "<<x.ss<<")";
		}
		cout<<nline;
		return 1;
	}
	int ans=0;
	for(int dx=-2;dx<=2;dx++){
		if(dx==0)continue;
		int xx=dx+x;
		if(isValid(xx,y)){
			if(abs(dx)==2&&(!visited[xx-(dx/abs(dx))][y]))continue;
			sol.push_back({xx,y});
			ans+=rec(xx,y,count-1);
			sol.pop_back();
		}
	}
	for(int dy=-2;dy<=2;dy++){
		if(dy==0)continue;
		int yy=y+dy;
		if(isValid(x,yy)){
			if(abs(dy)==2&&(!visited[x][yy-(dy/abs(dy))]))continue;
			sol.push_back({x,yy});
			ans+=rec(x,yy,count-1);
			sol.pop_back();
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int xx=x+diagx[i];
			int yy=y+diagy[i];
			if(isValid(xx,yy)){
				sol.push_back({xx,yy});
				ans+=rec(xx,yy,count-1);
				sol.pop_back();
			}
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			int xx=x+jumpx[i];
			int yy=y+jumpy[j];
			int prevX=xx-(abs(jumpx[i])/jumpx[i]);
			int prevY=yy-(abs(jumpy[j])/jumpy[j]);
			if(isValid(xx,yy&&visited[prevX][prevY])){
				sol.push_back({xx,yy});
				ans+=rec(xx,yy,count-1);
				sol.pop_back();
			}
		}
	}
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	int ans1=rec(0,0,n);
	cout<<ans1<<nline;
	int ans2=rec(1,0,n);
	cout<<ans2<<nline;
	int ans3=rec(2,2,n);
	cout<<ans3<<nline;
	cout<<4*ans1+4*ans2+ans3<<nline;
	return 0;
}