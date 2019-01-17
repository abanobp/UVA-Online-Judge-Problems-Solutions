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
vector<vector<int> > adj ;
int col [105] , N , MX = 0 ;
vector<int> B  , cop ;
void best (int p  )
{
   // cout << N << "\n" ;
    if (p == N + 1)
    {
        if (B.size() > MX)
        {
            MX = B.size();
            cop.clear();
            for (int i = 0 ; i < B.size() ; i++)
            cop .push_back(B[i]);
        }
        return ;
    }

    bool black = 1 ;

    for (int i = 0 ; i < adj[p].size() ; i++)
    {
        int ch = adj [p][i] ;
        if (col [ch])
        {
            black = 0 ;
            break;
        }
    }

    best(p+1);

    if (black)
    {
        B.push_back(p);
        col [p] = 1 ;
        best(p+1);
        col [p] = 0 ;
        B.pop_back();
    }
}

int main()
{
         freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);
    int T ;
    scanf("%d",&T) ;
    memset(col , 0 ,sizeof col) ;
    while (T--)
    {
        MX = 0 ;
        int  K ;
        adj.clear();
        cop.clear();
        scanf("%d%d",&N , &K) ;
        adj.resize(N+5) ;
        for (int i = 0 ; i < K ; i++)
        {
            int a ,b ;
            scanf("%d%d",&a,&b) ;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        best(1);

        printf("%d\n",cop.size());

        for (int i = 0 ; i < cop.size();i++)
            if (i)
                printf(" %d",cop[i]) ;
            else
                printf("%d",cop [i]) ;
        printf("\n");
    }
}
