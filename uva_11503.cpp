#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent,rank,size;
    int a,b;
public:
    void add(int i)
    {
        parent.push_back(i);
        rank.push_back(0);
        size.push_back(1);
    }
    int find_parent(int i) {return (parent[i]==i)? i : parent[i]=find_parent(parent[i]);}
    int union_set(int i,int j)
    {
        a=find_parent(i);
        b=find_parent(j);
        if(a == b)return size[a];
        else
        {
            if(rank[a]>rank[b])
            {
                parent[b]=a;
                return size[a]+=size[b];
            }
                parent[a]=b;
                if(rank[a]==rank[b])rank[b]++;
                return size[b]+=size[a];
        }

    }
};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int no_friends,f,i=0,a,b;
        string str1,str2;
        char f1[21],f2[21];
        scanf("%d",&f);
        map<string,int>names;
        map<string,int>::iterator it;
        UnionFind uf;
        while(f--)
        {
            scanf("%s %s",f1,f2);
            str1=string(f1);
            str2=string(f2);
            if((it=names.find(str1))==names.end())
            {
                names.insert(make_pair(str1,i));
                uf.add(a=i++);
            }
            else a=it->second;
            if((it=names.find(str2))==names.end())
            {
                names.insert(make_pair(str2,i));
                uf.add(b=i++);
            }
            else b=it->second;

            printf("%d\n",uf.union_set(a,b));
        }
    }
    return 0;

}
