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
            int N ;
            scanf("%d",&N) ;
            vector <int> num (N);
            int sum = 0 ;
            for (int i = 0 ; i < N ; i++)
            {
                scanf("%d",&num[i]) ;
                int c = 0 ;
                for (int j = 0 ; j < i ; j++)
                {
                    if (num[j] <= num[i])
                        c++;
                }
                sum += c ;
            }

            printf("%d\n",sum) ;
        }
}
