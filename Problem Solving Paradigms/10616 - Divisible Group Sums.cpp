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
#include<bitset>
#include<limits.h>
#define INF  100000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define fr first
#define sc second
using namespace std;
int dp [205][25][15] , D ;
int v [205] ;
long long coun (int ix , long long sum , int m)
{
    if (m == 0 && sum % D == 0)
            return 1 ;
    if (ix == -1 || m == 0)
        return 0 ;

    int &ret = dp [ix][sum][m] ;

    if (ret != -1)
       return ret ;
    long long ne_s = (sum + v[ix]) % D ;
    if (ne_s < 0)
        ne_s += D ;
    return ret = coun(ix - 1 , sum ,m) + coun(ix - 1 , ne_s ,m - 1) ;
}

int main()
{
         freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);
    int N , Q , T = 1;
    while (scanf("%d%d" , &N , &Q) && (N || Q))
    {

            for (int i = 0 ; i < N ; i++)
                scanf("%d" , &v[i]) ;

            printf("SET %d:\n",T++) ;
            int TT = 1 ;
            while (Q--)
            {
               memset(dp , -1 ,sizeof dp) ;

               int M ;
               scanf("%d%d" , &D , &M) ;
               if (!D)
               {
                printf("QUERY %d: 0\n" ,TT++) ;
                continue ;
               }
               printf("QUERY %d: %lld\n" ,TT++ , coun(N - 1 , 0 , M)) ;
            }
    }
}
