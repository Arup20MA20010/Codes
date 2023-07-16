#include <bits/stdc++.h>
using namespace std;

int KthElement(vector<int> &a, vector<int> &b, int k)
{
    int n=a.size();
    int m=b.size();
    //searching in a.
    int hi=n-1;int lo=0;
    int ans1=1e9;
    while(hi>=lo){
        int mid=(hi+lo)/2;
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n), b(m);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    cout << KthElement(a, b, k) << '\n';

    return 0;
}