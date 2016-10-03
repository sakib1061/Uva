#include <bits/stdc++.h>
using namespace std;
int dp[1001][31],cost[1001],weight[1001],n,c;
int func(int i,int w)
{
    if(i==(n+1))
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    int pr=0,pr1=0;
    if((w+weight[i])<=c)
        pr=cost[i]+func(i+1,w+weight[i]);
    pr1=func(i+1,w);
    dp[i][w]=max(pr,pr1);
    return dp[i][w];
}
int main()
{
    int t,g;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {

        scanf("%d",&n);
        for(int j=1;j<=n;j++)
            scanf("%d %d",&cost[j],&weight[j]);
        scanf("%d",&g);
        int m=0;
        for(int j=0;j<g;j++)
        { 
        memset(dp,-1,sizeof(dp));
            scanf("%d",&c);
            m+=func(1,0);
        }
        printf("%d\n",m);
    }
    return 0;
}
