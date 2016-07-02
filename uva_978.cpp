    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
    int power;
    long b,sb,sg;
    vector<int> blue_lemmings,green_lemmings;
    vector<int>::iterator it;
    scanf("%ld %ld %ld",&b,&sg,&sb);
    
    while(sg--)
    {
    scanf("%d",&power);
    green_lemmings.push_back(power);
    }
    sort(green_lemmings.begin(),green_lemmings.end());
    
    while(sb--)
    {
    scanf("%d",&power);
    blue_lemmings.push_back(power);
    }
    sort(blue_lemmings.begin(),blue_lemmings.end());
     
    while(!blue_lemmings.empty() && !green_lemmings.empty())
    {
    vector<int> blue_surv,green_surv;
	int j=b;
    while(j--)
    {
    if(blue_lemmings.back() > green_lemmings.back()) blue_surv.push_back(blue_lemmings.back() - green_lemmings.back());
    else if(blue_lemmings.back() < green_lemmings.back()) green_surv.push_back(green_lemmings.back()-blue_lemmings.back());
    blue_lemmings.pop_back();
    green_lemmings.pop_back();
    if(blue_lemmings.empty() || green_lemmings.empty()) break;
    }
    sort(blue_surv.begin(),blue_surv.end());
    sort(green_surv.begin(),green_surv.end());
    it=blue_lemmings.end();
    blue_lemmings.insert(it,blue_surv.begin(),blue_surv.end());
    inplace_merge(blue_lemmings.begin(),it,blue_lemmings.end());
    it=green_lemmings.end();
    green_lemmings.insert(it,green_surv.begin(),green_surv.end());
    inplace_merge(green_lemmings.begin(),it,green_lemmings.end());
    
    
    }
    
    if(!blue_lemmings.empty())
    {
    printf("blue wins\n");
    vector<int>::reverse_iterator rit=blue_lemmings.rbegin();
    while(rit != blue_lemmings.rend()) printf("%d\n",*rit++);
    }
    
    else if(!green_lemmings.empty())
    {
    printf("green wins\n");
    vector<int>::reverse_iterator rit=green_lemmings.rbegin();
    while(rit != green_lemmings.rend()) printf("%d\n",*rit++);
    }
    else printf("green and blue died\n");
    if(tc)printf("\n");
    }
     
    return 0;
    }
