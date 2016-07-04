#include<bits/stdc++.h>
using namespace std;

int main()
{

    int m,n,num,a,b;
    string str1,str2;
    while(scanf("%d %d",&m,&n)==2)
    {
        getchar();
        vector<vector<pair<int,int> > > transpose(n,vector<pair<int,int> >());
        for(int i=0; i<m; i++)
        {
            getline(cin,str1);
            getline(cin,str2);
            stringstream ss1(str1),ss2(str2);
            ss1>>num;
            for(int ii=0; ii<num; ii++)
            {
                ss1>>a;
                ss2>>b;
                transpose[a-1].push_back(make_pair(i,b));
            }
        }
        printf("%d %d\n",n,m);
        for(int i=0; i<n; i++)
        {
            printf("%d",transpose[i].size());
            for(int ii=0; ii<transpose[i].size(); ii++) printf(" %d",transpose[i][ii].first+1);
            printf("\n");
            for(int ii=0; ii<transpose[i].size(); ii++)
            {
                printf("%d",transpose[i][ii].second);
                if(transpose[i].size()-ii-1)printf(" ");
            }
            printf("\n");
        }

    }

    return 0;
}
