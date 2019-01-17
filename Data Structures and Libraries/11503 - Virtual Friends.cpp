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
         // freopen("in.txt","r",stdin);
       //  freopen("out.txt","w",stdout);


       int N ;

       scanf("%d",&N) ;

       while (N--)
       {

            int F ;

            scanf("%d",&F) ;

            UNION P ;
            P.full(F*2);

            map <string,int> M ;
            int j = 0 ;
            for (int i = 0 ; i < F ; i++)
            {
                string a ,b ;
                cin >> a >> b ;
                if (M.find(a) == M.end())
                    M [a] = j++ ;
                if (M.find(b) == M.end())
                    M [b] = j++;
                cout << P.UN(M[a],M[b]) << "\n" ;
            }
       }
}
