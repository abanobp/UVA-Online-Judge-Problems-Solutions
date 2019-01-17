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

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------
int wall [4][5] ;
bool vis [10][10] ;
pair<int,int> par [10][10] ;

int dis (int x , int y , int a , int b)
{
    return (x - a) * (x - a) + (y - b) * (y - b) ;
}


bool cross (int x , int y , int a , int b)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        if (x == a && wall [i][0] == wall [i][2] && x == wall [i][0])
        {
            if (y >= wall [i][1] && y <= wall [i][3] && b >= wall [i][1] && b <= wall [i][3])
                return 0 ;
        }
        else if (y == b && wall [i][1] == wall [i][3] && y == wall [i][1])
        {
            if (x >= wall [i][0] && x <= wall [i][2] && a >= wall [i][0] && a <= wall [i][2])
                return 0 ;
        }
    }
    return 1 ;
}

bool valid (int x , int y)
{
    return (x < 1 || x > 6 || y < 1 || y > 6 ||  vis [x][y] )?0:1;
}

void path (int x , int y)
{
    queue<pair<int,int> > q ;
    memset(vis , 0 , sizeof vis);

    q.push(MP(x,y)) ;

    par [x][y].fr = -1 , par [x][y].sc = -1;
    vis [x][y] = 1 ;

    while (!q.empty())
    {
        int a  = q.front().fr , b = q.front().sc ;
        q.pop() ;

        if (valid(a - 1 , b) && cross(a - 1 , b - 1 , a - 1 , b))
            q.push(MP(a - 1 , b)) , vis [a - 1][b] = 1 , par [a - 1][b].fr = a , par [a - 1][b].sc = b ;

        if (valid(a + 1 , b) && cross(a , b - 1 , a , b))
            q.push(MP(a + 1 , b)) , vis [a + 1][b] = 1 , par [a + 1][b].fr = a , par [a + 1][b].sc = b ;

        if (valid(a , b + 1) && cross(a - 1 , b , a , b))
            q.push(MP(a , b + 1 )) , vis [a][b + 1] =  1 ,par [a][b + 1].fr = a , par [a][b + 1].sc = b ;

        if (valid(a , b - 1) && cross(a - 1 , b - 1 , a , b - 1))
            q.push(MP(a , b - 1 )) , vis [a][b - 1] = 1 , par [a][b - 1].fr = a , par [a][b - 1].sc = b;
    }
}

void how (int x , int y , int a , int b)
{
    if (x == a)
    {
        if (b < y)
            printf("E") ;
        else
            printf("W") ;
    }
    else
    {
        if (a < x)
            printf("S") ;
        else
            printf("N") ;
    }
}
void print (int x , int y)
{
    if (par[x][y].fr == -1 && par[x][y].sc == -1)
        return ;
    //cout << x << " " << y << "\n" ;
   print(par[x][y].fr ,par[x][y].sc) ;
   how(x , y , par[x][y].fr ,par[x][y].sc) ;
}

int main()
{
           //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);

    int s1 , e1 , s2 , e2 ;

    while (scanf("%d%d" , &e1 , &s1) && s1 && e1)
    {
        scanf("%d%d" , &e2 , &s2) ;

        for (int i = 0 ; i < 3 ; i++)
            scanf("%d%d%d%d" , &wall [i][1] , &wall[i][0] , &wall[i][3] , &wall [i][2]) ;

        path(s1 , e1) ;

        print(s2 , e2) ;

        printf("\n") ;
    }
}

//------------------------------------ DONE -----------------------------------------------------
