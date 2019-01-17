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
#include<bitset>
#define INF  100000007
using namespace std;
class UNION {

public :
vector<int> parent ;
int Rank [755];
void full (int n)
{
    parent.resize(n+5);
    for (int i = 0 ;i < n + 5 ; i++)
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
bool comp (pair<int , pair<int,int> > &x , pair<int , pair<int,int> > &y )
{
    return (x.first > y.first) ;
}
vector<vector<pair<int,int> > > adj ;
int M , th;

void fun (int u , int pr , int m)
{
    if (u == th)
       {M = m ;
       return ; }
    for (int i = 0 ; i < adj[u].size() ; i++)
    {
        if (adj[u][i].first != pr)
        {
            fun(adj[u][i].first , u , min(m ,adj[u][i].second)) ;
        }
    }
}
int main()
{
         //freopen("in.txt","r",stdin);
           //   freopen("out.txt","w",stdout);
    int N , R , tes = 1;

    while (scanf("%d%d",&N , &R) && N && R )
    {
        map <string , int > nam ;
        vector<pair<int , pair<int,int> > > edg (N) ;
        int in = 1 ;
        for (int i = 0 ; i < R ;i++)
        {
            string a , b ;
            int x ;
             cin >> a >> b >> x ;

             if (nam.find(a) == nam.end())
                nam [a] = in++;
             if (nam.find(b) == nam.end())
                nam [b] = in++ ;
            edg.push_back(make_pair(x , make_pair( nam[a] , nam[b]))) ;
        }
        adj.clear();
        adj.resize(N + 5) ;
        sort(edg.begin() , edg.end() ,comp) ;
        UNION P ;
        P.full(N) ;
        for (int i = 0 ; i < R ; i++)
        {
            int a = edg [i].second.first , b = edg [i].second.second ;
            if (P.UN(a , b))
                adj[a].push_back(make_pair(b , edg[i].first)) , adj[b].push_back(make_pair(a , edg[i].first)) ;
        }

        string a , b ;
        cin >> a >> b ;
        th = nam [b] ;
        fun(nam[a] , -1 , 1000000007) ;

        printf("Scenario #%d\n%d tons\n\n" , tes++ , M) ;
    }
}
