#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent,rank;

public:
    UnionFind(int N)
    {
        rank.assign(N,0);
        for(int i=0; i<N; i++) parent.push_back(i);
    }
    bool ifconnected(int i,int j)
    {
        return find_set(i)==find_set(j);
    }
    int find_set(int i)
    {
        return (parent[i]==i)? i : (parent[i]=find_set(parent[i]));
    }
    void union_set(int i,int j)
    {
        if(parent[i]!=parent[j])
        {
            int a=find_set(i),b=find_set(j);
            if(rank[a]<rank[b])parent[a]=b;
            else
            {
                parent[b]=a;
                if(rank[a]==rank[b])rank[a]++;
            }
        }
    }

};


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char ch;
    int tc,a,b,num_computer;
    string str;
    scanf("%d",&tc);
    getchar();
    getchar();
    for(int i=0; i<tc; i++)
    {
        int num_connected=0,num_not_connected=0;
        scanf("%d",&num_computer);
        getchar();
        UnionFind connected(num_computer+1);
        while(getline(cin,str))
        {
            if(str.empty())break;
            sscanf(str.c_str(),"%c %d %d",&ch,&a,&b);
            if(ch=='c') connected.union_set(a,b);
            else
            {
                if(connected.ifconnected(a,b))num_connected++;
                else num_not_connected++;
            }
        }
        if(i)printf("\n");
        printf("%d,%d\n",num_connected,num_not_connected);
    }

    return 0;
}
