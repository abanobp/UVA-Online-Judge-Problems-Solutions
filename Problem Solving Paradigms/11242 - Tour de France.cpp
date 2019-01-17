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
#define INF  1000007
using namespace std;

int main()
{
         // freopen("in.txt","r",stdin);
         //freopen("out.txt","w",stdout);
         int N  , M ;

        while (scanf("%d",&N) && N )
        {
           scanf("%d",&M) ;
           vector<int> Front (N) , Back (M);

           for (int i = 0 ; i < N ; i++)
            scanf("%d",&Front[i]) ;

           for (int i = 0 ; i < M ; i++)
                scanf("%d",&Back[i]) ;

            vector<double> RAT ;

            for (int i = 0 ; i < N ; i++)
            {
                for (int j = 0 ; j < M ; j++)
                {
                    RAT.push_back( double (Back [j]) / Front [i]) ;
                }
            }

           sort(RAT.begin(),RAT.end()) ;
           double MX = 0 ;
           for (int i = 0 ; i < RAT.size() - 1 ; i++)
            MX = max(MX , RAT[i+1] / RAT [i]) ;

           printf("%.2lf\n",MX) ;
        }
}
