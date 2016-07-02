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
    multiset<int,greater<int> > blue_lemmings,green_lemmings;
    scanf("%ld %ld %ld",&b,&sg,&sb);
    
    while(sg--)
    {
    scanf("%d",&power);
    green_lemmings.insert(power);
    }
    
    
    while(sb--)
    {
    scanf("%d",&power);
    blue_lemmings.insert(power);
    }
    
    multiset<int>blue_surv,green_surv;
    
    while(!blue_lemmings.empty() && !green_lemmings.empty())
    {

    for(int j=0;j<b;j++)
    {
    if(blue_lemmings.empty() || green_lemmings.empty()) break;
    if(*blue_lemmings.begin() > *green_lemmings.begin()) blue_surv.insert((*blue_lemmings.begin()) - (*green_lemmings.begin()));
    else if(*blue_lemmings.begin() < *green_lemmings.begin()) green_surv.insert((*green_lemmings.begin())-(*blue_lemmings.begin()));
    blue_lemmings.erase(blue_lemmings.begin());
    green_lemmings.erase(green_lemmings.begin());
    }
    
    blue_lemmings.insert(blue_surv.begin(),blue_surv.end());
    green_lemmings.insert(green_surv.begin(),green_surv.end());
    blue_surv.clear();
    green_surv.clear();
    }
    multiset<int>::iterator it;
    if(!blue_lemmings.empty())
    {
    printf("blue wins\n");
    it=blue_lemmings.begin();
    while(it !=blue_lemmings.end()) printf("%d\n",*it++);
    }
    
    else if(!green_lemmings.empty())
    {
    printf("green wins\n");
    it=green_lemmings.begin();
    while(it != green_lemmings.end()) printf("%d\n",*it++);
    }
    else printf("green and blue died\n");
    if(tc)printf("\n");
    }
     
    return 0;
    }