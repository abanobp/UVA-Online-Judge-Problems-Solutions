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

int main()
{
       // freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
   int N ;

   while (scanf("%d",&N) && N)
   {
       bool f = 0 ;
       for (int i = 0 ; i < N ; i++)
       {
           int a ;
           scanf("%d",&a) ;

           if (f&&a)
            printf(" %d",a) ;
            else if (!f && a)
             printf("%d",a) , f = 1 ;
       }

       if (!f)
        printf("0\n") ;
       else
        printf("\n") ;
   }
}
