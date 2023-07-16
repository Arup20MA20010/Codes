#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int q;cin>>q;
	int arr[n+1];
	set<pair<int,int>>st;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		st.insert({arr[i],i});
	}
	while(q--){
		int ch;cin>>ch;
		if(ch==1){
			int x,y;cin>>x>>y;
			st.erase({arr[x],x});
			arr[x]=y;
			st.insert({arr[x],x});
		}else{
			int k;cin>>k;
			auto it=st.lower_bound({k,0});
			if(it==st.end())cout<<-1<<nline;
			else
				cout<<it->second<<nline;
		}
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