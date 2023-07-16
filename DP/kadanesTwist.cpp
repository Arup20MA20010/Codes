#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
int kadane(vector<int>&arr){
	int sum=0;
	int maxSum=0;
	int maxVal=-1e18;
	for(auto v:arr){
		if(sum<0)sum=0;
		sum+=v;
		maxSum=max(maxSum,sum);
		maxVal=max(maxVal,v);
	}
	return (maxSum==0?maxVal:maxSum);
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n+1);
	int maxSum=-1e18;
	vector<int>fullSum(n+1,0);
	vector<int>rightSum(n+1,0);
	vector<int>leftSum(n+1,0);
	for(int i=1;i<=n;i++){
		int l;cin>>l;
		arr[i].resize(l);
		for(int j=0;j<l;j++){
			cin>>arr[i][j];
			fullSum[i]+=arr[i][j];
			leftSum[i]=max(leftSum[i],fullSum[i]);
		}
		int sum=0;
		for(int j=l-1;j>0;j--){
			sum+=arr[i][j];
			rightSum[i]=max(sum,rightSum[i]);
		}
		maxSum=max(maxSum,kadane(arr[i]));
	}
	int maxVal=maxSum;
	int sum=0;
	while(m--){
		int x;cin>>x;
		maxSum=max(maxSum,sum+leftSum[x]);//ending at that index
		if(sum+fullSum[x]<rightSum[x]){//starting from index x;
			sum=rightSum[x];
		}else{
			sum+=fullSum[x];
		}
		maxSum=max(maxSum,sum);
	}
	cout<<(maxSum==0?maxVal:maxSum)<<nline;
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