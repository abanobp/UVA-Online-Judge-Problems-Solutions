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
#define INF -1000000007
using namespace std;
//int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int > > adj;
vector<int> lev ;
vector<int> dis ;
vector<int> yes ;
vector<bool> vis ;

bool reach (int v ,int  N )
{
    if (vis [v])
        return 0 ;
    vis [v] = 1 ;
    if (v == N)
        return 1 ;
   bool M = 0 ;
    for (int i = 0 ; i < adj [v].size() ; i++)
        M = max(M, reach(adj[v][i] ,N )) ;
    return M ;
}

bool shortest (int N  )
{
    yes.clear();
    dis.clear();
    dis.assign(N+3,INF);
    vector<bool> dd (N+3,1);

    dis [1] = 100 ;

    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 1 ; j <= N ; j++)
        {
            for (int k = 0 ; k < adj[j].size() ; k++)
            {
                int v = adj [j][k] , w = lev [v] ;

                if (dis [j] + w > dis[v] && dis [j] + w > 0 )
                {
                        dis [v] = dis [j] + w ;

                        if (i == N-1)
                            yes.push_back(v);
                        if (v == N )
                                return 1 ;
                }
            }
        }
    }
    vis.clear();
    vis.assign(N+3 , 0 );
    for (int i = 0 ; i < yes.size() ;i++)
    {
            if (reach(yes[i],N))
                return 1 ;
    }
    return 0 ;
}

int main()
{
       // freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);

        int N ;

        while (scanf("%d",&N) && N != -1)
        {
           adj.clear();
           adj.resize(N+3);
           lev.clear();
           lev.resize(N+3);

            for (int i = 1 ; i <= N ; i++)
            {
                int  door ;
                scanf("%d%d",&lev[i] , &door) ;

                for (int j = 0 ; j < door ; j++){
                 int a ;
                 scanf("%d",&a) ; adj[i].push_back(a);
                }
            }

           if (!shortest(N))
            printf("hopeless\n");
           else
            printf("winnable\n");

        }
}
