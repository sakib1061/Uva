/***********************************\
        BOXTROLL
        Sakibhossain.nstu@gmail.com
/************************************/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pai(A) pair<int,int>A
#define mkp(x,y) make_pair(x,y)
#define ll long long int
#define ull unsigned long long int
#define re(x) return x
#define repa(i,j) for(int i=1;i<=j;i++)
#define rep(i,j) for(int i=0;i<j;i++)
#define pob pop_back()
#define per(i,j) for(int i=j;i>=0;i--)
#define po(i,j) pow(i+0.0,j)
#define pb(x) push_back(x)
#define ppb(x,y) push_back(pair<int, int>(x,y))
#define pf printf
#define sf scanf
#define all(x) x.begin(), x.end()
#define clr(x) x.erase(all(x))
#define sum(x) accumulate(all(x),0)
#define vi(x) vector<int>x
#define vs(x) vector<string>x
#define vp(x) vector< pair<int,int> >x
#define ca(x) pf("Case %d: ",x)
#define ok pf("ok\n")
#define SET(x) memset(x, 0, sizeof(x))
#define CLR(x) memset(x, -1, sizeof(x))
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 100000000
template <class T> T Max(T a, T b) { return a>b?a:b;}
template <class T> T Min(T a, T b) { return a<b?a:b;}
bool stb(const string &a,const string &b) ///sorting from small to big size///
{
    return a.size()<b.size();
}
bool bts(const string &a,const string &b)  ///sorting from big to small size///
{
    return a.size()>b.size();
}
bool pas(const pair< int,int > &a,const pair <int,int> &b) ///Sort by Second elements of Pair ///
{
    return a.ss<b.ss;
}
const long int inf=2000000000;
long int Sequence[MAX],L[MAX],I[MAX+1];
long int lis(long int n)
{
     long int i=0;
     I[i++]=-inf;
     for(i=1;i<=n;i++)
     I[i]=inf;
     long int lislength=0;
     i=0;
     for(i=0;i<n;i++)
     {
         long int low,mid,high;
         low=0;
         high=lislength;
         while(low<=high)
         {
             mid=(high+low)/2;
             if(I[mid]<=Sequence[i])
                low=mid+1;
             else
                high=mid-1;
         }
         I[low]=Sequence[i];
         if(lislength<low)
            lislength=low;
     }
      return lislength;
}
///Main Code Starting From Here///
int main()
{
long int n,t=0,i,j;
while(1)
{
    i=0;t++;
    scanf("%ld",&n);
    if(n==-1)
        break;
    Sequence[i++]=n;

    while(scanf("%ld",&n) && n!=-1)
    {
        Sequence[i++]=n;
    }
    ///Now we can solve the problem by LDS  ,here i used LIS thus i reversed the Array
    reverse(Sequence,Sequence+i);
    if(t!=1)
        cout<<endl;
    printf("Test #%ld:\n  maximum possible interceptions: %ld\n",t,lis(i));
}
return 0;
}
///Never Give Up///
