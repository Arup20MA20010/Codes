#include <bits/stdc++.h>
using namespace std;
int indeg[1001];
int outdeg[1001];
int FindCeleb(vector<vector<int>> &a)
{
    // Complete the solution
    int n=a.size();
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(a[i][j]){
                indeg[j]++;
                outdeg[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(indeg[i]==n-1&&outdeg[i]==0){
            return i+1;
        }
    }
    return -1;
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
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << FindCeleb(a) << '\n';
}