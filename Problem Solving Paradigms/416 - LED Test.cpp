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
bool burn [8] ;
bool check (string a , string b)
{
    for (int i = 0 ; i < 7 ; i++)
    {
        if ((a [i] == 'N' && b [i] == 'Y') || ( b [i] == 'Y' && burn [i] ) )
            return 0 ;
        else if (a[i] == 'Y' && b[i] == 'N')
            burn [i] = 1;
    }
    return 1 ;
}
int main()
{
           freopen("in.txt","r",stdin);
           freopen("out.txt","w",stdout);
    string num [10] ;
    num [0] = "YYYYYYN" , num [1] = "NYYNNNN" , num [2] = "YYNYYNY" ;
    num [3] = "YYYYNNY" , num [4] = "NYYNNYY" , num [5] = "YNYYNYY" ;
    num [6] = "YNYYYYY" , num [7] = "YYYNNNN" , num [8] = "YYYYYYY" ;
    num [9] = "YYYYNYY" ;
    int N ;
    while (scanf("%d",&N) && N )
    {
       vector<string> G (N) ;

        for (int i = 0 ; i < N ; i++)
            cin >> G [i] ;
        bool YES = 0 ;
        for (int i = 9 ; i >= N - 1 ; i--)
        {
                YES = 1 ;
                memset(burn , 0 , sizeof burn);

                for (int j = 0 ; j < N ; j++)
                {
                    if (!check(num [i - j], G [j]))
                    {
                        YES = 0 ;
                        break;
                    }
                }
            if (YES)
            {
               break ;
            }
        }

        if (YES)
            printf("MATCH\n");
        else
            printf("MISMATCH\n");
    }
}
