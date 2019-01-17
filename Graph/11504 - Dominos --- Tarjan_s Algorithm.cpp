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
int low[100005] , num [100005] ,root [100005] , yes [100005] ,counter = 1 ;
bool vis1 [100005] , vis2 [100005];

void tarjan (int v)
{
   // cout<<v<<" v\n";
    low [v] = num [v] = counter++;
    vis2 [v] = 1;
    vis1 [v] = 1;

    stac.push_back(v);

    for (int i = 0 ; i<calls[v].size();i++)
    {
        int ch = calls [v][i] ;
        if (num [ch] == -1)
            tarjan(ch);

        if (vis1 [ ch ])
            low [v] = min(low[v] , low [ch] );
    }

    if (num [v] == low [v])
    {

        yes[v] = 1;
        int x = -1;
        while (1)
        {
            x = stac.back() , stac.pop_back() ,root [x] = v , vis1 [x] = 0 ;
            if (x == v)
                break;
        }

    }
}

int main()
{
       freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

    int N , M , T ;
    cin >> T ;

    while (T-- &&scanf("%d%d",&N,&M) && N )
    {

        memset(vis2, 0 , sizeof vis2 );
        memset(yes, 0 , sizeof yes );
        memset(num, -1 , sizeof num );
        memset(low, -1 , sizeof low );
        counter = 1;
        calls.clear();
        calls.resize(N+5) ;

        for (int i = 0 ; i < M ; i++ )
        {
            int a , b ;
            scanf("%d%d",&a,&b);
            calls [a].push_back(b);
        }

        for (int i = 1 ; i <= N ; i++)
        {
            if (!vis2 [i] )
                tarjan(i);
        }

        for (int i = 1 ;i <= N ; i++)
        {
            for (int j =0 ;j < calls[i].size() ; j++)
            {
                if (yes [root [calls[i][j]]])
                 //   cout<<"yes\n";
                if (root [calls[i][j]] != root [i])
                    yes [root [calls[i][j]]] = 0;
            }
        }

        int c = 0 ;

        for (int i = 1 ; i <=N ; i++)
            c+=yes[i];

        printf("%d\n",c);
    }
}
