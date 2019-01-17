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

       int T ,t = 1;

       scanf("%d",&T) ;

       while (T--)
       {
            int N , R ;
            scanf("%d%d",&N,&R) ;

            vector<vector<int> > mat (N , vector<int> (N , INF)) ;

            for (int i = 0 ; i < N ; i++)
                mat [i][i] = 0 ;

            while (R--)
            {
                int a , b ;
                scanf("%d%d",&a,&b) ;
                mat [a] [b] = 1 ;
                mat [b] [a] = 1;
            }

            for (int k = 0 ; k < N ; k++ )
            {
                for (int i = 0 ; i < N ; i++ )
                {
                    for (int j = 0 ; j < N ; j++)
                    {
                        mat [i][j] = min(mat [i][j] , mat [i][k] + mat [k][j] ) ;
                    }
                }
            }
            int f ,d ,tot = 0 ;
            scanf("%d%d",&f,&d) ;

            for (int i = 0 ; i < N ; i++)
            {
                if ( mat [f][i] != INF && mat [i][d] != INF )
                {
                    tot = max(tot , mat [f][i] + mat [i][d] ) ;
                }
            }

            printf("Case %d: %d\n",t++ , tot ) ;
       }
}
