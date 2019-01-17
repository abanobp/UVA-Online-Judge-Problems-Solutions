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
//int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<pair<int,int> > > maze ;

int shortest (int n, int S , int T )
{
    priority_queue< pair<int,int>  , vector<pair<int,int > >  , greater<pair<int,int > > > pq;
    set <int> mice ;
    vector<int > dis (n+5, INF);
    mice.insert(S);
    pq.push(make_pair(0,S));
    dis [S] = 0 ;

    while(!pq.empty())
    {
       // cout <<"a";
        int d = pq.top().first  , v = pq.top().second  ;
            pq.pop();
        if (d > dis [v]) continue ;

        for (int i = 0 ; i < maze [v].size() ; i++)
        {
            int D = maze [v][i].first , nod = maze [v][i].second ;

            if ( D + dis [v] < dis [nod])
            {
                dis [nod] = D + dis [v] ;
                pq.push(make_pair(dis [nod],nod)) ;
                if (dis [nod] <= T )
                mice.insert(nod);
            }
        }

    }
    return mice.size();
}

int main()
{
        freopen("in.txt","r",stdin);
      // freopen("out.txt","w",stdout);

   int N  ;
    cin >> N;

    while (N--)
    {
        cin.ignore();
            int n , E , T ,link ;
        scanf("%d%d%d%d",&n,&E,&T,&link);
        maze.clear();
        maze.resize(n+5);

       while (link--)
       {
            int a , b , c ;
            scanf("%d%d%d",&a,&b,&c);
            maze[b].push_back (make_pair(c,a));
       }

       cout <<   shortest(n,E,T) << "\n";

       if (N)
        cout << "\n";

    }
}
