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
using namespace std;
vector<vector<int> > col ;
int bit [209] ;
bool yes (int c , int v)
{
    for (int i = 0 ;i < col [ v] .size() ; i++ ){
        if ( bit [col [v][i]] == c)
            return 1;
    }
    return 0;
}
bool color (int v)
{
    if (bit [v]!=-1)
        return 1 ;

    for (int i = 1 ; i <= 2  ; i++ )
    {
     if (!yes (i ,v)){
            bit [v] = i ;
            bool ans  = 1;
        for (int i = 0 ; i <col [ v ] .size() ; i++)
             ans = min(ans,color(col [v][i]));

             return ans ;
     }
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

     int N ;

   while (scanf("%d",&N) && N !=0)
   {
         memset(bit, -1 , sizeof bit);
           col.clear();
           col.resize(N);
       int l ;
       scanf("%d",&l);

       while (l--)
       {
           int a , b ;
           scanf("%d%d",&a,&b);
           col [a].push_back(b);
           col [b].push_back(a);
       }
       bool ans = 1;
       for ( int i = 0 ; i <N ; i++)
        ans = min(ans , color(i));

       if (ans)
        printf("BICOLORABLE.\n");
       else
        printf("NOT BICOLORABLE.\n");
   }

}
