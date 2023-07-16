#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int cnt=0;
	int n,k;cin>>n>>k;
	string s;cin>>s;
	vector<int>C(26,0);
	string temp;cin>>temp;
	for(int i=0;i<26;i++){
		C[i]=1-(temp[i]-'0');
	}
	int ans=0;
	int head=-1,tail=0;
	while(tail<n){
		while(head+1<n&&cnt+C[s[head+1]-'a']<=k){
			head++;
			cnt+=C[s[head]-'a'];
		}
		ans=max(ans,head-tail+1);
		if(head>=tail){
			cnt-=C[s[tail]-'a'];
			tail++;
		}else{
			tail++;
			head=tail-1;
			cnt=0;
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
	while(T--){
		solve();
	}
	return 0;
}