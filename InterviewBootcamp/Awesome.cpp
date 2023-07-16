#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;cin>>s;
	int n=s.length();
	vector<vector<int>>freq(10,vector<int>(n,0));
	for(int i=0;i<n;i++){
		freq[s[i]-'a'][i]++;
	}
	//first search  for even length
	int lo=0;int hi=n-(n&1);
	int ans1=-1;
	while(hi>=lo){
		int mid=(hi+lo)/2;
		if(check(mid)){
			ans1=mid;
			lo=mid+2;
		}else{
			hi=mid-2;
		}
	}
	//then search for odd length
	lo=1;hi=n-1+(n&1);
	int ans2=-1;
	while(hi>=lo){
		int mid=(hi+lo)/2;
		if(check(mid)){
			ans2=mid;
			lo=mid+2;
		}else{
			hi=mid-2;
		}
	}
	int ans=max(ans1,ans2);
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