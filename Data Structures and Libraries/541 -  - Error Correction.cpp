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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int N , gr [105][105] ;

    while (scanf("%d" , &N) && N )
    {
        int tot_r = 0 , ix_r , tot_c = 0 , ix_c ;

        for (int i = 0 ; i < N ; i++)
        {
            int sum = 0 ;
            for (int j = 0 ; j < N ; j++)
            {
                scanf("%d" , &gr[i][j]);
                sum += gr[i][j] ;
            }
            if (sum % 2)
                tot_r++ , ix_r = i + 1 ;
        }

        for (int i = 0 ; i < N ; i++)
        {
            int sum = 0 ;
            for (int j = 0 ; j < N ; j++)
                sum += gr [j][i] ;
            if (sum % 2)
                tot_c++ , ix_c = i + 1 ;
        }

        if (!tot_c && !tot_r)
            printf("OK\n") ;
        else if (tot_c == 1 && tot_r == 1)
            printf("Change bit (%d,%d)" , ix_r , ix_c) ;
        else
            printf("Corrupt\n") ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
