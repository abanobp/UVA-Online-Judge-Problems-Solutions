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
int Rank [200009] , sz [200009];
void full (int n)
{
    parent.resize(n+4);
    for (int i = 0 ;i < n + 4; i++)
        parent[i] = i , Rank [i] = 0 , sz [i] = 1 ;
}
int find (int p )
{
    if  ( parent[p] == p  )
        return  p ;
   return parent [ p ]  = find( parent [ p ] ) ;

}

int UN (int x , int y)
{
int p_x = find(x) ;
int p_y = find(y) ;
if (p_x == p_y){
    return  sz[p_x] ;
}

      if (Rank [p_x] > Rank  [p_y])
   {
       parent [p_y] = p_x ;
       sz [p_x] += sz [p_y] ;
       return  sz [p_x];
   }
   else {
    parent [p_x]  = p_y ;
    sz [p_y] += sz [p_x] ;
    if (Rank[p_x] == Rank [p_y] )
        Rank  [p_y]++;

        return sz [p_y];
   }
}
};
int main()
{
          freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);

       int S ;

       while (cin >> S )
       {
            int M ;
            scanf("%d",&M) ;

            string a ;
            cin >> a ;
            map <char,int> n ;

            n[a[0]] = 0 , n[a[1]] = 1 , n[a[2]] = 2 ;

            vector<vector<int> > p (S+5) ;
            int yes [30] ;
            memset(yes , 0 , sizeof yes) ;
            yes[n[a[0]]] = 1 , yes [n[a[1]]] = 1 , yes [n[a[2]]] = 1 ;
            int j = 3 ;
            while (M--)
            {
                string c ;
                cin >> c ;

                if (n.find(c[0]) == n.end())
                    n[c[0]] = j++ ;
                if (n.find(c[1]) == n.end())
                    n[c[1]] = j++ ;
                p[n[c[0]]].push_back( n[c[1]]) ;
                p[n[c[1]]].push_back( n[c[0]]) ;
            }
            int mx = 1 ;
            bool x = 0 ;
            for (int i = 0 ; i < S ; i++)
            {
                x = 0 ;
                for (int j = 0 ; j < S ; j++)
                {
                    if (!yes [j] )
                    {
                        vector<int> v ;
                        for (int k = 0 ; k < p[j].size() ; k++)
                        {
                            if (yes [p[j][k]] > 0)
                                 v.push_back(yes [p[j][k]] + 1) ;
                        }
                        if (v.size() >2){
                           sort(v.begin(),v.end()) ;
                           yes [j] = v[2] ;
                           mx = max(mx , v[2]);
                        }
                        else
                            x = 1 ;
                    }
                }
            }

            if (x)
                printf("THIS BRAIN NEVER WAKES UP\n");
            else
                printf("WAKE UP IN, %d, YEARS\n",mx-1) ;

       }
}
