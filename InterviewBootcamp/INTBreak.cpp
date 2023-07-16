#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int mulMod(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}
int binPow(int x,int p){
    int ans=1;
    while(p){
        if(p&1){
            ans=mulMod(ans,x);
        }
        x=mulMod(x,x);
        p>>=1;
    }
    return ans;
}
int findMaxProd(int n)
{
    //add code here
    if(n==2){
        return 1;
    }else if(n==3){
        return 2;
    }else if(n==4){
        return 4;
    }
    int r=n%3;
    int cnt=n/3;
    if(r==1){
        return mulMod(binPow(3,cnt-1),4);
    }else if(r==2){
        return mulMod(binPow(3,cnt),2);
    }else{
        return binPow(3,cnt);
    }
}
#undef int 
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
        cout << findMaxProd(n) << '\n';
    }
    return 0;
}