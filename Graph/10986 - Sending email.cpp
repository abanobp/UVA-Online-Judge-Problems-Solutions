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
#define INF 1000000000
using namespace std;
vector<vector<pair<int,int> > > adj;
int shortest (int n ,int S , int T)
{
    priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq;
    vector<int>dis (n + 5 , INF);

    pq.push(make_pair(0,S));
    dis [S] = 0 ;

    while(!pq.empty())
    {
       // cout <<"a";
         int d = pq.top().first  , v = pq.top().second ;
            pq.pop();
        if (d > dis [v]) continue ;
       // cout << v <<"\n" ;
        if (v == T )
            return dis [v] ;

        for (int i = 0 ; i < adj[v].size() ; i++)
        {
            int in1 = adj[v][i].first , in2 = adj[v][i].second ;

            if (dis [v] + in2 < dis [in1])
            {

                dis [in1] = dis [v] + in2 ;
                pq.push(make_pair(dis[in1],in1)) ;
            }
        }
    }
    return -1;
}

int main()
{
         freopen("in.txt","r",stdin);
      //  freopen("out.txt","w",stdout);

    int  N ,test = 1;
    scanf("%d",&N);

    while (N--)
    {
        int n , m  , S , T ;
        scanf("%d%d%d%d",&n,&m,&S,&T) ;
        adj.clear();
        adj.resize(n+5);
        while (m--)
        {
            int a , b , c ;
             scanf("%d%d%d",&a,&b,&c) ;
            adj[a].push_back(make_pair(b,c));
            adj[b].push_back(make_pair(a,c));
        }

        int res = shortest(n,S,T);

        if (res == -1)
            printf("Case #%d: unreachable\n", test++);
        else
            printf("Case #%d: %d\n",test++ , res );
    }
}
