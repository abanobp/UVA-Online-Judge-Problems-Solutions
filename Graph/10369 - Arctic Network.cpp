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
int Rank [507];
void full (int n)
{
    parent.resize(n+4);
    for (int i = 0 ;i < n ; i++)
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
int dis (int x1 ,int y1 , int x2 , int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) ;
}
int main ()
{
            freopen("in.txt","r",stdin);
          freopen("out.txt","w",stdout);

        int N ;

        scanf("%d",&N) ;

        while (N--)
        {
            int S , P ;

            scanf("%d%d",&S,&P) ;

            vector<pair <int,int> > par (P) ;
            vector<pair<int,pair<int,int> > > edg  ;

            for (int i = 0 ; i < P ; i++)
                scanf("%d%d",&par[i].first,&par[i].second) ;

            for (int i = 0 ; i < P ; i++)
            {
                for (int j = i+1 ; j < P ; j++)
                    {
                        int x1  = par[i].first , y1 = par [i].second , x2 =  par[j].first , y2 = par [j].second ;

                        edg.push_back(make_pair(dis (x1,y1,x2,y2),make_pair(i,j))) ;
                    }
            }

            sort(edg.begin() , edg.end()) ;
            UNION CON ;

            CON.full(P) ;
            int  MX = 0  ,c = 0 ;
            for (int i = 0 ; i < edg.size() ; i++)
            {
                int cos = edg [i].first , a = edg[i].second.first , b = edg [i].second.second ;
                if (CON.UN(a,b))
                {
                    if (c < (P - S) )
                        MX = max(MX , cos ) ;
                    c++ ;
                }
            }

            cout << fixed << setprecision(2) << sqrt(MX)  << "\n";
        }
}
