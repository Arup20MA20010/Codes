#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
vector<string> reversal(string s){
	vector<string>ans;
	for(int l=1;l<=s.length();l++){
		for(int i=0;i<s.length();i++){
			if(i+l>s.length())continue;
			string res;
			stack<char>helper;
			for(int j=0;j<i;j++){
				res.push_back(s[j]);
			}
			for(int k=i;k<i+l;k++){
				helper.push(s[k]);
			}
			while(!helper.empty()){
				res.push_back(helper.top());
				helper.pop();
			}
			for(int k=i+l;k<s.length();k++){
				res.push_back(s[k]);
			}
			ans.push_back(res);
		}
	}
	return ans;
}
set<string>generate(string s){
	set<string>ans;
	vector<string>reversedStrings=reversal(s);
	for(auto str:reversedStrings){
		vector<string>temp=reversal(str);
		for(auto x:temp){
			ans.insert(x);
		}
	}
	return ans;
}
void solve(){
	string s;string t;
	cin>>s>>t;
	set<string>t1=generate(s);
	set<string>t2=generate(t);
	
	for(auto v:t1){
		if(t2.count(v)){
			cout<<"YES"<<nline;
			return;
		}
	}
	cout<<"NO"<<nline;
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