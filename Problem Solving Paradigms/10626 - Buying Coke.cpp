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
#define INF  -1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define fr first
#define sc second
using namespace std;
int coin [3] , cok [150] ;
int dp [155][105][55] ;

int sol (int ix , int nf , int nt , int one)
{
    if (ix == 0)
        return 0 ;

    int &res = dp [ix][nf][nt] ;

    if (res != -1)
        return res ;

    res = INT_MAX ;
 //   cout << nf << " " << nt << " " << one << "\n" ;
    if (nt >= 1)
        res = min(res , 1 + sol(ix - 1 , nf , nt - 1, one + 2 )) ;

    if (nf >= 2)
        res = min(res , 2 + sol(ix - 1 , nf - 2 , nt, one + 2 )) ;

    if (nf >= 1 && one >= 3)
        res = min(res , 4 + sol(ix - 1 , nf - 1 , nt, one - 3 ) ) ;
    if (one >= 8)
        res = min(res , 8 + sol(ix - 1 , nf , nt, one - 8 ) ) ;
    if (one >= 3 && nt >= 1)
        res = min(res , 4 + sol(ix - 1 , nf + 1 , nt - 1 , one - 3 ) ) ;
   // cout << ix << " " <<  res << "\n" ;
    return res ;
}

int main()
{
        freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);

    int  T ;

    scanf("%d" , &T) ;

    while (T--)
    {
        int c , n1 , n5 , n10 ;
        scanf("%d%d%d%d" ,&c , &n1 , &n5 , &n10) ;

        memset(dp , -1 ,sizeof dp) ;

        printf("%d\n" , sol(c , n5 , n10 , n1)) ;
    }
}
