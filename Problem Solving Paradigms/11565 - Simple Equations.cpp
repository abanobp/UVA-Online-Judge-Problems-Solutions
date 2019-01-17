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
         // freopen("in.txt","r",stdin);
         //freopen("out.txt","w",stdout);
    int N ;

    scanf("%d",&N) ;

    while (N--)
    {
        int a ,b ,c ;

        scanf("%d%d%d",&a,&b,&c) ;
        int i = -100 , j  , k  ,yes = 0 ;
        for ( i = -100 ;  i <= 100 && !yes ; i++ )
        {
            for ( j = i + 1;  j <=  100 && !yes; j++)
            {
                for ( k = j + 1 ; k  <=  100 && !yes ; k++ )
                {
                    if (i + j + k == a )
                    {
                        if (i * j * k == b)
                        {
                            if (k * k + j * j + i * i == c)
                                yes = 1 ;
                        }
                    }
                }
            }
        }

        if (yes)
            printf("%d %d %d\n",i-1,j-1,k-1) ;
        else
            printf("No solution.\n");
    }

}
