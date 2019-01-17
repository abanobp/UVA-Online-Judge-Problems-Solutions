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
#include<iomanip>
#define INF  1000000007
using namespace std;
//int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
class UNION {

public :
vector<int> parent ;
int Rank [107];
void full (int n)
{
    parent.resize(n+4);
    for (int i = 0 ;i < n + 4 ; i++)
        parent[i] = i , Rank [i] = 0 ;

}
int find (int p )
{
    if  ( parent[p] == p  )
        return  p ;
   return parent [ p ]  = find( parent [ p ] ) ;

}

bool UN (int x , int y)
{
int p_x = find(x) ;
int p_y = find(y) ;
if (p_x == p_y)
    return  0 ;

      if (Rank [p_x] > Rank  [p_y])
   {
       parent [p_y] = p_x ;
       return  1;
   }
   else {
    parent [p_x]  = p_y ;

    if (Rank[p_x] == Rank [p_y] )
        Rank  [p_y]++;

        return 1;
   }

}
};

int main ()
{
           freopen("in.txt","r",stdin);
           freopen("out.txt","w",stdout);

        int T ;

        scanf("%d",&T) ;

        while (T--)
        {
            int N , M  ;

            scanf("%d%d",&N,&M);

            vector<pair<int,pair<int,int> > > edg (M);

            for (int i = 0 ; i < M ; i++ )
                scanf("%d%d%d",&edg[i].second.first,&edg[i].second.second,&edg[i].first) ;

            sort(edg.begin(),edg.end());

            UNION  P ;
            P.full(N) ;
            vector <int> E ;
            int cost_1 = 0 ;
            for (int i = 0 ; i < M ; i++)
            {
                int a = edg[i].second.first , b =  edg[i].second.second , c =  edg[i].first ;

                if (P.UN(a,b))
                {
                    cost_1 += c;
                    E.push_back(i) ;
                }
            }

            int MIN = INF ;
            for (int i = 0 ; i < E.size() ; i++)
            {
                P.full(N);
                int cost_2 = 0 , num = 0 ;
                for (int j = 0 ; j < M ; j++ )
                {
                    int a = edg[j].second.first , b =  edg[j].second.second , c =  edg[j].first ;
                    if ( E [i] != j )
                    {
                        if (P.UN(a,b))
                          num++,cost_2 += c ;
                    }
                }

                if (num == N-1)
                    MIN = min(MIN , cost_2 ) ;
            }

            printf("%d %d\n",cost_1 , MIN ) ;
        }
}
