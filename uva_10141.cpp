#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc=0,n,p;
    string str;
    while(scanf("%d %d",&n,&p)==2,n>0)
    {
        getchar();
        tc++;
        string proposal;
        float d,price=0;
        int r,best=0;
        for(int i=0;i<n;i++)cin.ignore(81,'\n');
        for(int i=0;i<p;i++)
        {
            getline(cin,str);
            scanf("%f %d",&d,&r);
            getchar();
            if(r>best)
            {
                best=r;
                price=d;
                proposal=str;
            }
            else if(r==best && d<price)
            {
                price=d;
                proposal=str;
            }
            for(int j=0;j<r;j++)cin.ignore(81,'\n');
        }
        if(tc>1)printf("\n");
        printf("RFP #%d\n",tc);
        printf("%s\n",proposal.c_str());
    }
    return 0;
}
