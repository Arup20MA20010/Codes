#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int visited[7][7];
string s;
char dir[]={'U','D','L','R'};
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int isValid(int i,int j){
	if(i<0||i>=7||j<0||j>=7||visited[i][j])return 0;
	return 1;
}
int rec(int level,int x,int y){
	//base case
	if(level==s.length()){
		if(x==6&&y==0)return 1;
		else
			return 0;
	}
	//recursive idea
	int ans=0;
	if(s[level]='?'){
		for(int i=0;i<4;i++){
			if(isValid(x+dx[i],y+dy[i])){
				ans+=rec(level+1,x+dx[i],y+dy[i]);
			}
		}
	}else{

		int i;
		for(i=0;i<4;i++){
			if(s[level]==dir[i]){
				break;
			}
		}
		if(isValid(x+dx[i],y+dy[i]))ans=rec(level+1,x+dx[i],y+dy[i]);
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
	cin>>s;
	cout<<rec(0,0,0)<<nline;
	return 0;
}