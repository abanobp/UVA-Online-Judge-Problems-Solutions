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

map <string , pair<string ,string> > com ;
map <string , vector<string> > lan ;

int shortest (string start , string en )
{
    priority_queue< pair<int,string >  , vector<pair<int,string > >  , greater<pair<int,string > > > pq;

    map <string,int> dis ;
    for (int i = 0 ; i < lan [start].size() ; i++ )
        pq.push(make_pair(lan[start][i].size(),lan[start][i])), dis [lan[start][i]] = lan[start][i].size();

    while (!pq.empty())
    {
        int D = pq.top().first ;
        string v = pq.top().second;
        pq.pop();

        if (dis.find(v)!=dis.end() && dis [v] < D ) continue ;
        if (com[v].first == en || com [v].second == en)
            return dis [v];

        for (int i = 0 ; i < lan [com[v].first].size() ; i++)
        {
         int sz = lan [com[v].first][i].size();
         string nod =  lan [com[v].first][i] ;

         if ((dis.find(nod)==dis.end() || sz + dis [v]  < dis [nod]) && nod[0]!= v[0])
         {
            dis [nod] = sz + dis [v] ;
            pq.push(make_pair(dis[nod],nod)) ;
         }
        }
        for (int i = 0 ; i < lan [com[v].second].size() ; i++)
        {
         int sz = lan [com[v].second][i].size();
         string nod =  lan [com[v].second][i] ;

         if ((dis.find(nod)==dis.end() || sz + dis [v]  < dis [nod]) && nod[0]!= v[0])
         {
            dis [nod] = sz + dis [v] ;
            pq.push(make_pair(dis[nod],nod)) ;
         }
        }
    }
    return -1 ;
}

int main()
{
        //freopen("in.txt","r",stdin);
      // freopen("out.txt","w",stdout);
    int M ;

    while (scanf("%d",&M) && M)
    {
        com.clear();
        lan.clear();
        string start , en ;
        cin >> start >> en ;

        while (M--)
        {
            string a , b , c ;
            cin >> a >> b >> c ;

            com[c].first = a , com [c].second = b;
            lan [a].push_back(c);
            lan [b].push_back(c);
        }

        int res = shortest(start,en);

        if (res == -1)
            printf("impossivel\n");
        else
            printf("%d\n",res);
    }
}
