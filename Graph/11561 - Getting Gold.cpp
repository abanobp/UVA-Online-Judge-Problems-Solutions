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
int mov1 [] = {0 , -1 , 1 , 0} ;
int mov2 [] = {1 , 0 , 0 , -1} , N , M ;
bool vis [55][55] ;
char arr [55][55] ;

int gold (int x , int y)
{
    if (vis [x][y] || arr [x][y] == 'T' || arr [x][y] == '#')
        return 0 ;

    vis [x][y] = 1 ;

    int res = 0 ;
    if (arr [x][y] == 'G')
        res = 1 ;

    if (x && arr [x - 1] [y] == 'T')
        return res ;
    if (y && arr [x] [y - 1] == 'T')
        return res ;
    if (x < M - 1&& arr [x + 1] [y] == 'T')
        return res ;
    if (y < N - 1 && arr [x ] [y + 1] == 'T')
        return res ;

    for (int i = 0 ; i < 4 ; i++)
    {
        if (x + mov1 [i] >= 0 && x + mov1 [i] < M && y + mov2 [i] >= 0 && y + mov2 [i] < N )
            res += gold(x + mov1 [i] , y + mov2 [i]) ;
    }

    return res ;
}

int main()
{
     //  freopen("in.txt","r",stdin);
      //freopen("out.txt","w",stdout);


    while (cin >> N >> M)
    {
        int x , y ;
        memset(vis , 0 , sizeof vis) ;

        for (int i = 0 ; i < M ; i++)
         {
             for (int j = 0 ; j < N; j++)
             {
                 cin >> arr [i][j] ;
                if (arr [i][j] == 'P')
                    x = i , y = j ;
             }
         }

        printf("%d\n" , gold(x , y)) ;
    }
}
