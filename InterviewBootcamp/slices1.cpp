#include <bits/stdc++.h>
using namespace std;

long long findArithmeticSeq(int arr[], int n)
{
    int head=1;int tail=0;
    long long ans=0;
    while(tail<n){
        while(head+1<n&&(arr[head+1]-arr[head]==arr[tail+1]-arr[tail])){
            head++;
        }
        if(head-tail>=2){
            ans+=(1LL*(head-tail-1));
        }
        if(head-tail<=1){
            tail++;
            head=tail+1;
        }else{
            tail++;
        }
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << findArithmeticSeq(a, n) << '\n';
    return 0;
}