#include <bits/stdc++.h>
using namespace std;
long long dp[1001][2001];
int n;
int tar;
const int mod=1e9+7;
vector<int>arr;
long long rec(int level,int sum){
	if(level==n){
		if(sum-1000==tar)return 1;
		return 0;
	}
	if(dp[level][sum]!=-1)return dp[level][sum];
	long long ans=0;
	ans+=(rec(level+1,sum-arr[level])%mod);
	ans%=mod;
	ans+=(rec(level+1,sum+arr[level])%mod);
	ans%=mod;
	return dp[level][sum]=ans;
}
int BuildingtheSum(vector <int>& nums, int target) {
	n=nums.size();
	arr=nums;
	int sum=0;
	for(auto v:nums){
		sum+=abs(v);
	}
	for(int i=0;i<=n;i++){
		for(int j=1000-sum;j<=1000+sum;j++){
			dp[i][j]=-1;
		}
	}
	tar=target;
	return rec(0,1000);	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	cin >> n;
	int target;
	cin >> target;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	cout << BuildingtheSum(nums, target);
}