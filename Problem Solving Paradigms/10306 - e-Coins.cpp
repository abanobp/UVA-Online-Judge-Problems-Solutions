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
#define INF  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define fr first
#define sc second
using namespace std;
int dp [44][305][305] , val;
ii con [44] ;

int tot (int x , int y)
{
    return ( x * x ) + ( y * y ) ;
}

int sol (int ix , int x , int y)
{
    if (tot(x , y) == val)
        return 0;

    if (ix == -1 || tot(x , y) > val)
        return 1000000 ;

    int &refo = dp [ix][x][y];

    if ( refo != -1)
        return refo ;

    refo = sol(ix - 1 ,x , y) ;

    refo = min(refo , 1 + sol(ix , x + con [ix].fr , y + con[ix].sc)) ;

    return refo ;
}

int main()
{
      // freopen("in.txt","r",stdin);
      //freopen("out.txt","w",stdout);

    int T ;

    scanf("%d" , &T) ;

    while (T--)
    {
        int N  ;
        scanf("%d%d" , &N , &val) ;

        for (int i = 0 ; i < N ; i++)
            scanf("%d%d" , &con[i].fr , &con[i].sc) ;

        memset(dp , -1 , sizeof dp) ;
        val *= val ;

        int res =  sol(N - 1 , 0 , 0 ) ;

        if (res >= 1000000)
            printf("not possible\n") ;
        else
        printf("%d\n" , res) ;
    }
}
