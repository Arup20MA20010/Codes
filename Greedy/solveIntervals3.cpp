#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
using pii=pair<pair<int,int>,int>;
#define ff first
#define ss second
void solve(){
	int n;cin>>n;
	vector<pii>v;
	for(int i=0;i<n;i++){
		int l,r,x;cin>>l>>r>>x;
		v.push_back({{l,0},x});
		v.push_back({{r,2},x});
	}
	int q;cin>>q;
	vector<int>ans(q,-1);
	vector<int>zval(q);
	for(int i=0;i<q;i++){
		int y,z;cin>>y>>z;
		v.push_back({{y,1},i});
		zval[i]=z;
	}
	sort(v.begin(),v.end());
	multiset<int>mt;
	for(int i=0;i<v.size();i++){
		if(v[i].ff.ss==0){
			//starting index
			mt.insert(v[i].ss);
		}else if(v[i].ff.ss==2){
			//ending index
			mt.erase(mt.find(v[i].ss));
		}else{
			//query
			int queryIndex=v[i].ss;
			if(mt.empty()||mt.upper_bound(zval[queryIndex])==mt.begin()){
				ans[queryIndex]=-1;
			}else{
				auto it=mt.upper_bound(zval[queryIndex]);
				it--;ans[queryIndex]=*it;
			}
		}
	}
	// for(auto p:v){
	// 	cout<<"("<<p.ff.ff<<" "<<p.ff.ss<<") "<<p.ss<<nline;
	// }
	for(auto x:ans){
		cout<<x<<nline;
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