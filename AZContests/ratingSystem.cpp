#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	vector<int>arr(n,0);
	multiset<int>mt;
	vector<int>prefix(n,0);
	vector<int>suffix(n,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		prefix[i]=arr[i];
		suffix[i]=arr[i];
		if(i)
			prefix[i]+=prefix[i-1];
	}
	mt.insert(0);
	mt.insert(suffix[n-1]);
	for(int i=n-2;i>=0;i--){
		suffix[i]+=suffix[i+1];
		mt.insert(suffix[i]);
	}
	int kmax=0;
	int maxi=*(mt.rbegin());
	for(int i=0;i<n;i++){
		mt.erase(mt.find(suffix[i]));
		int maxSuffix=*mt.rbegin();
		if(maxi<prefix[i]+maxSuffix){
			maxi=prefix[i]+maxSuffix;
			kmax=prefix[i];
		}
	}
	cout<<kmax<<nline;
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