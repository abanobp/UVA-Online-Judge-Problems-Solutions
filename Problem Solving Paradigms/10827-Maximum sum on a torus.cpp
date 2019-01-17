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
using namespace std;
int war [80][80] ;
int one (int com [] , int N)
{
    int sum = 0 , mx = INT_MIN , neg = INT_MIN ;

    for (int i = 0 ; i < N ;i++)
    {
        sum += com [i] ;
        //cout << com [i] << " " ;
        if (sum < 0)
            sum = 0;
        else
          mx = max (mx , sum) ;

        neg = max(neg ,com [i]) ;
    }
    //cout << "\n" ;
    if (mx >= 0)
        return mx ;

    return neg ;

}

int two (int N)
{
    int mx = INT_MIN ;

    for (int r = 0 ; r < N ; r++)
    {
        for (int i = 0 ; i < N ;i++)
        {
            int com [100] ;
            for (int j = i ; j < N ;j++)
            {
                int d = 0 ;
                for (int k = r ; k < N ;k++)
                    if (i == j)
                        com [d++] = war[k][j] ;
                    else
                        com [d++] += war[k][j] ;
                for (int k = 0 ; k < r  ;k++)
                    if (i == j)
                        com [d++] = war[k][j] ;
                    else
                        com [d++] += war[k][j] ;

                mx = max(mx , one( com ,N)) ;
            }
             for (int j = 0 ; j < i ;j++)
            {
                int d = 0 ;
                for (int k = r ; k < N ;k++)
                        com [d++] += war[k][j] ;
                for (int k = 0 ; k < r ;k++)
                        com [d++] += war[k][j] ;
                mx = max(mx , one( com ,N)) ;
            }
        }
    }
    return mx ;
}

int main()
{
        freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);
    int T ;
    cin >> T ;

    while (T--)
    {
        int N ;
        scanf("%d" , &N) ;

        for (int i = 0 ; i < N ;i++)
            for (int j = 0 ; j < N ; j++)
                scanf("%d",&war[i][j]);

        printf("%d\n" , two(N)) ;

    }
}
