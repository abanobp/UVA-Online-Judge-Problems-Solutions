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

int main()
{
         // freopen("in.txt","r",stdin);
         //freopen("out.txt","w",stdout);
         int  M ;

        while (scanf("%d",&M) != EOF )
        {
          vector<string> arr (M) ;

          for (int i = 0 ; i < M ; i++)
            cin >> arr [i] ;
          int TOT = 0 ;
          for (int i = 0 ; i < M ; i++ )
          {
              for (int j = 0 ; j < M ;j++)
              {
                  if (arr [i][j] == '1')
                  {
                   int step = INF ;
                   for (int k = 0 ; k < M ; k++)
                   {
                       for (int g = 0 ; g < M ; g++)
                       {
                           if (arr [k][g] == '3')
                           {
                               step = min( step , abs(k - i) + abs(g - j)) ;
                           }
                       }
                   }
                   TOT = max(TOT , step ) ;
                  }
              }
          }

            printf("%d\n",TOT) ;
        }
}
