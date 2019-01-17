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

   string a ;
   while(cin >> a)
   {
       bool h = 0 ;
       string res = "" ;
       deque<char> q ;
        a += ']';

       for (int i = 0 ; i < a.size() ; i++)
       {
           if (a[i] != '[' && a [i] != ']')
           {
               if (!h)
                q.push_back(a[i]) ;
               else
                res+=a[i];
           }
           else
           {
               for (int i = res.size() - 1 ; i>= 0 ;i--)
                q.push_front(res[i]) ;
               res = "" ;
           }
           if (a[i] == '[')
            h = 1 ;
           if (a [i] == ']')
            h = 0 ;
       }

       for (int i = 0 ; i < q.size() ; i++)
        cout << q[i] ;
       cout << "\n" ;
   }
}
//------------------------------------ DONE -----------------------------------------------------
