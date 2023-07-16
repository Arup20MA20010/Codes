#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s1,s2;
	cin>>s1>>s2;
	int carry=0;int sum=0;
	string ans;
	if(s1.length()>s2.length())swap(s1,s2);
	string temp="";
	for(int i=0;i<s2.length()-s1.length();i++){
		temp.push_back('0');
	}
	temp+=s1;
	s1=temp;
	for(int i=s1.length()-1;i>=0;i--){
		int bit1=s1[i]-'0';
		int bit2=s2[i]-'0';
		int x=bit1+bit2+carry;
		if(x==1||x==0){
			char ch=x+'0';
			ans.push_back(ch);
			carry=0;
		}else{
			carry=1;
			char ch=(x&1)+'0';
			ans.push_back(ch);
		}
	}
	if(carry)ans.push_back(carry+'0');
	reverse(ans.begin(),ans.end());
	cout<<ans<<nline;
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