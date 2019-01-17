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
#define INF  1000000007
using namespace std;
int man [10] ,tot ;
vector<bool> row (10,0) , LD(20,0) , RD (20 , 0 ) ;
void MIN (int col , int sum)
{
    // cout <<col << " " << sum << "\n" ;
    if (col == 9)
    {
       tot =  min(sum , tot) ;
       return ;
    }

    for (int i = 1 ; i <= 8 ; i++)
    {
        if (!row [i] && !LD [i - col + 8] && !RD[i + col])
        {
            row [i] = LD [i - col + 8] = RD[i + col] = 1 ;
            if (i != man [col])
            MIN(col + 1 ,sum + 1) ;
            else
            MIN (col + 1 , sum) ;
            row [i] = LD [i - col + 8] = RD[i + col] = 0 ;
        }
    }
}

int main()
{
         //    freopen("in.txt","r",stdin);
         //  freopen("out.txt","w",stdout);
        int T = 1 ;
        while (scanf("%d",&man[1]) != EOF)
        {
            tot = INF ;
            for (int i = 2 ; i <= 8 ; i++)
                scanf("%d",&man[i]) ;
            MIN(1,0) ;
            printf("Case %d: %d\n",T++,tot) ;
        }
}
