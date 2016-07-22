#include<bits/stdc++.h>
using namespace std;

int row[8],a,b,counter=0;
bool isSafe(int r,int c)
{
    if(r==a || abs(a-r)==abs(b-c))return false;
    for(int i=0; i<c; i++)
        if(row[i]==r || (abs(row[i]-r)==abs(i-c)))return false;
    return true;
}
int backtrack(int c)
{
    if(c==b)backtrack(c+1);
    else if(c==8)
    {
        printf("%2d      %d",++counter,row[0]+1);
        for(int i=1; i<8; i++) printf(" %d",row[i]+1);
        printf("\n");
    }
    else for(int r=0; r<8; r++)
        {
            if(isSafe(r,c))
            {
                row[c]=r;
                backtrack(c+1);
            }
        }
    return 0;
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    getchar();
    while(tc--)
    {
        scanf("%d %d",&a,&b);
        getchar();
        a--;
        b--;
        counter=0;
        memset(row,0,sizeof row);
        row[b]=a;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n");
        printf("\n");
        backtrack(0);
        if(tc)printf("\n");
    }
    return 0;
}
