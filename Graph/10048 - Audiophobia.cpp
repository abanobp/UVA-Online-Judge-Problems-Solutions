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
class UNION {

public :
vector<int> parent ;
int Rank [1005];
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
int MX [105][105] ;
vector<vector<pair<int,int> > > adj  ;
void tree (int x , int v, int m , int pr)
{
    MX [x][v] = m ;
    MX [x][v] = m ;
   // cout << v  << "\n";
    for (int i = 0 ;i < adj[v].size () ; i++ )
        if (pr != adj[v][i].first)
            tree(x , adj[v][i].first , max(m,adj[v][i].second),v) ;
}
int main ()
{
           // freopen("in.txt","r",stdin);
         // freopen("out.txt","w",stdout);

       int C , S , Q  , T = 1 ;

       while (scanf("%d%d%d",&C,&S,&Q) && C )
       {
           if (T > 1)
            printf("\n");

           memset(MX , -1, sizeof MX) ;
           adj.clear() ;
           adj.resize(C+3) ;
           vector<pair<int , pair<int,int> > > edg (S);
           for (int i = 0 ; i < S ; i++)
           {
               scanf("%d%d%d",&edg[i].second.first , &edg[i].second.second , &edg[i].first) ;
           }

           sort (edg.begin(),edg.end()) ;

           UNION P ;
           P.full(C) ;

           for (int i = 0 ; i < S ; i++)
           {
               int a = edg[i].second.first , b = edg[i].second.second , cos = edg[i].first ;
               if (P.UN(a,b))
               {
                   adj[a].push_back (make_pair(b , cos )) ;
                   adj[b].push_back (make_pair(a , cos )) ;
               }
           }

           for (int i = 1 ; i <= C ; i++ )
                tree(i,i,0,0);
           printf("Case #%d\n",T++) ;
          while (Q--)
          {
            int a ,b ;
            scanf("%d%d",&a,&b) ;

            if (MX[a][b] != -1)
                printf("%d\n",MX [a][b]) ;
            else
                printf("no path\n") ;
          }

       }
}
