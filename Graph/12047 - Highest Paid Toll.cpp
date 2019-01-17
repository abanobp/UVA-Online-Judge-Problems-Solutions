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
vector<vector<pair<int,int> > > adj1 ,adj2;
priority_queue<pair<int,pair<int,int> > > edg;
vector<int>dis1,dis2;
void shortest1 (int N , int S )
{
    priority_queue< pair<int,int >  , vector<pair<int,int> >  , greater<pair<int,int > > > pq;
        dis1.assign(N+5,INF);
        pq.push(make_pair(0,S));
        dis1[S] = 0 ;

        while(!pq.empty())
        {
            int D = pq.top().first , v = pq.top().second ;
            pq.pop();

            if (D != dis1 [v]  ) continue ;

            for (int i = 0 ; i < adj1[v].size() ; i++)
            {
              int d = adj1[v][i].second , nod = adj1[v][i].first ;
              if (d + dis1 [v] < dis1[nod] )
              {
                  dis1 [nod] = d + dis1 [v] ;
                  pq.push(make_pair(dis1[nod],nod));
              }
            }
        }
}

void shortest2 (int N , int S )
{
    priority_queue< pair<int,int >  , vector<pair<int,int> >  , greater<pair<int,int > > > pq;
        dis2.assign(N+5,INF);
        pq.push(make_pair(0,S));
        dis2[S] = 0 ;

        while(!pq.empty())
        {
            int D = pq.top().first , v = pq.top().second ;
            pq.pop();

            if (D != dis2 [v]) continue ;

            for (int i = 0 ; i < adj2[v].size() ; i++)
            {
              int d = adj2[v][i].second , nod = adj2[v][i].first ;
              if (d + dis2 [v] < dis2[nod] )
              {
                  dis2 [nod] = d + dis2 [v] ;
                  pq.push(make_pair(dis2[nod],nod));
              }
            }
        }
}

int MAX  (int p )
{
    int res = -1 ;
    while(!edg.empty())
    {
        int c = edg.top().first , a = edg.top().second.first , b = edg.top().second.second;

        if ( dis1[a] + dis2 [b] + c <= p && res == -1)
             res = c ;
        edg.pop();
    }
    return res ;
}
int main()
{
        //freopen("in.txt","r",stdin);
      // freopen("out.txt","w",stdout);

        int T ;

        scanf("%d",&T);

        while (T--)
        {
            adj1.clear();
            adj2.clear();
            dis1.clear();
            dis2.clear();
            int  N , M , S ,T ,P ;

            scanf("%d%d%d%d%d",&N,&M,&S,&T,&P);

            adj1.resize(N+5);
            adj2.resize(N+5);
            while (M--)
            {
                int a ,b ,c ;
                scanf("%d%d%d",&a,&b,&c);
                adj1 [a].push_back(make_pair(b,c)) ;
                adj2 [b].push_back(make_pair(a,c)) ;
                edg.push(make_pair(c,make_pair(a,b)));
            }

            shortest1(N , S);
            shortest2(N , T);
            printf("%d\n", MAX(P) ) ;

        }
}
