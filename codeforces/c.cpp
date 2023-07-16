#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using ii=pair<int,pair<int,int>>;
#define ff first
#define ss second
int present[200100];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		present[i]=0;
	}
	present[1]=1;
	
	multiset<ii>mt;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		mt.insert({i,{a,b}});
	}
	int ans=0;
	while(!mt.empty()){
		auto it=mt.begin();
		// cout<<"before"<<nline;
		// for(auto v:mt){
		// 	cout<<v.ff<<" "<<"("<<v.ss.ff<<" "<<v.ss.ss<<")"<<nline;
		// }
		while(it!=mt.end()){
			ii entry=*it;
			if(present[entry.ss.ff]|present[entry.ss.ss]){
				auto it1=it;
				it++;
				present[entry.ss.ff]=1;
				present[entry.ss.ss]=1;
				mt.erase(mt.find(entry));
			}else{
				it++;
			}
		}
	// 	cout<<"after"<<nline;
	// 	for(auto v:mt){
	// 		cout<<v.ff<<" "<<"("<<v.ss.ff<<" "<<v.ss.ss<<")"<<nline;
	// 	}
	// 	for(int i=1;i<=n;i++){
	// 		cout<<present[i]<<" ";
	// 	}
	// 	cout<<nline;
		ans++;
	}
	cout<<ans<<nline;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}