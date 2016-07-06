#include<bits/stdc++.h>
using namespace std;
class UnionFind
{
private:
    vector<int> parent,set_rank;
    int numSet=0,numUnion=0;
public:
    UnionFind(int N)
    {
        set_rank.assign(N,0);
        parent.assign(N,-1);
    }
    int findSet(int i)
    {
        return (parent[i]==-1)? -1 : findset(i);
    }
    int findset(int i)
    {
        return (parent[i]==i)? i : (parent[i]=findset(parent[i]));
    }
    void unionSet(int i,int j)
    {
        int a,b;
        a=findSet(i);
        if(a==-1)
        {
            a=parent[i]=i;
            numSet++;

        }
        b=findSet(j);
        if(b==-1)
        {
            b=parent[j]=j;
            numSet++;
        }
        if(a != b)
        {
            numUnion++;
            if(set_rank[a]<set_rank[b]) parent[a]=parent[b];
            else
            {
                parent[b]=parent[a];
                if(set_rank[a]==set_rank[b]) set_rank[a]++;
            }

        }
    }
    int numTree()
    {
        return numSet-numUnion;
    }
    int numTotal()
    {
        return numSet;
    }
};


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int tc,a,b;
    char A,B;
    string str;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        UnionFind data(26);
        while(getline(cin,str))
        {
            if(str[0]=='*')break;
            sscanf(str.c_str(),"(%c,%c)",&A,&B);
            a=A-'A';
            b=B-'A';
            data.unionSet(a,b);
        }
        getline(cin,str);
        int acorn=str.size()+1; acorn >>= 1;
        printf("There are %d tree(s) and %d acorn(s).\n",data.numTree(),acorn-data.numTotal());
    }

    return 0;
}

