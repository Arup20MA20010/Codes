#include <bits/stdc++.h>
using namespace std;

void MovingZeros(vector <int>& nums) {
    int i=0;int j=0;
    int n=nums.size();
    while(i<n&&j<n){
        while(j<n&&nums[j]==0){
            j++;
        }
        if(j<n&&nums[i]==0){
            swap(nums[i],nums[j]);
        }
        i++;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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