#include <bits/stdc++.h>
using namespace std;

bool isReach(vector<int> jump)
{
	// Complete the function
	int n=jump.size();
    vector<int>dp(n,0);
    dp[n-1]=1;
    int j=-1;
    for(int i=n-1;i>=0;i--){
    	if(jump[i]&&i+jump[i]>j){
    		dp[i]=1;
    	}else{
    		dp[i]=0;
    		j=i;
    	}
    }
    return dp[0];
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
	vector<int> jump(n);
	for (auto &i : jump)
		cin >> i;
	// cout<<"whu"<<endl;
	if (isReach(jump))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}