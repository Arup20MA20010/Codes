#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int prev=(n&1);
    int ans=0;
    int numCount=(n&1)+1;
    // cout<<numCount<<endl;
    for(int i=1;i<32;i++){
        ans=prev+(numCount+i*(1<<(i-1)))*((n>>i)&1);
        numCount=numCount+(1<<i)*((n>>i)&1);
        prev=ans;
    }
    return ans;
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countSetBits(n) << '\n';
    }

    return 0;
}