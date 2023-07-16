#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int freq[26];
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int i=0,j=n-1;
	bool isPalindromic=1;
	int cnt=0;
	while(i<=j){
		if(s[i]==s[j]){
			i++;
			j--;
			continue;
		}
		//find the location of s[j] from i+1.....j
		int loc1=-1;
		for(int k=i+1;k<j;k++){
			if(s[k]==s[j]){
				loc1=k;
				break;
			}
		}
		//find the location of s[i] from i+1....j
		int loc2=-1;
		for(int k=i+1;k<j;k++){
			if(s[k]==s[i]){
				loc2=k;
			}
		}
		if(loc1==-1&&loc2==-1){
			isPalindromic=0;
			break;
		}
		if(loc1>=i&&loc1-i<=j-loc2){
			for(int k=loc1;k>i;k--){
				swap(s[k],s[k-1]);
				cnt++;
			}
		}
		else if(loc2>=i&&(loc1-i>=j-loc2||loc1==-1)){
			for(int k=loc2;k<j;k++){
				swap(s[k],s[k+1]);
				cnt++;
			}
		}
	}
	if(!isPalindromic){
		cout<<-1<<nline;
		return;
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
	while(T--){
		solve();
	}
	return 0;
}