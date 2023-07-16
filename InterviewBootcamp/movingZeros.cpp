#include <bits/stdc++.h>
using namespace std;

void MovingZeros(vector <int>& nums) {
	int n=nums.size();
	int zeroPos=n+1;
	for(int i=0;i<n;i++){
		if(nums[i]!=0&&zeroPos!=n+1){
			swap(nums[i],nums[zeroPos]);
		}else{
			zeroPos=min(zeroPos,i);
		}
	}
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
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	MovingZeros(nums);
	for (auto i : nums)
		cout << i << " ";
}