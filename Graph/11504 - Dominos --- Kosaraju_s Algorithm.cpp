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
vector<int>top;
bool vis [100005];
/*
Kosaraju's Algorithm
*/
void topological_sort(int v)
{
    //cout<<v<<"\n";
    if (vis [v])
        return;

    vis [ v ] =1;

    for (int i = 0 ; i < calls[v].size() ;i++)
        topological_sort(calls[v][i]);

    top.push_back(v);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int N , M , T ;
    cin >> T ;

    while (T-- &&scanf("%d%d",&N,&M) && N )
    {

        memset(vis, 0 , sizeof vis );
        top.clear();
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
            if (!vis [i] )
                topological_sort(i);
        }

        reverse(top.begin(),top.end());

        int circls = 0;
        memset(vis , 0 ,sizeof vis);
        for (int i = 0 ;i < N ; i++)
        {
            if ( !vis [ top [ i ] ] )
                topological_sort(top [ i ]) , circls++;
        }
        printf("%d\n",circls);
    }
}
