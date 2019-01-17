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
#define INF  1000000007
using namespace std;
//int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int> > adj ;
vector<int> dis ,lev , yes;
vector<bool> vis ;

void SHORT (int N)
{

    if (!N)
        return ;
    dis [1] = 0 ;

    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 1 ; j <= N ; j++)
        {
            for (int k = 0 ; k < adj[j].size () ; k++)
            {
                int  v = adj[j][k] , w = lev [v] - lev [j] ;
                w = w * w * w ;

                if (w + dis [j] < dis [v] && dis [j] != INF)
                {
                    dis [v] = w + dis [j] ;

                    if (i == N - 1 )
                        yes.push_back(v) ;
                }
            }
        }
    }

}

void hello (int v)
{
    if (vis [v])
        return ;
    vis [v] = 1 ;

    for (int i = 0 ; i < adj[v].size() ;i++)
        hello(adj[v][i]);
}
int main ()
{
          // freopen("in.txt","r",stdin);
         // freopen("out.txt","w",stdout);

    int N ,T = 1;

    while (cin >> N )
    {

        adj.clear();
        adj.resize(N+3);
        dis.clear();
        dis.assign(N+3,INF);
        vis.clear();
        vis.assign(N+3,0);
        yes.clear();
        lev.clear();
        lev.resize(N+3);
        for (int i = 1 ; i <= N ; i++ )
        {
            cin >> lev[i];
        }

        int r ;

        cin >> r  ;

        while (r--)
        {
            int a ,b ;
            cin >> a >> b ;

            adj[a].push_back(b) ;
        }

        SHORT(N);

        for (int i = 0 ; i < yes.size() ;i++)
            hello(yes[i]);

        int q ;

        scanf("%d",&q)  ;

        cout << "Set #" << T++ << "\n" ;
        while (q--)
        {
            int a ;
            cin >> a ;

            if (dis[a] < 3 || vis[a] || dis [a]==INF)
                cout << "?\n";
            else
                cout << dis [a] << "\n";
        }

    }


}
