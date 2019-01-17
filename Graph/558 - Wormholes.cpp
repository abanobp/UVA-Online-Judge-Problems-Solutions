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
#define INF 1000000007
using namespace std;
//int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<pair<int,int> > > adj;
vector<int> dis ;
bool shortest (int N , int S )
{
    dis.clear();
    dis.assign(N+3,INF);

    dis [S] = 0 ;
    bool yes = 0 ;
    for (int i = 0 ; i < N ; i++)
    {
         yes = 0 ;
        for (int j = 0 ; j < N ; j++)
        {
            for (int k = 0 ; k < adj[j].size() ; k++)
            {
                int v = adj [j][k].first , w = adj [j][k].second ;

                if (dis [j] + w < dis[v])
                {
                        dis [v] = dis [j] + w ;
                        yes = 1;
                        if (i == N - 1)
                            return 1 ;
                }
            }
        }
        if (!yes)
            break;
    }

    return 0;
}
int main()
{
        //freopen("in.txt","r",stdin);
      // freopen("out.txt","w",stdout);

        int T ;

        scanf("%d",&T);

        while (T--)
        {
           int N , M ;
           scanf("%d%d",&N,&M);
           adj.clear();
           adj.resize(N+3);
           while (M-- )
           {
               int a , b , c ;
               scanf("%d%d%d",&a,&b,&c);
               adj[a].push_back(make_pair(b,c));
           }

           if (shortest(N ,0))
                printf("possible\n");
            else
                printf("not possible\n");
        }
}
