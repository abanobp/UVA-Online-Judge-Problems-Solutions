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
using namespace std;
int N;
char grid [105][105];
bool ship (int x,int y)
{
    if (x<0 || y<0 || x>=N || y>=N)
        return 1;
    if (grid [ x ][ y ] == '.')
        return 1 ;
//cout<<x<<" "<<y<<"\n";
    grid [x][y] = '.';

    ship(x,y-1);
    ship(x,y+1);
    ship(x-1,y);
    ship(x+1,y);

    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

       int T ;

       scanf("%d",&T);

       for ( int TEST = 1 ; TEST <= T ; TEST++ )
       {
           scanf("%d",&N);

           for ( int i = 0 ; i < N ; i++)
                cin>>grid[i];

                int ans = 0 ;
             for ( int i = 0 ; i < N ; i++)
                {
                    for (int j = 0 ; j < N ; j++)
                        if (grid[i][j]=='x')
                          ans += ship (i,j);
                }
            printf("Case %d: %d\n",TEST,ans);
       }
}
