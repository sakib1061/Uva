#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
stack<char>C;
int t,l;
char c,s[130];
cin>>t;  
getchar();
for(int i=0;i<t;i++)
{

    gets(s);
    l=strlen(s);
    if(l%2)
    {
        cout<<"No"<<endl;
    }
    else
    {
        bool f=1;
        for(int j=0;j<l;j++)
        {
            if(s[j]=='[' || s[j]=='(')
            {
                C.push(s[j]);
            }
            else
            {
                if(C.size()==0)
                    f=0;
                else if(s[j]==')')
                {
                    if(C.top()=='(')
                    {
                        C.pop();
                    }
                    else
                    {
                        f=0;
                    }
                }
                else if(s[j]==']')
                {
                    if(C.top()=='[')
                    {
                        C.pop();
                    }
                    else
                    {
                        f=0;
                    }
                }
            }
            if(f==0)
                break;
        }
         if(C.size()!=0)
         f=0;

         if(s[0]=='\0')
            f=1;
        if(f)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    C=stack<char>();
}
return 0;
}
