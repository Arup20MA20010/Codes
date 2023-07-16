#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
void solve(){
	int n;cin>>n;
	int h[n];
	int level[n];
	int leftIndex[n];
	int rightIndex[n];
	for(int i=0;i<n;i++){
		cin>>h[i];
		leftIndex[i]=i-1;
		rightIndex[i]=i+1;
	}
	//selecting the leftIndex
	for(int i=0;i<n;i++){
		while(leftIndex[i]>=0&&h[i]>h[leftIndex[i]]){
			leftIndex[i]=leftIndex[leftIndex[i]];
		}
	}
	//selecting the right Index
	for(int i=n-1;i>=0;i--){
		while(rightIndex[i]<n&&h[rightIndex[i]]<h[i]){
			rightIndex[i]=rightIndex[rightIndex[i]];
		}
	}
	int i=0;
	while(i<n){
		level[i]=h[i];
		if(rightIndex[i]<n){
			for(int j=i+1;j<rightIndex[i];j++){
				level[j]=h[i];
			}
			i=rightIndex[i];
		}else{
			i++;
		}
	}
	i=n-1;
	while(i>=0){
		level[i]=max(h[i],level[i]);
		if(leftIndex[i]>=0){
			for(int j=i-1;j>leftIndex[i];j--){
				level[j]=max(level[j],h[i]);
			}
			i=leftIndex[i];
		}else{
			i--;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=(level[i]-h[i]);
	}
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