#include<bits/stdc++.h>
using namespace std;
#define nline '\n'
#define int long long
vector<int>kmp(string s){
	int n=s.length();
	vector<int>res(n+1);
	res[0]=-1;
	int i=0,j=-1;
	while(i<n){
		while(j!=-1&&s[i]!=s[j]){
			j=res[j];
		}
		i++;
		j++;
		res[i]=j;
	}
	return res;
}
void solve(){
	string P,T;cin>>P>>T;
	string res=P+'$'+T;
	vector<int>kmpArr=kmp(res);
	vector<int>ans;
	for(int i=0;i<res.length();i++){
		if(kmpArr[i+1]==P.length()){
			ans.push_back(i-P.length()*2);
		}
	}
	for(auto x:kmpArr){
		cout<<x<<" ";
	}
	cout<<nline;
	for(auto x:ans)cout<<x<<" ";
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