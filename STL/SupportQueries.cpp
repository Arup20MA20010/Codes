#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int q,k;cin>>q>>k;
	multiset<int>topK;multiset<int>rest;
	int ch;
	int sum=0;
	while(q--){
		cin>>ch;

		if(ch==1){
			int x;cin>>x;
			topK.insert(x);
			sum+=x;
			if(topK.size()>k){
				int restElement=*topK.begin();
				sum-=restElement;
				rest.insert(restElement);
				topK.erase(topK.find(restElement));
			}
		}else if(ch==2){
			int x;cin>>x;
			if(rest.find(x)!=rest.end()){
				rest.erase(rest.find(x));
			}else if(topK.find(x)!=topK.end()){
				topK.erase(topK.find(x));
				sum-=x;
				auto it=rest.end();
				if(rest.empty())continue;
				it--;
				topK.insert(*it);
				sum+=(*it);
				rest.erase(rest.find(*it));
			}
		}else{
			char c;cin>>c;
			cout<<sum<<nline;
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