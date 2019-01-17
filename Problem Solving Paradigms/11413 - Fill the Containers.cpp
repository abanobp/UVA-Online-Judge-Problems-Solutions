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
int N , M;

bool yes (int cap)
{
    int con = 0  , last = cap;

    for (int i = 0 ; i < N ; i++ )
    {
        if (con == M || cap < v[i])
            return 0 ;
        if (last >= v[i])
            last-= v[i] ;
        else
            con++,last = cap , i-- ;
    }
    return 1 ;
}

int main()
{
      // freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

    while (cin >> N >> M )
    {
        v.clear();
        v.resize(N) ;
        for (int i = 0 ; i < N ; i++)
            scanf("%d",&v[i]) ;

        int s = 1 , l = 1000000000 ;

        int cap = 0 ;
        while (1)
        {
            int mid = (s+l) / 2 ;
            //cout << l - s << "\n" ;
            if (l - s <= 4)
            {
                for (int i = s ; i <= l ; i++){
                    if (yes(i))
                    {
                        cap = i ;
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

      printf("%d\n",cap);
    }
}
