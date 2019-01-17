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
      // freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);
   int N , M ;

   while (scanf("%d%d",&N,&M) && N && M)
   {
        vector<int> D (N) , K (M) ;

        for (int i = 0 ; i < N ; i++)
            scanf("%d",&D[i]) ;

        for (int i = 0 ; i < M ; i++)
            scanf("%d",&K[i]) ;
        sort(D.begin(),D.end()) ;
        sort(K.begin() , K.end ()) ;

        int p = 0 ;
        long long  sum  = 0;

        for (int i = 0 ; i < N ; i++)
        {
            bool yes = 0 ;
            for ( p ; p < M ; p++)
            {
                if (D[i] <= K [p])
                {
                    sum += K [p] ;
                    p++;
                    yes = 1;
                    break ;
                }
            }

            if (!yes)
            {
                sum = -1 ;
                break ;
            }
        }

        if (sum == -1)
            printf("Loowater is doomed!\n") ;
        else
            printf("%lld\n", sum) ;
   }

}
