#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int m,n;
    long ll,ul,interval;
    while(scanf("%d %d",&m,&n),m|n)
    {
        bool conflict=false;
        bitset<1000000> calender;
        for(int i=0;i<m;i++)
        {
            scanf("%ld %ld",&ll,&ul);
            while(ll<ul && !conflict)
            {
                if(calender.test(ll))conflict=true;
                calender.set(ll++);
            }
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&ll,&ul,&interval);
            while(ll<1000000 && !conflict)
            {
                if(ul>1000000)ul=1000000;
                for(long l=ll;l<ul;l++)
                {
                    if(calender.test(l))conflict=true;
                    calender.set(l);
                }
                ll+=interval;
                ul+=interval;
            }
        }
        if(conflict)printf("CONFLICT\n");
        else printf("NO CONFLICT\n");
    }

    return 0;
}
