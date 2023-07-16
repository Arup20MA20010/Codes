#include <bits/stdc++.h>
using namespace std;

int LongestConsecutive(vector <int>& nums) {
	set<int>st;
	for(auto v:nums){
		st.insert(v);
	}
	int ans=1;
	while(!st.empty()){
		int firstElement=*st.begin();
		int i=0;
		while(true){
			if(st.find(firstElement+i)!=st.end()){
				ans=max(ans,(i+1));
				st.erase(firstElement+i);
				i++;
			}else{
				break;
			}
		}
	}
	return ans;
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