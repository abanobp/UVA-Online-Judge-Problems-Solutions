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
#define INF  1000000007
using namespace std;

int main()
{
             freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);
    int T ;

    scanf("%d",&T) ;

    while (T--)
    {
        int N ;
        scanf("%d",&N) ;
        int gr [10][10] ;
        vector<int> v (N) ;
        for (int i = 0 ; i < N ; i++)
        {
            v[i] = i ;
            for (int j = 0 ;j < N ;j++)
                scanf("%d",&gr[i][j]) ;
        }


        int MX = INF ;

        do
        {
            vector<bool> yes (N , 0) ;
            int sum = 0 ;
           for (int i = 0 ; i < N ; i++)
           {
              // cout << v[i] << "\n" ;
               int p , M = INF;
               for (int j = 0 ; j < N ; j++ )
               {
                   if (!yes [j] )
                   {
                       if ( M  > gr [v[i]][j] ){
                       M =  gr [v[i]][j];
                       p = j ;
                       }
                   }
               }

               yes [p] = 1 ;
               sum += gr [v[i]][p] ;
           }
         //  cout << sum << " s \n";
           // cout << sum << "\n" ;
           MX = min(MX , sum) ;
        }while(next_permutation(v.begin(),v.end()));

        printf("%d\n",MX) ;
    }

}
