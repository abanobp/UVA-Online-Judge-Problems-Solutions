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
#define BIG  1000000007
#define ii pair<int,int>
#define iii pair<int,pair<int,int> >
#define MP(a,b) make_pair(a,b)
#define fr first
#define sc second

using namespace std;

//--------------------- This code Written by " Abanob Ashraf " ----------------------------------
//------------------ I Hope To Learn Or Understand Any Thing from it ----------------------------
//----------------------------------- START -----------------------------------------------------

int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
   int N ;

   while(scanf("%d" , &N) && N )
   {
       queue<int> q ;

       for (int i = 1 ; i <= N ;i++)
          q.push(i) ;

       printf("Discarded cards:") ;

       while(q.size() > 1 )
       {
         printf(" %d" ,  q.front()) ;
         if (q.size() > 2)
            printf(",") ;
         q.pop() ;
         int x = q.front() ;
         q.pop();
         q.push(x) ;
       }

       printf("\nRemaining card: %d\n",  q.front()) ;

   }
}
//------------------------------------ DONE -----------------------------------------------------
