#include <bits/stdc++.h>
using namespace std;
int maxi=0;
struct node
{
	int endmark;
	node *next[3];
	node()
	{
		endmark=0;
		for(int i=0;i<2;i++) next[i]=NULL;
	}
}*root;

void insert(string str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
		curr->endmark+=1;
		if(((curr->endmark)*(i+1))>maxi)
            maxi=((curr->endmark)*(i+1));
	}


}
void del(node *cur)
{
      for(int i=0;i<2;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;


         delete(cur) ;
}
int main(){
    int test,n;
    string A[100001];
    cin>>test;
    for(int t=1;t<=test;t++) {
            maxi=0;
	root=new node();
	int num_word;
	cin>>num_word;
	for(int i=0;i<num_word;i++)
	{
		cin>>A[i];
		insert(A[i],A[i].size());
	}
cout<<maxi<<endl;
	del(root);
    }
	return 0;
}
