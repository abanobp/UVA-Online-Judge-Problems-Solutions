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
vector<int> v ;
int N ;

bool yes (int cap)
{
    int l = 0 ;
    for (int i = 0 ; i < N ; i++ )
    {
       if (v[i] - l > cap)
        return 0 ;
       if (cap == v[i]-l)
        cap--;
       l = v[i] ;
    }
    return 1 ;
}

int main()
{
      // freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

    int t ;

    scanf("%d",&t) ;

    for (int T = 1 ; T <= t ; T++){

           scanf("%d",&N) ;
        v.clear();
        v.resize(N) ;
        for (int i = 0 ; i < N ; i++)
            scanf("%d",&v[i]) ;

        int s = 1 , l = 10000005;

        int fac = 0 ;

        while (1)
        {
            int mid = (s+l) / 2 ;
            //cout << l - s << "\n" ;
            if (l - s <= 4)
            {
                for (int i = s ; i <= l ; i++){
                    if (yes(i))
                    {
                       fac = i ;
                        break ;
                    }
                }
                    break ;
            }

            if (!yes (mid))
                s = mid ;
            else
                l = mid ;
        }

      printf("Case %d: %d\n",T,fac) ;
    }
}
