#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int arr[101][101][11];
void solve(){
	int n,q,c;
	cin>>n>>q>>c;
	int xlow=101,ylow=101,xhigh=-1,yhigh=-1;
	set<pair<int,int>>st;
	for(int i=0;i<n;i++){
		int x,y,s;
		cin>>x>>y>>s;
		xlow=min(xlow,x);
		ylow=min(ylow,y);
		xhigh=max(xhigh,x);
		yhigh=max(yhigh,y);
		if(st.find({x,y})!=st.end()){
			for(int m=0;m<=10;m++){
				arr[x][y][m]+=(s+m)%(c+1);
			}
		}else{
			st.insert({x,y});
			for(int m=0;m<=10;m++){
				arr[x][y][m]+=(s+m)%(c+1);
			}
		}
		
	}
	for(int m=0;m<=10;m++){
		for(int row=xlow;row<=xhigh;row++){
			for(int col=ylow;col<=yhigh;col++){
				if(st.find({row,col})!=st.end())continue;
				arr[row][col][m]=0;
			}
		}
	}
	//row wise sum
	for(int m=0;m<=10;m++){
		for(int row=xlow;row<=xhigh;row++){
			for(int col=ylow+1;col<=yhigh;col++){
				arr[row][col][m]+=arr[row][col-1][m];
			}
		}
	}
	//col wise sum
	for(int m=0;m<=10;m++){
		for(int col=ylow;col<=yhigh;col++){
			for(int row=xlow+1;row<=xhigh;row++){
				arr[row][col][m]+=arr[row-1][col][m];
			}
		}
	}
	while(q--){
		int m;cin>>m;
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		x1=max(xlow,x1);
		y1=max(ylow,y1);
		x2=min(xhigh,x2);
		y2=min(yhigh,y2);
		int z=m%(c+1);
		int ans=arr[x2][y2][z]-(x1-1>=xlow?arr[x1-1][y2][z]:0)-(y1-1>=ylow?arr[x2][y1-1][z]:0)+((x1-1>=xlow)&&(y1-1>=ylow)?arr[x1-1][y1-1][z]:0);
		cout<<ans<<nline;
	}

}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--){
		solve();	
	}
	return 0;
}