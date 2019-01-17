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
vector< vector<int> > clow ;
int vis [305];
bool BFS (int v)
{
    //cout<<v<<"\n";
    queue<int>q;
    q.push(v);
    vis [ v ] = 1;

    while(!q.empty())
    {

     int top = q.front();
        q.pop();
     for (int i = 0; i <clow[top].size() ; i++)
     {
         if (vis [clow[ top ][i]] == -1){
            q.push(clow [ top ][i]), vis [clow [ top ][i]] = 1 - vis [ top ] ;
         }
         else if (vis [ clow [ top ][i] ] == vis [ top ] )
            return 0;
     }
    }
   return 1;
}

int main()
{
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);

     int u ;

   while (scanf("%d",&u) && u)
   {
         memset(vis,-1,sizeof vis);
          clow.clear();
          clow.resize(u);

         int a , b;
            while (scanf("%d%d",&a,&b) && a)
          {
              clow [a - 1].push_back(b - 1);
              clow [b - 1].push_back(a - 1);
          }

          bool ans = 1 ;
         for (int i = 0 ; i < u ; i++)
         {

             if (vis [i] == -1)
                {
                    ans = min (ans , BFS(i));
                }
         }

                if (ans)
                printf("YES\n");
                else
                printf("NO\n") ;
   }

}
