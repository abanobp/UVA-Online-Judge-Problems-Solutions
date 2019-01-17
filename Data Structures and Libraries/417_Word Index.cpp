#include<bits/stdc++.h>
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
   //   freopen("in.txt","r",stdin);
  //    freopen("out.txt","w",stdout);


    deque<string> q ;
    q.push_back("") ;

    int ix = 0 ;
    map<string, int> mp ;

    while (ix <= 83681)
    {
        char st ;
        string a = q.front();
        if (a == "")
            st = 'a'  ;
        else
           st = a[a.size() - 1] + 1;

        for (char i = st ; i <= 'z' ; i++)
        {
            q.push_back(a + i) ;
        }

        q.pop_front() ;
        mp [a] = ix++ ;
    }

    string in ;

    while (cin >> in)
    {
        cout << mp [in] << "\n" ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
