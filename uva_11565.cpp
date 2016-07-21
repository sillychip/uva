#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc,A,B,C,cx,cy;
    bool flag;
    scanf("%d",&tc);
    while(tc--)
    {
        flag=false;
        scanf("%d %d %d",&A,&B,&C);
        for(int x=-21; x<22 && !flag; x++)
            if((cx=x*x)<C)for(int y=-100; y<101 && !flag; y++,cy=cx)
                    if((cy+=y*y)<=C && y!=x)for(int z=y; z<101 ; z++)
                            if(z!=x && z!=y && x+y+z==A && x*y*z==B && cy+z*z==C)
                            {
                                printf("%d %d %d\n",x,y,z);
                                flag=true;
                                break;
                            }
        if(!flag)printf("No solution.\n");
    }

    return 0;
}
