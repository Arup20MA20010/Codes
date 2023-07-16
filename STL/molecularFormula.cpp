#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
bool isParen(char ch){
	if(ch=='('||ch==')')return true;
	return false;
}
bool isNum(char ch){
	if(ch<='9'&&ch>='0')return true;
	return false;
}
bool isCapital(char ch){
	if(ch<='Z'&&ch>='A')return true;
	return false;
}
bool isLower(char ch){
	if(ch<='z'&&ch>='a')return true;
	return false;
}
void solve(){
	string s;cin>>s;
	map<string,int>mp;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(isCapital(s[i])){
			int pos=i;
			for(int j=i+1;j<n;j++){
				if(!isLower(s[j])){
					break;
				}else{
					pos=j;
				}
			}
			if(j+1<n&&isNum(s[j+1])){
				mp[s[i]-'a']
			}
		}
	}
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