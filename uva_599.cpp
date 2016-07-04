#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc,a,b,c,d;
    char A,B;
    string str;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        int n_tree=0,n_acorn=0;
        vector<int> parent(26,-1);
        vector<vector<int> > tree(26,vector<int>());
        while(getline(cin,str))
        {
            if(str[0]=='*')break;
            sscanf(str.c_str(),"(%c,%c)",&A,&B);
            a=A-'A';
            b=B-'A';
            if(parent[a]==-1)
            {
                parent[a]=a;
                tree[a].push_back(a);
            }
            if(parent[b]==-1)
            {
                parent[b]=b;
                tree[b].push_back(b);
            }
            if(parent[a]==parent[b])continue;
            else if(tree[parent[a]].size()>tree[parent[b]].size())
            {
                c=parent[a];
                d=parent[b];


            }
            else
            {
                c=parent[b];
                d=parent[a];
            }
            for(int i=0; i<tree[d].size(); i++)
            {
                parent[tree[d][i]]=c;
                tree[c].push_back(tree[d][i]);
            }
            tree[d].clear();

        }
        for(int i=0; i<tree.size(); i++) if(!tree.at(i).empty()) n_tree++;
        getline(cin,str);
        for(int i=0; i<str.size(); i+=2)
        {
            if(parent[str[i]-'A']==-1)n_acorn++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n",n_tree,n_acorn);
       // if(tc)printf("\n");
    }

    return 0;
}
