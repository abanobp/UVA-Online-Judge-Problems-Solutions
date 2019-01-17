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
#define INF  10000007
#define MOD  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define fr first
#define sc second
using namespace std;
vector<vector<int> > adj ;
vector<int> vis ;
vector<int> arr ;

int top (int in)
{
    if (vis [in] == 1)
        return 1 ;
    if (vis [in])
        return 0 ;

    vis [in] = 1 ;

    int ans = 0 ;

    for (int i = 0 ; i < adj[in].size() ; i++)
    {
        ans += top(adj[in][i]) ;
    }

    vis [in] = 2 ;
    arr.push_back(in) ;
    return ans ;
}

int main()
{
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);

    int N , M ;

    while (scanf("%d%d" , &N , &M) && (N || M))
    {
        arr.clear() ;
        vis.assign(N + 5 , 0) ;
        adj.clear() ;
        adj.resize(N + 5) ;

        for (int i = 0 ; i < M ; i++)
        {
            int a , b ;
            scanf("%d%d" , &a , &b) ;
            adj[b].push_back(a) ;
        }
        bool yes = 0 ;

        for (int i = 1 ; i <= N ; i++){
            if (top(i))
            {   yes = 1 ;
                break ;
            }
        }

        if (!yes)
        {
            for (int i = 0 ; i < N ; i++)
                printf("%d\n" , arr[i]) ;
        }
        else
                printf("IMPOSSIBLE\n") ;
    }
}
