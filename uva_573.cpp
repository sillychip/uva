#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int h,d;
    float u,f;
    while((scanf("%d %f %d %f",&h,&u,&d,&f))==4,h>0)
    {
        f=f*u/100;
        float climbed=0;
        int day=0;
        while(climbed>=0)
        {
            climbed+=u;
            day++;
            if(climbed>h)break;
            climbed-=d;
            u-=f;
            if(u<0)u=0;
        }
        if(climbed>h)printf("success on day %d\n",day);
        else printf("failure on day %d\n",day);

    }
    return 0;
}
