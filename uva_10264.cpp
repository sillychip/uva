#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int dim;
    while(scanf("%d",&dim)!=EOF)
    {
        int w;
        vector<int> weight;
        vector<int> potency;
        int range=1;
        range <<= dim;
        potency.assign(range,0);
        for(int i=0;i<range;i++)
        {
            scanf("%d",&w);
            weight.push_back(w);
        }
        int W=0;
        for(int i=0;i<weight.size();i++)
        {
            w=0;
            int max_potency=0;
            int shifter=1,neighbour;
            for(int j=0;j<dim;j++)
            {
                neighbour = i ^ shifter;
                w += weight[neighbour];
                if(potency[neighbour]>max_potency)max_potency=potency[neighbour];
                shifter <<= 1;
            }
            potency[i]=w;
            if((w+max_potency)>W) W=w+max_potency;
        }
        printf("%d\n",W);
    }
    return 0;
}
