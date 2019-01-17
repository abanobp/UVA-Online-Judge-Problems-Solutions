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
using namespace std;
vector<vector<int> > calls;
vector<int>stac;
int low[2005] , num [2005] ,counter = 1 , SCC = 0 , node = 0;
bool vis [2005];

void tarjan (int v)
{
   // cout<<v<<" v\n";
    low [v] = num [v] = counter++;
    vis [v] = 1;

    stac.push_back(v);

    for (int i = 0 ; i<calls[v].size();i++)
    {
        int ch = calls [v][i] ;
        if (num [ch] == -1)
            tarjan(ch);

        if (vis [ ch ])
            low [v] = min(low[v] , low [ch] );
    }

    if (num [v] == low [v])
    {
        SCC++;
        int x = -1;
        while (1)
        {
            node++;
            x = stac.back() , stac.pop_back() , vis [x] = 0 ;
            if (x == v)
                break;
        }
    }
}

int main()
{
       freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

    int N , M  ;

    while (scanf("%d%d",&N,&M) && N )
    {

        memset(vis, 0 , sizeof vis);
        memset(num, -1 , sizeof num );
        memset(low, -1 , sizeof low );
        counter = 1;
        SCC = 0 ,node = 0 ;
        calls.clear();
        calls.resize(N+5) ;

        for (int i = 0 ; i < M ; i++ )
        {
            int a , b ,c;
            scanf("%d%d%d",&a,&b,&c);
            calls [ a ].push_back( b );
            if (c == 2)
            calls [ b ].push_back( a );
        }

        tarjan(1);
         //   cout << SCC <<" " << node <<"\n";
        if (SCC == 1 && node == N )
            printf("1\n");
        else
            printf("0\n");
    }
}
