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
int N , arr [105][105] , com [105];

int one_d ( )
{
    int sum = 0 , mx = INT_MIN , neg = INT_MIN  ;
    for (int i = 0 ; i < N ; i++)
    {
        sum += com [i] ;
      //  cout << com [i] << " " ;
        if (sum < 0)
            sum = 0 ;
        else
            mx = max(mx , sum) ;
        neg = max(neg , com[i]) ;
    }
   // cout << "\n" ;

    if (mx >= 0)
    return mx ;

    return neg ;
}

int two_d ()
{
    int sub = INT_MIN ;
    for (int i = 0 ; i < N ;i++)
    {
        for (int j = i ; j < N ;j++)
        {
             for (int k = 0 ; k < N ; k++)
                if (i == j)
                    com [k] = arr [k][j] ;
                else
                    com [k] += arr [k][j] ;

            sub = max(sub ,one_d()) ;
          //  cout << sub << "\n" ;
        }
    }
    return sub ;
}

int main()
{
          // freopen("in.txt","r",stdin);
          // freopen("out.txt","w",stdout);
    int T ;
    cin >> T ;

   while (T--)
    {
        int S ;
        cin >> N >> S ;

       for (int i = 0 ; i < N ;i++)
            for (int j = 0 ; j < N ;j++)
                arr [i][j] = 1 ;
       while (S--)
       {
           int a , b , x , y ;
           cin >> a >> b >> x >> y ;
           a-- , b-- , x-- ,y--;

           for (int i = a ; i <= x ; i++)
                for (int j = b ; j <= y ;j++)
                    arr [i][j] = - 1000;

       }

        int res = two_d() ;

        if (res <= 0)
            cout << "0\n" ;
        else
            cout << res << "\n" ;
    }
}
