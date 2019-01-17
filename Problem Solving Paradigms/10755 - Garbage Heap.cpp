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

int main()
{
          //freopen("in.txt","r",stdin);
           // freopen("out.txt","w",stdout);
    int T ;
    cin >> T ;

    while(T--)
    {
        int a , b , c ;
        cin >> a >> b >> c ;
       long long  dp [25][25][25] ;

        for (int i = 0 ; i < a ; i++)
        {
            for (int j = 0 ; j < b ;j++)
            {
                for (int k = 0 ; k < c ;k++)
                {
                    long long &ret = dp [i][j][k] ;
                    cin >> ret  ;
                   // cout << ret << "\n" ;
                    if (i) ret += dp [i - 1][j][k] ;

                    if (j) {
                        ret += dp [i][j - 1][k] ;
                        if (i)
                        ret -= dp [i - 1][j - 1][k] ;
                    }

                    if (k)
                    {
                        ret += dp [i][j][k - 1] ;
                        if (i)
                        ret -= dp [i - 1][j][k - 1] ;

                        if (j){
                        ret -= dp [i][j - 1][k - 1]  ;
                        if (i)
                        ret += dp [i - 1][j - 1][k - 1] ;
                        }
                    }
                  //  cout << ret << "\n" ;
                }
            }
        }

        long long MX = LONG_LONG_MIN ;
        for (int i = 0 ; i < a ; i++)
        {
            for (int g = 0 ; g <= i ; g++)
            {
                for (int j = 0 ; j < b ;j++)
                {
                    for (int k = 0 ; k < c ; k++)
                    {
                        for (int x = j ; x < b ; x++)
                        {
                            for (int y = k ; y < c ; y++)
                            {
                               long long sum = dp [i][x][y] ;
                                // cout << sum << "\n" ;
                               if (j)
                               sum -=  dp [i][j - 1][y] ;

                               if (k)
                               sum -=  dp [i][x][k - 1] ;

                               if (j && k)
                                sum +=  dp [i][ j - 1 ][k - 1] ;

                               if (g){
                               long long  sum2 = dp [g - 1][x][y] ;
                               if (j)
                               sum2 -=  dp [g - 1][j - 1][y] ;

                               if (k)
                               sum2 -=  dp [g - 1][x][k - 1] ;

                               if (j && k)
                                sum2 +=  dp [g - 1][ j - 1 ][k - 1] ;

                               //  cout << i <<" " << x << " " << y << "\n" ;
                              // cout << sum << " " << sum2 <<  "\n" ;
                               sum -= sum2 ;
                               }
                                MX = max(MX , sum) ;
                            }
                        }
                    }
                }
            }
        }

        cout <<  MX << "\n" ;
        if (T)
            cout << "\n" ;
    }
}
