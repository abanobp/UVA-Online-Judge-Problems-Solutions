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


    int N, M ;

    while(scanf("%d%d", &N , &M) && (N || M))
    {
        int coun = 0 ;
        char arr [50] ;
        set<string> s ;

        while (N--)
        {
            scanf("%s" , &arr) ;
            s.insert(arr) ;
        }

        while(M--)
        {
            scanf("%s" , &arr) ;
            if (s.find(arr) != s.end())
                coun++;
        }

        cout << coun << "\n" ;
    }
}
//------------------------------------ DONE -----------------------------------------------------
