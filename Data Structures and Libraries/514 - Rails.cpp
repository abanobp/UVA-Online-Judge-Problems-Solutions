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

    while (scanf("%d", &N) && N)
    {
        int c, ix = 1;

        while (scanf("%d", &c) && c)
        {
            stack<int> sk ;
            bool f = 0 ;
            ix = 1 ;

            for (int i = 0 ; i < N ; i++)
            {
                if (i)
                    scanf("%d", &c) ;
                if (c >= ix)
                {
                    while(c != ix)
                        sk.push(ix) , ix++;
                    ix++;
                }
                else if (c == sk.top())
                    sk.pop();
                else
                    f = 1;
            }
            if (f)
                cout << "No\n" ;
            else
                cout << "Yes\n" ;
        }
        cout << "\n" ;
    }

}
//------------------------------------ DONE -----------------------------------------------------
