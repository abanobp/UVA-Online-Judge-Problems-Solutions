#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
#include<map>
#include<stack>
#include<sstream>
#include<queue>
#include<list>
#define INF  -10000000000007
using namespace std;
long long  MX  , S , D ;
vector<long long > v ;
void coun (int m ,int p, long long sum , long long tot)
{

    if (m > 5)
    {
        if ( sum >= 0 )
          return ;
        sum -=  v[p] ;
        p++ ;
    }
     if (m == 13){
      MX =   max(MX , tot) ;
      return ;
    }
    v.push_back(S);
    coun (m + 1 , p , sum + S , tot + S) ;
    v.pop_back();
    v.push_back(-D);
    coun (m + 1 , p , sum - D , tot - D) ;
    v.pop_back();
}

int main()
{
             // freopen("in.txt","r",stdin);
         // freopen("out.txt","w",stdout);

    while (scanf("%I64d%I64d",&S,&D) != EOF)
    {
        MX = INF ;
        coun(1 , 0 , 0 , 0 ) ;

        if (MX < 0 )
            printf("Deficit\n");
        else
           printf("%lld\n",MX);
    }
}
