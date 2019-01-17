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
int moves[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int malls [2005][2005];
queue<pair <int,int> >q ;
bool vis [2005][2005];

int BFS()
{
    int level  = 0 , sz = q.size();

    while (!q.empty())
    {
        int X = q.front().first , Y = q.front().second ;
        q.pop();
        sz--;

        for (int i = 0 ; i < 4 ; i++)
        {
            int in1 = X + moves [i][0] , in2 = Y + moves [i][1] ;

            if (in1>= 0 && in1 <= 2000 && in2 >= 0 && in2 <=2000 && !vis [in1][in2] )
            {
                q.push(make_pair(in1,in2));
                vis [in1][in2] = 1 ;
                if (malls [in1][in2] == 2)
                    return level + 1;
            }
        }
        if (!sz)
        {
            level++;
            sz = q.size();
        }
    }
    return 0 ;
}


int main()
{
            freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);


        int N , M ;

       while (scanf("%d",&N) && N )
        {
            memset(malls , 0 ,sizeof malls ) ;
            memset(vis,0,sizeof vis);
            while (!q.empty())
                q.pop();

            for (int i = 0 ; i < N ; i++)
            {
                int a , b ;
                scanf("%d%d",&a,&b);
                q.push(make_pair(a,b)) ;
                vis [a] [b] = 1;
            }

            scanf("%d",&M);

            for (int i = 0 ; i < M ; i++)
            {
                int a , b ;
                scanf("%d%d",&a,&b);
                malls [a][b] = 2 ;

            }

            printf("%d\n",BFS());
        }
}
