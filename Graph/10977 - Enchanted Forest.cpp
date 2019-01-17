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

//--------------------- This code Written by " Abanob Ashraf " --------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it -----------------------------
//----------------------------------- START ------------------------------------------------------
bool grid [205][205] ;
int N , M , dis [205][205];

bool valid (int x , int y)
{
    if (x < 1 || x > N || y < 1 || y > M || grid [x][y] || dis [x][y] != INF)
        return 0 ;
    return 1 ;
}

void path ()
{
    queue<pair<int , int> > q ;
    memset(dis , INF , sizeof dis) ;
    q.push(MP(1,1)) ;
    dis [1][1] = 0 ;

    while(!q.empty())
    {
        int x = q.front().first , y = q.front().second ;
        q.pop() ;
        //cout << x << " " << y << "\n" ;

        if (valid(x + 1 , y))
            q.push(MP(x + 1 , y)) , dis [x + 1][y] = dis [x][y] + 1 ;

        if (valid(x , y + 1))
            q.push(MP(x , y + 1)) , dis [x ][y + 1 ] = dis [x][y] + 1 ;

        if (valid(x - 1 , y))
            q.push(MP(x - 1 , y)) , dis [x - 1][y] = dis [x][y] + 1 ;

        if (valid(x , y - 1))
            q.push(MP(x , y - 1)) , dis [x][y - 1] = dis [x][y] + 1 ;
    }
}

int cal (int x , int y , int a , int b)
{
    return ((x - a) * (x - a)) + ((y - b) * (y - b)) ;
}
int main()
{
           freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

       while (scanf("%d%d" , &N , &M) && N && M)
       {
           memset(grid , 0 , sizeof grid ) ;
           int K ;
           scanf("%d" , &K) ;

           while (K--)
           {
               int a , b ;
               scanf("%d%d" , &a , &b) ;
               grid [a][b] = 1 ;
           }


           scanf("%d" , &K) ;

           while (K--)
           {
               int a , b , c ;
               scanf("%d%d%d" , &a , &b , &c) ;

               for (int i = max(a - c , 1) ; i <= min(a + c , N) ; i++)
               {
                   for (int j = max(b - c , 1) ; j <= min(b + c , M) ; j++)
                   {
                       if (cal(a ,b , i , j) <= c * c )
                            grid [i][j] = 1 ;
                   }
               }
           }
           path() ;
           if (dis [N][M] == INF)
                cout << "Impossible.\n";
           else
                cout << dis [N][M]  << "\n" ;
       }
}

//------------------------------------- DONE --------------------------------------------------------
