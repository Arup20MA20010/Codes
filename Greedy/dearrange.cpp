#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	map<int,int>freq;
	int maxFreq=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		freq[x]++;
		maxFreq=max(maxFreq,freq[x]);
	}
	int y=n-maxFreq;
	if(maxFreq>=y){
		cout<<2*y<<nline;
	}else{
		cout<<n<<nline;
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T;cin>>T;
	while(T--)solve();
	return 0;
}