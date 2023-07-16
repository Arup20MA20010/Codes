#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<string>s;
int m,n;

int rec(int x1,int y1,int x2){
	int y2=(m+n)-(x1+y1+x2)-2;
	//base case
}
void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
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