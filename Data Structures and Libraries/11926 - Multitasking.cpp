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
//int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main ()
{
          // freopen("in.txt","r",stdin);
          // freopen("out.txt","w",stdout);

        int N , M ;

        while (scanf("%d%d",&N,&M) )
        {
            if (!N && !M)
                break ;

            bool yes [2000005] ;
            memset(yes , 0 , sizeof yes ) ;
            bool f = 0 ;

            for (int i = 0 ; i < N ; i++ )
            {
                int a , b ;
                scanf("%d%d",&a,&b) ;
                for (int j = a ; j < b ; j++)
                {
                    if (yes [j])
                        f = 1 ;
                    else
                        yes [j] = 1 ;
                }
            }


            for (int i = 0 ; i < M ; i++)
            {
                int a , b , c ;
                scanf("%d%d%d",&a,&b,&c) ;

                while (a <=1000000 )
                {
                    for (int j = a ; j < b ; j++ )
                    {
                         if (yes [j])
                            f = 1 ;
                        else
                            yes [j] = 1 ;
                    }
                    a+=c , b+=c ;
                }
            }

            if (!f)
               cout <<  "NO CONFLICT\n";
            else
                cout << "CONFLICT\n" ;
        }
}
