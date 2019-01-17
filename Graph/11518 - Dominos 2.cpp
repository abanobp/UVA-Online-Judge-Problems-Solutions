#include<bits/stdc++.h>
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
#define MOD  1000000007
#define inf  1000000007
#define BIG  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second

using namespace std;

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------
vector<vector<int> > adj ;
vector<bool>vis;

int num (int s )
{
    if (vis[s])
        return 0 ;
    vis[s] = 1 ;
    int sum = 1 ;
    for (int i = 0 ; i < adj[s].size() ; i++)
        sum += num(adj[s][i]) ;

    return sum ;
}

int main()
{
    // freopen("res.txt" , "w" , stdout) ;
     // freopen("in.txt" , "r" , stdin) ;

    int T ;
    scanf("%d" , &T) ;

    while(T--)
    {
        int N , M , L;
        scanf("%d%d%d" , &N , &M , &L) ;
        adj.clear();
        adj.resize(N + 3) ;
        vis.clear();
        vis.resize(N + 3 , 0 );
        int res = 0 ;
        while(M--)
        {
            int a , b ;
            scanf("%d%d" , &a , &b) ;
            adj[a].push_back(b);
        }

        while(L--)
        {
            int x ;
            scanf("%d" , &x) ;
            res += num(x) ;
        }

        printf("%d\n" , res) ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
