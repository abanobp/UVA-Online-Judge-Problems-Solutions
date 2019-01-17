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
int Rank [200009];
void full (int n)
{
    parent.resize(n+4);
    for (int i = 0 ;i < n + 4; i++)
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
int roll (char a , char b)
{
   int res1 = abs(a - b) ;
   int res2 = ( min(a , b) - '0') + ('9' - max(a,b) ) + 1 ;

   return min(res1 , res2) ;
}
int main()
{
       //   freopen("in.txt","r",stdin);
        //    freopen("out.txt","w",stdout);

    int T ;
    cin >> T ;

    while (T--)
    {
        int N ;
        scanf("%d" , &N) ;
        vector <string> a (N+1);
        a[0] = "0000" ;

        for (int i = 1 ; i <= N ;i++)
            cin >> a[i] ;

        vector<pair<int,pair<int,int> > > edg ;

        for (int i = 0 ; i <= N ;i++)
        {
            for (int j = i + 1 ; j <= N ; j++)
            {
                int res = 0;
                for (int k = 0 ; k < 4 ; k++)
                    res += roll(a[i][k],a[j][k]) ;
                edg.push_back(make_pair(res , make_pair(i,j))) ;
            }
        }

        sort(edg.begin(),edg.end()) ;
        long long res = 0 ;

        UNION P ;
        P.full(N) ;
        bool f = 0 ;
        for (int i = 0; i < edg.size() ;i++)
        {
            int val = edg[i].first , a = edg[i].second.first ,  b  = edg[i].second.second ;
            if (f && a && b){
              // cout << a << " " << b << "\n" ;
                if (P.UN(a,b))
                res+=val ;
            }
            else if (!f)
            {
                if (P.UN(a,b))
                    res+=val ;
                if (!a || !b)
                    f = 1 ;
            }
        }

        cout << res << "\n" ;
    }
}
