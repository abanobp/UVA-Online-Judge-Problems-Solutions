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
         //  freopen("in.txt","r",stdin);
        //   freopen("out.txt","w",stdout);
        int T = 1 ;
        while (1)
        {
            vector<vector<int> > SH (105,vector<int> (105 , INF) ) ;

            for (int i = 0 ; i < 105 ; i++ )
                SH [i][i] = 0 ;
            int a , b , c = 0 , cost = 0 ;

            while (scanf("%d%d",&a,&b) && a)
            {
                SH [a][b] = 1 ;
                c++ ;
                cost++ ;
            }

            if (!c)
                break ;
            set<pair<int,int> > yes ;
            for (int k = 1 ; k < 105 ; k++ )
            {
                for (int i = 1 ; i < 105 ; i++ )
                {
                    for (int j = 1 ; j < 105 ; j++ )
                    {
                            if (SH [i][j] > SH [i][k] + SH [k][j] )
                            {

                                if (yes .find(make_pair(i,j)) == yes.end() )
                                {
                                 SH [i][j] = SH [i][k] + SH [k][j]  ;
                                 cost += SH [i][j] ;
                                 c++;
                                 yes.insert(make_pair(i,j));
                                }
                                else
                                {
                                    cost -=  SH [i][j] ;
                                    SH [i][j] = SH [i][k] + SH [k][j]  ;
                                    cost += SH [i][j] ;
                                }
                            }
                        }
                    }
                }

          cout << "Case "<<T++ << ": average length between pages = " << fixed << setprecision(3) << (double (cost) ) / c << " clicks\n" ;

        }
}
