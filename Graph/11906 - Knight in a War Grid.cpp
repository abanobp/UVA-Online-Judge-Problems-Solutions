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
int vis [105][105],land [105][105],mark [105][105],N,M,R,C,H=0;

    void KNIGHT (int x,int y)
    {
        if (x<0 || y<0 || x >= R || y >= C )
        return ;
            if (land [x][y])
                return ;
            mark [x][y]++;

            if (vis [x][y] == 1)
                return ;

            vis [x][y] = 1 ;

         KNIGHT(x + M , y + N );
         KNIGHT(x + M , y - N );
         KNIGHT(x - M , y + N );
         KNIGHT(x - M , y - N );
         KNIGHT(x + N , y + M );
         KNIGHT(x + N , y - M );
         KNIGHT(x - N , y + M );
         KNIGHT(x - N , y - M );
    }

int main()
{
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

       int T ;

       scanf("%d",&T);

       for ( int TEST = 1 ; TEST <= T ; TEST++ )
       {
           memset(land,0,sizeof land);
           memset(mark,0,sizeof mark);
            memset(vis,0,sizeof vis);
           int W;
           scanf("%d%d%d%d%d",&R,&C,&M,&N,&W);

           while (W--)
           {
               int a,b;
                scanf("%d%d",&a,&b);
                land [a][b] = 1;
           }

            KNIGHT (0,0);
            mark [0][0]--;
           int even =0,odd=0;
           for (int i = 0 ; i < R ; i++)
           {
               for (int j = 0 ; j < C ; j++){
                     if (M==N || M ==0 || N == 0)
                           mark[i][j]/=2;

                if (mark[i][j]%2==0  && vis[i][j])
                  even++;
                if (mark[i][j]%2!=0 && vis [i][j])
                    odd++;}

           }

         printf("Case %d: %d %d\n",TEST,even,odd);
       }
}
