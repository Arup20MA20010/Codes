#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	map<string,int>mp;
	for(int i=0;i<n;i++){
		string name;cin>>name;
		if(mp.find(name)==mp.end()){
			cout<<"OK"<<nline;
		}else{
			cout<<name<<mp[name]<<nline;
		}
		mp[name]++;
	}
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}