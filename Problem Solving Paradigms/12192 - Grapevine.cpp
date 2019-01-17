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
      //  freopen("in.txt","r",stdin);
       //  freopen("out.txt","w",stdout);

    int N , M ;

    while (scanf("%d%d",&N,&M) && N)
    {
        vector<vector<int> > v (N , vector<int> (M)) ;

        for (int i = 0 ; i < N ; i++)
            for (int j = 0 ; j < M ; j++)
                scanf("%d",&v[i][j]) ;

        int q ;
        scanf("%d",&q) ;

        while (q--)
        {
            int l , u ;
            scanf("%d%d",&l,&u) ;
        int MX = 0 ;
        for (int i = 0 ; i < N ; i++)
        {
            if (v[i][M - 1] >= l ){
            int p = lower_bound(v[i].begin(),v[i].end() , l )  - v[i].begin();
            int side = 0 ;
            for (int j = 0 ; ((j + i < N ) && j + p < M ) ; j++)
            {
                int in = j + i , rn = j + p ;
                if (v[in][rn] <= u )
                {
                    side++;
                }
                else
                    break ;
            }
            MX = max(MX , side) ;
            }
        }

        printf("%d\n",MX) ;
        }
        printf("-\n") ;
    }
}
