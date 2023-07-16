#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pii pair<int, int>
#define F first
#define S second
#define N 902
bool isprime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int len;
string s;
bool isPrime[N];

int dp[51][2][2][451][451][2];
// vector<int>pos1;
// vector<int>pos2;
// Here, flag keeps account of whether x < y : If x < y, flag = 0, else flag  = 1
int RecBrute(int level, int rt1, int rt2, int sum1, int sum2, int flag)
{
    if (level == len)
    {
        if (sum1< sum2 && isprime(sum1 + sum2) && flag == 0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[level][rt1][rt2][sum1][sum2][flag] != -1)
    {
        return dp[level][rt1][rt2][sum1][sum2][flag];
    }

    // Transitions
    int ans = 0;
    int high_bnd1 = 9;
    int high_bnd2 = 9;

    if (rt1)
    {
        high_bnd1 = s[level] - '0';
    }
    if (rt2)
    {
        high_bnd2 = s[level] - '0';
    }

    for (int i = 0; i <= high_bnd1; i++)
    {
        int new_rt1 = rt1;
        if (i != s[level] - '0')
        {
            new_rt1 = 0;
        }
        for (int j = 0; j <= high_bnd2; j++)
        {
            int new_flag = flag;
            if (flag == 1 && j < i)
            {
                continue;
            }
            if (flag == 1 && j > i)
            {
                new_flag = 0;
            }

            int new_rt2 = rt2;
            if (j != s[level] - '0')
            {
                new_rt2 = 0;
            }
            // pos1.push_back(i);
            // pos2.push_back(j);
            ans+=RecBrute(level+1,new_rt1,new_rt2,sum1+i,sum2+j,new_flag);
            ans%=mod;
            // pos1.pop_back();
            // pos2.pop_back();
        }
    }

    return dp[level][rt1][rt2][sum1][sum2][flag] = ans;
}

void solve()
{
    cin >> s;
    len = s.length();

    memset(dp, -1, sizeof(dp));
    cout << RecBrute(0, 1, 1, 0, 0, 1) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
int t = 1;
 
    while (t--)
    {
        solve();
    }
    return 0;
}