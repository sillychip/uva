    #include<bits/stdc++.h>
    using namespace std;
    
    class Compare
    {
    public:
    bool operator()(pair<long,pair<int,int> > lhs,pair<long,pair<int,int> >rhs){
    if(lhs.first == rhs.first) return (lhs.second.first>rhs.second.first);
    return lhs.first>rhs.first;
    }
    
    };
     
    int main()
    {
    string str;
    int q_num,period,k;
   	priority_queue< pair<long,pair<int,int> >,vector<pair<long,pair<int,int> > >,Compare> queries;
   	while(getline(cin,str))
   	{
   	if(str[0]=='#') break;
   	sscanf(str.c_str(),"%*[^ ]%d %d",&q_num,&period);
   	queries.push(make_pair(long(period),make_pair(q_num,period)));
   	}
   	
   	scanf("%d",&k);
   	
   	while(k--)
   	{
   	printf("%d\n",queries.top().second.first);
   	queries.push(make_pair(queries.top().first+queries.top().second.second,make_pair(queries.top().second.first,queries.top().second.second)));
   	queries.pop();
   	}
     
     
    return 0;
    }