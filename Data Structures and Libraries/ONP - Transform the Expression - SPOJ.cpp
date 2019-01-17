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

    int T ;
    scanf("%d" , &T) ;

    while(T--)
    {
        string s ;
        cin >> s ;
        stack<string> res ;

        for (int i = 0 ; i < (int) s.size() ; i++)
        {
            if (s [i] == ')')
            {
                string r = res.top() ;
                res.pop() ;
                string op = res.top() ;
                res.pop() ;
                string l = res.top() ;
                res.pop() , res.pop();
                string tot = l + r + op ;
                res.push(tot) ;
            }
            else{
                string k = "" ;
                k += s[i] ;
                res.push(k) ;
            }
        }

        cout << res.top() << "\n" ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
