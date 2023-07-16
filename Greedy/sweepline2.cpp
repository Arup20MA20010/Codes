#include<bits/stdc++.h>
using namespace std;
#define nline '\n'
#define int long long
using pii=pair<pair<int,int>,int>;
using ii=pair<int,int>;
#define ff first
#define ss second
void solve(){
	int n;cin>>n;
	vector<pii>v;
	for(int i=0;i<n;i++){
		int a,b,z;
		cin>>a>>b>>z;
		v.push_back({{a,0},z});
		v.push_back({{b,2},z});
	}
	int q;cin>>q;
	vector<int>ans(q,-1);
	for(int i=0;i<q;i++){
		v.push_back({{x,1},i});
	}
	v.sort(v.begin(),v.end());
	multiset<int>mt;
	for(int i=0;i<v.size();i++){
		if(v[i].ff.ss==0){
			mt.insert(v[i].ss);
		}else if(v[i].ff.ss==2){
			mt.erase(mt.find(v[i].ss));
		}else{
			if(mt.empty())continue;
			ans[v[i].ss]=*mt.rbegin();
		}
	}
	for(auto x:ans){
		cout<<x<<" ";
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
	solve();
	return 0;
}