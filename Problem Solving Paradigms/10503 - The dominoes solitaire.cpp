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
int dom1 [15] , dom2 [15] , N , M , a ,b , x , y ;
bool yes [15] ;
bool best (int p , int pr)
{
    //cout << pr << "\n" ;
    if (p == N)
    {
        if (pr == x)
            return 1 ;
        return 0 ;
    }

    for (int i = 0 ; i < M ;i++)
    {
        if ( !yes [i]){
                yes [i] = 1 ;
        if (dom1 [i] == pr)
            if (best(p + 1 , dom2 [i]))
                return 1 ;
        if (dom2 [i] == pr)
            if (best(p+1 , dom1[i]))
                return 1 ;
        yes [i] = 0 ;
        }
    }
    return 0 ;
}
int main()
{
        // freopen("A-large.in","r",stdin);
        //freopen("out.txt","w",stdout);

   while (scanf("%d",&N) && N)
   {
       scanf("%d",&M) ;
       scanf("%d%d%d%d",&a,&b,&x,&y) ;

       for (int i = 0 ; i < M ;i++)
        scanf("%d%d",&dom1[i],&dom2[i]);

        memset(yes , 0 , sizeof yes) ;

        if (best(0,b))
            printf("YES\n") ;
        else
            printf("NO\n") ;
   }
}
