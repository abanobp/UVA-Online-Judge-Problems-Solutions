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
      // freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);
    int T ;
    cin >> T ;

    while (T--)
    {
        int N ;
        scanf("%d",&N) ;
        long long last = 0 , tot = 0 , c = 0;

        for (int i = 0 ; i < N ; i++)
        {
            long long a ;
            scanf("%I64d",&a) ;

            if (a <= tot)
                tot -= last , tot+= a , last = a ;
            else
                tot+= a , last = a , c++ ;
        }

       cout <<  c << endl;
    }
}
