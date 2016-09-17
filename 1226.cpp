#include <bits/stdc++.h>
using namespace std;
#define F(n) for(int i=0;i<n;i++)
struct node{
 int endmark;

node *next[129];
node()
{
    endmark=0;
    F(128)
    {
        next[i]=NULL;
    }
}
}*root;
void insert(string S,int Len)
{
    node *curr=root;int id;
    F(Len)
    {
        id=S[i];
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark++;
}
int searchs(string S,int Len)
{
    node *curr=root;int id;
    F(Len)
    {
        id=S[i];
        if(curr->next[id]==NULL)
            return 0;
        curr=curr->next[id];
    }
    return curr->endmark;
}
void dlt(node *curr)
{
    F(128)
    {
        if(curr->next[i])
            dlt(curr->next[i]);
    }
    delete (curr);
}
int main()
{
    int n=0,t;
    char c;
    scanf("%d\n\n", &t);
    F(t) {
        n=0;
    vector<string>A;
    string s;
    set<string>B;
    root=new node();
    while(getline(cin,s))
    {
        if(s[0]=='\0')
            break;
        B.insert(s);
        insert(s,s.size());
        n++;
    }
    set<string> ::iterator it;
    for(it=B.begin();it!=B.end();it++)
        A.push_back(*it);
    int si=A.size();
    F(si)
    {
        int fo=searchs(A[i],A[i].size());
        double q=(fo*100)/(n+0.0);
        cout<<A[i];
        printf(" %.4lf\n",q);
    }
    if(i!=(t-1))
    cout<<endl;
    dlt(root);
    }
    return 0;
}

