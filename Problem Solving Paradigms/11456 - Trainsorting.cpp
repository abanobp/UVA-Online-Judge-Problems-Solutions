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
#include<limits.h>
#define INF  100000007
using namespace std;

int main()
{
          //   freopen("in.txt","r",stdin);
             //freopen("out.txt","w",stdout);
    int T ;
    scanf("%d" , &T) ;

    while (T--)
    {
            int N  ;
            scanf("%d" , &N) ;
            int d = N - 1;
            vector<int> arr (N*2) , TT (N * 2) ;

            for (int i = N ; i < N *2 ;i++)
                scanf("%d" , &arr [i]) , arr [d--] = arr [i];

            N *= 2;
            int sz = 0 ;
            if (N)
            TT [0] = arr[0] ;

            for (int i = 1 ; i < N ;i++)
            {
                if (arr [i] > TT [sz])
                    sz++ , TT[sz] = arr [i] ;
                else
                {
                    int in = lower_bound(TT.begin() ,TT.begin() + sz , arr[i]) - TT.begin() ;
                    TT [in] = arr [i] ;
                }
            }


            if (N)
                printf("%d\n" , sz + 1) ;
            else
                printf("0\n") ;
    }
}
