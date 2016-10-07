#include <bits/stdc++.h>
using namespace std;
int coin[]={1,5,10,25,50}; 
int make; 
int dp[6][7490];
int call(int i,int amount)
{
    if(i>=5) { 
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) { return dp[i][amount]; }
    int ret1=0,ret2=0;
    if(amount-coin[i]>=0) { ret1=call(i,amount-coin[i]);}
    ret2=call(i+1,amount); //dont take coin i
    return dp[i][amount]=ret1+ret2;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>make)
    {
        cout<<call(0,make)<<endl;
    }
    return 0;
}
