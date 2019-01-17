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
using namespace std;
int N , M ,dis1 ,dis2;
int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}} ;
bool vis [1005][1005];

int BFS (int x , int y)
{
    queue<pair <int , int> > q ;

    q.push(make_pair(x,y));

    int level = 0 , sz = 1 ;
    vis [x][y];

    while(!q.empty())
    {
       int X = q.front().first , Y = q.front().second;
        q.pop();
        sz--;
        for (int i = 0 ; i < 4 ; i++)
        {
            int in1 = X + moves [i][0]  , in2 =   Y + moves [i][1] ;
            if (in1>=0 && in1 <= N && in2 >= 0 && in2 <= M && !vis [in1][in2] )
            {
                q.push(make_pair(in1,in2));
                vis [in1][in2] = 1 ;
                if (in1 == dis1 && in2 == dis2 )
                    return level + 1 ;
            }
        }

        if ( sz == 0 )
        {
            sz = q.size();
                 level++ ;
        }
    }
}

int main()
{
    // freopen("in.txt","r",stdin);
     //  freopen("out.txt","w",stdout);


       while (scanf("%d%d",&N,&M) && N )
            {

            memset(vis , 0 ,sizeof vis ) ;

            int rows ;
            scanf("%d",&rows) ;

            while (rows--)
            {
                int row , col;
                scanf("%d%d",&row,&col) ;

                for (int i = 0 ; i < col ; i++)
                {
                    int a ;
                    scanf("%d",&a);
                    vis [row][a] = 1;
                }
            }
             int x , y ;
                scanf("%d%d%d%d",&x,&y,&dis1,&dis2);
                printf("%d\n",BFS(x,y));
            }
}
