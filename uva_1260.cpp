#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int tc,n;
    int A[1000],B[1000];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
            int j=i;
            B[i]=0;
            while(j--)
            {
                if(A[j]<=A[i]) B[i]++;
            }
            sum+=B[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
