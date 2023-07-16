#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;cin>>s;
	int n=s.length();
	vector<int>prefix(n,0);
	for(int i=0;i<n;i++){
		prefix[i]=s[i]-'0';
		if(i)
			prefix[i]+=prefix[i-1];
	}
	int head=-1;int tail=0;
	int ans=0;
	while(head<n){
		while(head+1<n&&2*(prefix[head+1]-(tail?prefix[tail-1]:0))<=(head-tail+2)){
			head++;
		}
		if(2*(prefix[head]-(tail?prefix[tail-1]:0))>(head-tail+1))ans++;
		cout<<s.substr(tail,head-tail+1)<<nline;
		if(head>=tail){
			tail++;
		}else{
			tail++;
			head=tail-1;
		}
	}
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
	while(T--)solve();
	return 0;
}