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

int main()
{
     // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int H, W , N ;

    while(scanf("%d%d%d" , &H , &W , &N) && (H || W || N))
    {
        bool tot [505][505] = {0} ;

        for (int i = 0 ; i < N ; i++){
            int x1, x2 ,y1 , y2 ;

            scanf("%d%d%d%d" , &x1, &y1, &x2 , &y2);

            for (int i = min(x1 , x2) ; i <= max(x1,x2) ; i++)
                for (int j = min(y1,y2) ; j <= max(y1,y2) ; j++)
                    tot [i][j] = 1 ;
        }

        int res = 0 ;
        for (int i = 1 ; i <= H ; i++)
            for (int j = 1 ; j <= W ; j++)
                res += tot[i][j] ;
        res = (H * W) - res ;

        if (!res)
            printf("There is no empty spots.\n");
        else if (res == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n" , res) ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
