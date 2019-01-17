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
        //   freopen("in.txt","r",stdin);
        //   freopen("out.txt","w",stdout);

        int N ;

        while (cin >> N)
        {
            vector<int> v (N) ;

            for (int i = 0 ; i < N ; i++)
                scanf("%d",&v[i]);

            sort(v.begin(),v.end()) ;
            int M ;
            scanf("%d",&M) ;
            int pon ;
            for (int i = 0 ; i < N ; i++)
            {
                if (v[i]> M / 2 )
                    break ;
                int p = upper_bound(v.begin(),v.end(),M - v[i]) - v.begin() - 1 ;
                if (v[p] == M - v[i] && p != i )
                    pon = i;
            }

            printf("Peter should buy books whose prices are %d and %d.\n\n",v[pon], M - v[pon]);

        }
}
