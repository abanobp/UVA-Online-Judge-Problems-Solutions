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

int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    int N , M , T = 1;
    while (scanf("%d%d",&N , &M)  && N && M)
    {

        int mimi = 10000000 ;
            for (int i = 0 ; i < N ; i++)
            {
                 int a ;
                scanf("%d",&a) ;
                mimi = min (mimi , a) ;
            }
            for (int i = 0 ; i < M ; i++){
                 int a ;
                scanf("%d",&a) ;
            }

       if (N <= M)
            printf("Case %d: 0\n",T++) ;
       else
       {
           printf("Case %d: %d %d\n",T++, N - M , mimi) ;
       }

    }
}
