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
int Rank [1009];
void full (int n)
{
    parent.resize(n);
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
int number ()
{
    set <int> s ;
    for (int i = 0 ; i < parent.size() ; i++)
    {
        s.insert(parent[i]);
    }
    return s.size();
}
};

int dis (int x1,int y1,int x2,int y2)
{
    return  ((x1-x2) * (x1-x2))  + ((y1-y2) * (y1-y2)) ;
}
int main ()
{
          // freopen("in.txt","r",stdin);
         // freopen("out.txt","w",stdout);

        int T ;
        scanf("%d",&T);

       for (int test = 1 ; test <= T ; test++)
       {

           int N , R ;

           scanf("%d%d",&N,&R) ;

           vector<pair <int,int> > p ;
           vector <pair <int,pair <int,int> > > edg ;
           for (int i = 0 ; i < N ; i++)
           {
               int a , b ;
               scanf("%d%d",&a,&b);
               p.push_back(make_pair(a,b)) ;
           }


           for (int i = 0 ; i < N ; i++)
           {
               for (int j = i +1 ; j < N ; j++)
               {
                    int x1 = p[i].first , y1 = p[i].second , x2 = p [j].first ,y2 = p [j].second ;

                    edg.push_back(make_pair(dis(x1,y1,x2,y2),make_pair(i,j)));
               }
           }

            sort(edg.begin(),edg.end());

            UNION   road ;

            road.full(N);

            double tot1 = 0 , tot2 = 0 ;
            int stat = 1 ;
            R *= R ;

            for (int i = 0 ; i < edg.size() ; i++)
            {
                int cost = edg[i].first , cit1 = edg[i].second.first , cit2 = edg[i].second.second ;


                    if (road.UN(cit1,cit2)){

                        if (cost <= R )
                            tot1 += sqrt(cost) ;
                        else
                            tot2 += sqrt(cost) , stat++;
                    }
            }

            printf("Case #%d: %d %d %d\n",test , stat , int (round(tot1)) , int ( round(tot2) ));

       }

}
