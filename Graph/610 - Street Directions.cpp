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
int num [1005], low [1005] ;
vector<int> adj[1005] ;
int counter  ;

void ArtPoint (int s , int pr)
{
    num[s] = low[s] = counter++;

    for (int i = 0 ; i < (int) adj[s].size() ; i++)
    {
        int ch = adj[s][i] ;


        if (num[ch] == -1)
        {
            ArtPoint(ch , s) ;

            if (low[ch] > num[s])
                printf("%d %d\n%d %d\n" , s , ch , ch , s) ;
            else
                printf("%d %d\n" , s , ch) ;

            low[s] = min(low[ch] , low[s]) ;
        }
        else if ( pr != ch && num[s] > num[ch])
        {
              printf("%d %d\n" , s , ch) ;
              low[s] = min(num[ch] , low[s]) ;
        }

    }
}



int main()
{
    // freopen("res.txt" , "w" , stdout) ;
    // freopen("in.txt" , "r" , stdin) ;

    int N , M , T = 1 ;

    while(scanf("%d%d" , &N , &M) && N && M )
    {
        for (int i = 1 ; i <= N ; i++)
            adj[i].clear() , num[i] = low[i] = -1;
        counter = 1 ;
        for (int i = 0 ; i < M; i++)
        {
            int a , b ;
            scanf("%d%d" , &a , &b) ;

            adj[a].push_back(b) ;
            adj[b].push_back(a) ;
        }

        printf("%d\n\n" , T++);
        for (int i = 1 ; i <= N ; i++)
            if (num[i] == -1)
                ArtPoint(i , 0) ;
        printf("#\n") ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
