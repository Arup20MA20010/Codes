#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int isPalindrome[1001][1001];
string s;
bool rec(int i,int j){
	if(i>=j)return 1;
	if(isPalindrome[i][j]!=-1)return isPalindrome[i][j];
	isPalindrome[i][j]=0;
	if(s[i]==s[j]){
		isPalindrome[i][j]=rec(i+1,j-1);		
	}
	if(i<=j&&isPalindrome[i+1][j]==-1){
		isPalindrome[i+1][j]=rec(i+1,j);
	}
	if(i<=j&&isPalindrome[i][j-1]==-1){
		isPalindrome[i][j-1]=rec(i,j-1);
	}
	return isPalindrome[i][j];
}
void solve(){
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			isPalindrome[i][j]=-1;
		}
	}
	rec(0,n-1);
	string ans;
	int len=0;
	int startIdx=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(isPalindrome[i][j]&&len<j-i+1){
				len=j-i+1;
				startIdx=i;
			}
		}
	}
	ans=s.substr(startIdx,len);
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