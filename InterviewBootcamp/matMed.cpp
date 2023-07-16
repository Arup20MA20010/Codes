#include <bits/stdc++.h>
using namespace std;

int MedianInMatrix(vector<vector<int>> &a)
{
    // Complete the function
    int n=a.size();
    int m=a[0].size();
	vector<int>candi;
	for(int i=0;i<n;i++){
		candi.push_back(a[i][m/2]);
	}
	sort(candi.begin(),candi.end());
	return candi[n/2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << MedianInMatrix(a) << "\n";

    return 0;
}