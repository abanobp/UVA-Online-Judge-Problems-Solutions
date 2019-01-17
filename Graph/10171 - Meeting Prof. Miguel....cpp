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
           freopen("in.txt","r",stdin);
           freopen("out.txt","w",stdout);

        int N;
        while (scanf("%d",&N) && N )
        {
            int SH [30][30][30] ;

            for (int i = 0 ; i < 30 ; i++ ){
                for (int j = 0 ; j < 30 ; j++ )
                     SH [i][j]['M' - 'A'] = INF , SH [i][j]['Y' - 'A'] = INF;
                SH [i][i]['M' - 'A'] = 0, SH [i][i]['Y' - 'A'] = 0 ;
            }
            while (N--)
            {
                char g , d , a, b ;
                int c ;
                cin >> g >> d >> a >> b >> c ;
                SH [a - 'A'][b - 'A'][g - 'A'] = min(SH [a - 'A'][b - 'A'][g - 'A'] , c) ;
                if (d == 'B')
                SH [b - 'A'][a - 'A'][g - 'A'] = min(SH [a - 'A'][b - 'A'][g - 'A'] , c);
            }

            for (int k = 0 ; k < 30 ; k++ )
            {
                for (int i = 0 ; i < 30 ; i++ )
                {
                    for (int j = 0 ; j < 30 ; j++ )
                    {
                         SH [i][j]['Y' - 'A'] =  min(SH [i][j]['Y' - 'A'], SH [i][k]['Y' - 'A'] + SH [k][j]['Y' - 'A'] );
                         SH [i][j]['M' - 'A'] =  min(SH [i][j]['M' - 'A'], SH [i][k]['M' - 'A'] + SH [k][j]['M' - 'A'] );
                    }
                }
            }

            char a , b ;
            cin >> a >> b ;
            int M = INF ;
            vector<char> S ;
            for (int i = 0 ; i < 30 ; i++ )
            {
              //  cout << SH [a - 'A'][i]['Y' - 'A'] + SH [b - 'A'][i]['M' - 'A'] << "\n";
                     if (M > SH [a - 'A'][i]['Y' - 'A'] + SH [b - 'A'][i]['M' - 'A'] )
                     {
                         M = SH [a - 'A'][i]['Y' - 'A'] + SH [b - 'A'][i]['M' - 'A'] ;
                         S.clear() ;
                         S.push_back(i + 'A') ;
                     }
                     else if (M == SH [a - 'A'][i]['Y' - 'A'] + SH [b - 'A'][i]['M' - 'A'] )
                        S.push_back(i + 'A') ;
            }

            if (M == INF)
                cout << "You will never meet.\n" ;
            else
            {
                cout << M ;
                for (int i = 0 ; i < S.size() ; i++)
                    cout << " " << S [i] ;
                cout << "\n" ;
            }
        }
}
