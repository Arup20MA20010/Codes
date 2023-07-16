#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	string s;cin>>s;
	int n=s.length();
	int start=0,end=n-1;
	while(start<=end){
		if(s[start]==s[end]){
			start++;
			end--;
		}else{
			break;
		}
	}
	if(start>=end){
		cout<<"Y"<<nline;
		return;
	}
	int s1=start+1,e1=end;
	int s2=start,e2=end-1;
	int flag1=1,flag2=1;
	while(s1<=e1){
		if(s[s1]==s[e1]){
			s1++;e1--;
		}else{
			flag1=0;
			break;
		}
	}
	while(s2<=e2){
		if(s[s2]==s[e2]){
			s2++;
			e2--;
		}else{
			flag2=0;
			break;
		}
	}
	if(flag1||flag2){
		cout<<"Y"<<nline;
	}else{
		cout<<"N"<<nline;
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
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}