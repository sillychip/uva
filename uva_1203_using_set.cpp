    #include<bits/stdc++.h>
    using namespace std;
    
    int main()
    {
    string str;
    int q_num,period,k;
   	set<pair<long,pair<int,int> > > queries;
   	while(getline(cin,str))
   	{
   	if(str[0]=='#') break;
   	sscanf(str.c_str(),"%*[^ ]%d %d",&q_num,&period);
   	queries.insert(make_pair(long(period),make_pair(q_num,period)));
   	}
   	
   	scanf("%d",&k);
   	
   	while(k--)
   	{
   	printf("%d\n",queries.begin()->second.first);
   	queries.insert(make_pair(queries.begin()->first+queries.begin()->second.second,make_pair(queries.begin()->second.first,queries.begin()->second.second)));
   	queries.erase(queries.begin());
   	}
     
     
    return 0;
    }