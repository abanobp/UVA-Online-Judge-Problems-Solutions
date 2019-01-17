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
//int moves [4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main ()
{
          // freopen("in.txt","r",stdin);
          // freopen("out.txt","w",stdout);

        int N  ;

        while (scanf("%d",&N) && N )
        {
            int j = 0 ,a = 0 , b = 0 , i = 0;
            while (N)
            {
                if (N & 1 )
                {
                    if (j%2 == 0)
                        a = a | (1 << i) ;
                    else
                        b = b | (1 << i) ;
                        j++;
                }

                N = N >> 1 ;
                i++;
            }

            cout << a << " " << b << "\n";
        }
}
