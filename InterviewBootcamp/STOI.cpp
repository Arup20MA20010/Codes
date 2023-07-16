#include <bits/stdc++.h>
using namespace std;

struct Response
{
    bool isValid;
    long long int integer;

    Response() : isValid(true), integer(0) {}
    Response(bool isValid, long long int integer) : isValid(isValid), integer(integer){};
};

Response STOI(string s)
{
    Response ans;
    int sign=1;
    if(s=="+"||s=="-"){
        ans.isValid=false;
        return ans;
    }
    if(s[0]=='-')sign*=-1;
    else if(s[0]=='+')sign=1;
    else if(s[0]<='9'&&s[0]>='0')ans.integer=(s[0]-'0');
    else
        ans.isValid=false;
    if(!ans.isValid){
        return ans;
    }
    for(int i=1;i<s.length();i++){
        if(s[i]<'0'||s[i]>'9'){
            ans.isValid=false;
            return ans;
        }
        ans.integer=ans.integer*10+(s[i]-'0');
    }
    ans.integer*=sign;
    return ans;
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
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string s;
        cin >> s;

        Response response = STOI(s);

        if (!response.isValid)
            cout << "Invalid\n";
        else
            cout << response.integer << "\n";
    }
}