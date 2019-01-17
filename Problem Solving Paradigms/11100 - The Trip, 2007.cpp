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
#include<iomanip>
#define INF  1000000007
using namespace std;

int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    int N ;
    bool f = 0 ;
    while (scanf("%d",&N)  && N )
    {
        if (f)
            printf("\n") ;
        f = 1 ;
        vector<int> v (N) ;
        int MX = 0 , TOT = 0 ;
        for (int i = 0 ; i < N ; i++)
            scanf("%d",&v[i]) ;

     sort(v.begin() , v.end()) ;
     int las = 0 ;
     for (int i = 0 ; i < N ; i++)
     {
        if (las != v[i])
            MX = max( MX , TOT) , TOT = 1 ;
        else
            TOT++ ;
        las = v[i] ;
     }

      MX = max( MX , TOT) ;

     printf("%d\n", MX) ;

     for (int i = 0 ; i < MX ; i++)
     {
         for (int j = i ; j < N ; j += MX )
            if (j != i)
                printf(" %d",v[j]);
            else
                printf("%d" ,v[j]) ;
        printf("\n") ;
     }
    }
}
