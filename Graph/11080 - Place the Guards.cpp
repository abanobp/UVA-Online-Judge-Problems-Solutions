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
vector< vector<int> > junc ;
int vis [209] , zero , one;
bool BFS (int v)
{
    zero = 0 , one = 0;

    queue<int>q;
    q.push(v);
    vis [ v ] = 1;

    one++;

    while(!q.empty())
    {

     int top = q.front();
      //  cout<<top<<"\n";
        q.pop();
     for (int i = 0; i <junc[top].size() ; i++)
     {
         if (vis [junc [ top ][i]] == -1){
            q.push(junc [ top ][i]), vis [ junc [ top ][i]] = 1 - vis [ top ] ;
            if (1 - vis [ top ] == 1)
                one++;
            else
                zero++;
         }
         else if (vis [ junc [ top ][i] ] == vis [ top ] )
            return 0;
     }
    }
   return 1;
}

int main()
{
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);

     int N ;
        scanf("%d",&N);
   while (N--)
   {
         memset(vis,-1,sizeof vis);
          junc.clear();

          int u , e ;

          scanf("%d%d",&u,&e);

          junc.resize(u);

          while (e--)
          {
              int a , b;
              scanf("%d%d",&a,&b);

              junc [a].push_back(b);
              junc [b].push_back(a);
          }

          int ans = 0 ;
         for (int i = 0 ; i < u ; i++)
         {

             if (vis [i] == -1)
                {

                   if ( BFS(i) )
                   {
                       if (one > 0 && zero > 0)
                        ans += min(one , zero);
                       else
                        ans += max(one , zero);
                   }
                    else
                    {
                        ans = -1;
                        break;
                    }

                }
         }

                printf("%d\n",ans);
   }

}
