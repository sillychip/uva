    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    int month,num_d,find;
    double down_payment,loan;
    while(scanf("%d %lf %lf %d",&month,&down_payment,&loan,&num_d)==4)
    {
    if(month<0)break;
    double monthly_payment=loan/month;
    double car_value = loan+down_payment;
    double depreciation;
    scanf("%*d %lf",&depreciation); num_d--;
    int month_next=-1;
    double depreciation_next;
    if(num_d--)scanf("%d %lf",&month_next,&depreciation_next);
    for(int i=0;i<=month;i++)
    {
    if(month_next==i){
    depreciation=depreciation_next;
    if(num_d--)scanf("%d %lf",&month_next,&depreciation_next);
    }
    if(i)loan-=monthly_payment;
    car_value *= (1-depreciation);
    if(car_value>loan){find=i;break;}
    }
    while(num_d-->0) scanf("%*d %*f");
    
    if(find==1)printf("1 month\n");
    else printf("%d months\n",find);
    
    }
     
    return 0;
    }