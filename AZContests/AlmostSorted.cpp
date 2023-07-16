#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int x,y,bound;
	cin>>x>>y>>bound;
	int a=x^y;
	for(int i=0;i<=bound;i++){
		if((((x^i)+(y^i))%(a+1))==0)
			cout<<i<<" ";
		cout<<(((x^i)+(y^i))%(a+1))<<nline;
	}
	cout<<"hello"<<nline;
	cout<<nline;
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