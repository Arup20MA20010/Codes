#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int n;
int arr[100100];
map<int,int>mp;
int limit;
set<int>st[100100];
bool check(int x){
	bool Ok=0;
	vector<int>sums;
	for(auto sum:mp){
		if(sum.second>=(n/2-x)){
			Ok=1;
			sums.push_back(sum.first);
		}
	}
	for(auto sum:sums){
		for(int i=0;i<n/2;i++){
			if(arr[i]+arr[n-i-1])
		}
	}
}
void solve(){

}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}