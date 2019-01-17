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
#define INF  100000007
using namespace std;

int main()
{
           freopen("in.txt","r",stdin);
              freopen("out.txt","w",stdout);

    int T ;
    scanf("%d" , &T) ;
    int a = 1 ;
    while (T--)
    {
       // cout << a++ << "  -------\n";
        int N , M ;
        scanf("%d%d", &N , &M) ;
        vector<vector<int> > adj (N + 4) ;
        while (M--)
        {
            int i , j ;
            scanf("%d%d" , &i , &j) ;
            if (a == 6)
            cout << i << " " << j << "\n" ;
            adj [i].push_back(j) ;
            adj [j].push_back(i) ;
        }
        int  an [3005] , res = 0 ;
        memset(an , 0 , sizeof an ) ;

        for (int i = 1 ; i <= N ; i++)
        {
            for (int j = 0 ; j < adj[i].size() ; j++)
            {
                int ch = adj [i][j] ;
                if (ch > i)
                    an [ch] = i ;
            }

            for (int j = 0 ; j < adj[i].size() ; j++)
            {
                int ch = adj [i][j] ;
                for (int k = 0 ; k < adj [ch].size() ; k++)
                {
                    int ch2 = adj [ch][k] ;
                    if (ch > i && an [ch2] == i)
                        res++;
                }
            }
        }

        printf("%d\n" , res / 2) ;
    }

}
