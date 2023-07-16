#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int q,x;cin>>q>>x;
	vector<int>arr(x,0);
	set<int>st;
	for(int i=0;i<=q;i++){
		st.insert(i);
	}
	while(q--){
		int y;cin>>y;
		int num=arr[y%x]*x+y%x;
		arr[y%x]++;
		if(st.find(num)!=st.end())st.erase(st.find(num));
		cout<<*st.begin()<<" ";
	}
	cout<<nline;
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