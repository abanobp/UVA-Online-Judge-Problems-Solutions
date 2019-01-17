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
vector<vector<int> > elev , flor ;
vector<int> speed ;
int shortest (int n, int S  )
{
    priority_queue< pair<int,pair<int,int> >  , vector<pair<int,pair<int,int> > >  , greater<pair<int,pair<int,int> > > > pq;

    vector< int > dis (105 , INF );

    pq.push(make_pair(0,make_pair(S,-1)));

    dis [S] = 0 ;

    while (!pq.empty())
    {

        int D = pq.top().first , v = pq.top().second.first , p = pq.top().second.second ;
        pq.pop();

        if (D > dis [v]) continue ;
        if (v == 0)
            return dis [v] ;

        for (int i = 0 ; i < flor[v].size () ; i++)
        {

            int E = flor[v][i];

            for (int j = 0 ; j < elev[E].size() ; j++)
            {

              int nod = elev[E][j] , weight =  abs(nod - v ) * speed [E] ;
            //  cout << nod <<"\n";
              if (E != p  && p != -1 )
                    weight += 60;
               // cout << nod << " " << v << " " << weight <<"\n";
               if ( dis [v] + weight  < dis [nod])
                {
                    dis [nod] = dis [v] + weight ;
                    pq.push(make_pair(dis [nod],make_pair(nod,E)));
                }
            }
        }
    }
    return -1 ;
}

int main()
{
        freopen("in.txt","r",stdin);
      // freopen("out.txt","w",stdout);

        int N , K ;
        while (scanf("%d%d",&N,&K)!=EOF)
        {
            speed.clear();
            speed.resize(N+3);
            elev.clear();
            elev.resize(N+3);
            flor.clear();
            flor.resize(105);

            for (int i = 0 ;i < N ; i++)
                scanf("%d",&speed[i]);
            cin.ignore();
            for (int i = 0 ;i < N ; i++)
            {
                string b ;
                getline(cin,b);
                stringstream ss (b);
                int a;

                while (ss >> a ){
                elev[i].push_back(a);
                flor[a].push_back(i);
                }
            }

            int res = shortest(N , K ) ;

            if (res == -1)
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n",res);
        }
}
