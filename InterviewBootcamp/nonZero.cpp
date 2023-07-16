#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int cnt1=0,cnt2=0;
	bool zeros=0;
	int arr[100100];
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		arr[i]=x;
		if(x==0){
			zeros=1;
			break;
		}
		int temp=x;
		while(temp&&(temp%2==0)){
			cnt1++;
			temp>>=1;
		}
		temp=x;
		while(temp&&(temp%5==0)){
			cnt2++;
			temp/=5;
		}
	}
	if(zeros){
		cout<<-1<<nline;
		return;
	}
	
	int x=min(cnt1,cnt2);
	int y=x;
	int mul=1;
	for(int i=0;i<n;i++){
		while(arr[i]&&x&&arr[i]%2==0){
			arr[i]/=2;
			x--;
		}
		while(arr[i]&&y&&arr[i]%5==0){
			arr[i]/=5;
			y--;
		}
		mul*=(arr[i]%10);
		mul%=10;
	}
	cout<<mul<<nline;
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