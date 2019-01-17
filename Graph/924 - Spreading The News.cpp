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
vector<vector <int> > adj ;
vector<pair<int,int> > res ;
void BFS (int u)
{
    queue<int> q ;

    q.push(u);
    int level = 0 , sz = 1 ;
    bool vis [2505] ;
    memset(vis , 0 , sizeof vis);
    vis [u] = 1;
    int mx = 1 , f = 1 ;
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        sz--;
        for (int i = 0 ; i < adj[top].size() ; i++)
        {
            if (!vis [adj[top][i]])
            {
                q.push(adj[top][i]);
                vis [adj[top][i]] = 1 ;
            }
        }
        if ( sz == 0 )
        {

            sz = q.size();
            if (sz != 0 )
            {
                 level++ ;
                if (mx < sz)
                    mx = sz , f = level ;
            }
        }
    }

    if (!level)
        f= -1;
    res [u].first = mx , res [u].second = f ;
}

int main()
{
     //   freopen("in.txt","r",stdin);
     //  freopen("out.txt","w",stdout);

        int N ;
        scanf( "%d" , &N ) ;


            adj.resize(N + 5);

            res.resize(N + 5);

            for (int i = 0 ; i < N ; i++)
            {
                int sz , a ;
                cin >> sz ;
                while (sz--)
                    cin >> a , adj[i].push_back(a);
            }

            for (int i = 0 ; i < N ; i++)
            {
                BFS(i);
            }

            int T ;
            cin >> T ;

            while (T--)
            {
                int a ;
                cin >> a ;

                if (res [a].second == -1)
                    cout << "0\n";
                else
                    cout << res [a].first <<" " << res [a].second << "\n";
            }
}
