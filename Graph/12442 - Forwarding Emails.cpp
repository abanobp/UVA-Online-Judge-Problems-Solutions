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
using namespace std;
vector<vector<int> > ad ;
bool vis [50009];
int memo [50009];
    int DEPTH (int p)
    {
      vis [ p ] = 1;
            int mx = 0;
          for (int i = 0 ; i < ad [ p ].size() ; i++ )
            if (!vis [ ad[p][i] ])
                mx = max(mx,DEPTH(ad [p][i]));
        vis [ p ] = 0;
      return memo [p] = 1 + mx;
    }

int main()
{
  // freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

        int T ;
        cin >> T ;

        for (int test = 1 ; test <= T ; test++ )
        {
            memset(memo,-1,sizeof memo);
            memset(vis,0,sizeof vis);
            int  N ;
            scanf("%d",&N ) ;
                ad.clear();
             ad.resize(N+5);

            for (int i = 0 ; i < N ; i++ )
            {
                int a , b ;
                scanf("%d%d",&a,&b);
                ad[a].push_back(b);
            }
            int mx = 0 , p = 1;
            for (int i = 1 ; i <= N ; i++ )
            {
                int g;
                if (memo [ i ] == -1)
                g = DEPTH (i) ;
                else
                   g = memo [i] ;
              //  cout<<g<<"  gg\n";
               if ( mx < g )
                    mx = g , p = i;
            }
            printf("Case %d: %d\n",test,p);
        }

}
