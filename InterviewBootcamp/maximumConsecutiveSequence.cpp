#include <bits/stdc++.h>
using namespace std;

int LongestConsecutive(vector <int>& nums) {
	set<int>st;
	for(auto x:nums){
		st.insert(x);
	}
	int count=1;int maxCount=1;
	int prev=*st.begin();
	auto it=st.begin();it++;
	for(;it!=st.end();it++){
		if((*it)-prev==1){
			count++;
			maxCount=max(maxCount,count);
		}else{
			count=0;
		}
		prev=*it;
	}
	return maxCount;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	cin >> n;
	vector <int> nums(n);
	for (auto &i : nums)
		cin >> i;
	cout << LongestConsecutive(nums);
}