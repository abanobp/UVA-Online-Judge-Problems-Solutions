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
int row [10] , test = 1 , x ,y;
vector<bool> R (20,0) , LD (20,0), RD (20,0);
void sol (int col)
{
if (col == 9)
{
    if (test < 10)
        printf(" ") ;
    printf("%d      %d",test++,row[1]);
    for (int i = 2 ; i <= 8 ; i++)
        printf(" %d",row[i]) ;
    printf("\n");
}
    if (col == y )
        sol (col + 1 ) ;
    else
    {
    for (int i = 1 ; i <= 8 ;i++)
    {

         if (!R [i] && !LD [i - col + 8 ] && !RD [i + col])
            {
                R [i] = LD [i - col + 8 ] = RD [i + col] = 1 ;
                row [col] = i ;
                sol(col + 1) ;
                R [i] = LD [i - col + 8 ] = RD [i + col] = 0 ;
            }
    }
    }
}

int main()
{
             freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);

    int T ;
    scanf("%d",&T) ;
    while (T--)
    {
        cin >> x >> y ;
        R [x] = LD [x - y + 8 ] = RD [x + y] = 1 ;
        row [y] = x ;
        test = 1 ;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n") ;
        sol(1) ;
         R [x] = LD [x - y + 8 ] = RD [x + y] = 0 ;
         if (T)
        printf("\n") ;
    }

}
