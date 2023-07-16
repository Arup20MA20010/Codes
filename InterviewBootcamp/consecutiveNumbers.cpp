#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int freq[100100];
void solve(){
	int n,k;cin>>n>>k;
	set<int>st;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		freq[x]++;
		st.insert(x);
	}
	while(!st.empty()){
		int i=*st.begin();
		for(int j=i;j<=i+k-1;j++){
			if(st.find(j)==st.end()){
				cout<<"No"<<nline;
				return;
			}
			freq[j]--;
			if(freq[j]==0){
				st.erase(j);
			}
		}
	}
	cout<<"Yes"<<nline;
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