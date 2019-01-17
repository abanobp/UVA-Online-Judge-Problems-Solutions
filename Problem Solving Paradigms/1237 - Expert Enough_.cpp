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
#define INF  1000007
using namespace std;

int main()
{
         // freopen("in.txt","r",stdin);
         //freopen("out.txt","w",stdout);

        int T ;
        scanf("%d",&T) ;

        while (T--)
        {

         int n ;
         scanf("%d",&n) ;

         string  name [10005] ;
         int price [1000006] ;
         memset(price , 0 , sizeof price ) ;

         for (int i = 1 ; i <= n ; i++)
         {

            int l , h ;
            cin >> name [i] >> l >> h ;

            for (int j = l ; j <= h ; j++)
            {
                if (price [j])
                   price [j] = -1 ;
                else
                    price [j] = i ;
            }
         }

         int p ;
         scanf("%d",&p) ;


         while (p--)
         {
             int a ;
             scanf("%d",&a) ;

             if (price [a] < 1 )
                printf("UNDETERMINED\n") ;
             else
                cout << name [price[a]]  << "\n" ;
         }

            if (T)
                printf("\n") ;
         }
}
