#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;cin>>s;
	int n=s.length();
	string temp=s;
	temp+=s;
	string pattern1;
	string pattern2;
	for(int i=0;i<2*n;i++){
		if(i&1){
			pattern1.push_back('w');
			pattern2.push_back('b');
		}else{
			pattern1.push_back('b');
			pattern2.push_back('w');
		}
	}
	vector<int>prefix1(2*n,0);
	vector<int>prefix2(2*n,0);
	for(int i=0;i<2*n;i++){
		prefix1[i]=(temp[i]!=pattern1[i]);
		prefix2[i]=(temp[i]!=pattern2[i]);
		if(i){
			prefix1[i]+=prefix1[i-1];
			prefix2[i]+=prefix2[i-1];
		}
	}
	int cnt=1e18;
	for(int i=0;i<n;i++){
		cnt=min(cnt,prefix1[i+n-1]-(i?prefix1[i-1]:0));
	}
	for(int i=0;i<n;i++){
		cnt=min(cnt,prefix2[i+n-1]-(i?prefix2[i-1]:0));
	}
	cout<<cnt<<nline;
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