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
int area [5][5] ;
int dis (int x ,int y , int a ,int b)
 {
  return abs(x-a) + abs(y-b) ;
 }
int main()
{
         // freopen("in.txt","r",stdin);
         //freopen("out.txt","w",stdout);
     int N ;
     scanf("%d",&N) ;

     while (N--)
     {
        memset(area , 0 , sizeof area) ;

        int M , sum = 0;
        scanf("%d",&M) ;

        while (M--)
        {
            int x , y , c   ;
            scanf("%d%d%d",&x,&y,&c) ;
            sum += c ;
            area [x] [y] = c ;
        }

        bool yes [5][5] ;
        memset(yes , 0 , sizeof yes) ;
        vector<int> in (5) , mimi (5);
        int MIN = INF ;
        for (int i = 0 ; i < 25 ; i++)
        {
            in [0] = i ;
            for (int j = i+1 ; j < 25 ; j++)
            {
                in [1] = j ;
                for (int k = j+1 ; k < 25 ; k++)
                {
                    in [2] = k ;
                    for (int a = k+1 ; a < 25 ; a++)
                    {
                        in [3] = a ;
                        for (int b = a+1 ; b < 25 ;b++)
                        {
                            in [4] = b ;
                            int sum = 0 ;
                            for (int c = 0 ; c < 5 ;c++)
                            {
                                for (int d = 0 ; d < 5 ;d++)
                                {
                                    if (area[c][d])
                                    {
                                        int dis1 = dis (c,d,i/5,i%5) * area [c][d];
                                        int dis2 = dis (c,d,j/5,j%5) * area [c][d];
                                        int dis3 = dis (c,d,k/5,k%5) * area [c][d];
                                        int dis4 = dis (c,d,a/5,a%5) * area [c][d];
                                        int dis5 = dis (c,d,b/5,b%5) * area [c][d];
                                        sum += min(dis1,min(dis2,min(dis3,min(dis4,dis5)))) ;
                                    }
                                }
                            }
                            if (sum < MIN)
                            {
                                MIN = sum ;
                                for (int g = 0 ; g < 5 ; g++)
                                    mimi [g] = in [g] ;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0 ; i < 5 ; i++){
                if (i)
                    printf(" ") ;
            printf("%d" , mimi [i] );
        }
        printf("\n");
     }
}
