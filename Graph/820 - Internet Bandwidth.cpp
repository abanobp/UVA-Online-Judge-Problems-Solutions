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
#include<bitset>
#include<limits.h>
#define INF  -1
#define MOD  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second
using namespace std;

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------
int ban [105][105] , flow, S ;
vector<int> per ;

void  done (int v, int mimi)
{
    if (S == v)
    {
        flow = mimi ;
        return;
    }
    else if (per [v] != -1)
    {
        done(per [v] , min(mimi , ban [per[v]][v])) ;
        ban [per[v]][v] -= flow ;
        ban [v][per[v]] += flow ;
    }
}

int main()
{
    //  freopen("in.txt","r",stdin);
    //  freopen("out.txt","w",stdout);

    int N , tes = 1 ;

    while(scanf("%d" , &N) && N)
    {
        int T , C ;

        scanf("%d%d%d" , &S , &T , &C) ;

        memset(ban , 0 , sizeof ban ) ;

        while(C--)
        {
            int a , b , x ;
            scanf("%d%d%d" , &a , &b , &x) ;
            ban [a][b] += x ;
            ban [b][a] += x ;
        }

        int mxf = 0 ;

        while (1)
        {
            flow = 0 ;

            queue<int> q ;
            vector<bool> vis (N + 5 , 0) ;
            per.assign(N + 5 , -1) ;

            vis [S] = 1 ;
            q.push(S) ;

            while (!q.empty())
            {
                int vv = q.front() ; q.pop() ;

                if (vv == T)
                    break ;

                for (int i = 1 ; i <= N ; i++)
                {
                    if (ban[vv][i] > 0 && !vis [i])
                       q.push(i) , vis [i] = 1 , per [i] = vv ;
                }
            }

            done(T , INT_MAX) ;
            if (!flow)
                break ;
            mxf += flow ;
        }
        printf("Network %d\n" , tes++) ;
        printf("The bandwidth is %d.\n\n" , mxf) ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
