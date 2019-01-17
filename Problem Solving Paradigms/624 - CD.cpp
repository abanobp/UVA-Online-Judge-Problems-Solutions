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
#define INF  10000000007
using namespace std;
int M ,N , yes , z ;
vector<int> mx ;
vector<int> C  ;

void rec (int p , int sum , int k)
{
    if (p == M){
      if (sum > yes)
        yes = sum , z  = k;
      else if (sum == yes )
        z = max(z,k) ;
     return ;
    }

    rec(p+1 , sum , k ) ;

   if (sum + C [p] <= N )
       rec (p+1 , sum + C [p] , k + 1 ) ;
}

bool print (int p , int sum , int k )
{
    if (p == M && sum == yes && k == z)
    {
        for (int i = 0 ; i < mx.size() ;i++)
            printf("%d ", mx [i]) ;
        printf("sum:%d\n",sum) ;
        return 1 ;
    }
    if (p == M)
      return 0 ;

     if (print(p + 1 , sum, k))
        return 1;
     mx.push_back(C[p] ) ;
     if (print(p+1 , C[p] + sum , k +1))
            return 1 ;
     else
        mx.pop_back() ;
     return 0 ;
}

int main()
{
         //    freopen("in.txt","r",stdin);
         //   freopen("out.txt","w",stdout);

         while (scanf("%d",&N) != EOF)
         {
                scanf("%d",&M) ;
                C.resize(M) ;
                mx.clear() ;
                for (int i = 0 ; i < M ; i++)
                    scanf("%d",&C [i]) ;
                yes = z = 0 ;

                rec (0 , 0 , 0) ;
                print(0 , 0 , 0) ;

         }
}
