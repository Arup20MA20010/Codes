#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	pair<int,int>start={0,0};
	string s;cin>>s;
	set<pair<pair<int,int>,pair<int,int>>>st;
	for(auto ch:s){
		pair<int,int>newPos;
		if(ch=='N'){
			newPos={start.first,start.second+1};
			if(newPos>start){
				st.insert({newPos,start});
			}else{
				st.insert({start,newPos});
			}
			start=newPos;
		}else if(ch=='S'){
			newPos={start.first,start.second-1};
			if(newPos>start){
				st.insert({newPos,start});
			}else{
				st.insert({start,newPos});
			}
			start=newPos;
		}else if(ch=='E'){
			newPos={start.first+1,start.second};
			if(newPos>start){
				st.insert({newPos,start});
			}else{
				st.insert({start,newPos});
			}
			start=newPos;
		}else if(ch=='W'){
			newPos={start.first-1,start.second};
			if(newPos>start){
				st.insert({newPos,start});
			}else{
				st.insert({start,newPos});
			}
			start=newPos;
		}
	}
	int ans=s.length()+4*st.size();
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)
		solve();
	return 0;
}